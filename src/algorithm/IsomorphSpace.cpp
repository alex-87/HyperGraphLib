/*
 * MIT License
 * 
 * Copyright (c) 2015 Alexis LE GOADEC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "include/IsomorphSpace.hh"
#include <iostream>
#include <gecode/driver.hh>
#include <gecode/minimodel.hh>


IsomorphSpace::IsomorphSpace(
    const boost::shared_ptr<HypergrapheAbstrait>& h1,
    const boost::shared_ptr<HypergrapheAbstrait>& h2) :
    _edgeMapping (
        *this,
        h1->getHyperEdgeList().size(),
        0,
        h2->getHyperEdgeList().empty() ? 0 : h2->getHyperEdgeList().size() - 1 // Mapping identifier from 0 to n-1 (empty leads to 0)
    ),
    _vertexMapping(
        *this,
        h2->getHyperVertexList().size(),
        0,
        h1->getHyperVertexList().empty() ? 0 : h1->getHyperVertexList().size() - 1// Mapping identifier from 0 to n-1 (empty leads to 0)
    ),
    _ptrH1(h1),
    _ptrH2(h2) {

}


void
IsomorphSpace::postConstraints() {

    LibType::ListHyperVertex vertexH1(_ptrH1->getHyperVertexList());
    LibType::ListHyperEdge   edgeH1  (_ptrH1->getHyperEdgeList());
    LibType::ListHyperVertex vertexH2(_ptrH2->getHyperVertexList());
    LibType::ListHyperEdge   edgeH2  (_ptrH2->getHyperEdgeList());

    const unsigned int nbr_edge_h1   = edgeH1.size();
    const unsigned int nbr_vertex_h1 = vertexH1.size();
    const unsigned int nbr_edge_h2   = edgeH2.size();
    const unsigned int nbr_vertex_h2 = vertexH2.size();

    // Size checking to immediatly detect obvious non-isomorphism hypergraphs.
    if (nbr_edge_h1 != nbr_edge_h2 || nbr_vertex_h1 != nbr_vertex_h2) {
        this->fail();
        return;
    }

    // Adjency matrix for H1
    std::vector<std::vector<unsigned int>> matrixH1(nbr_edge_h1, std::vector<unsigned int>(nbr_vertex_h1, 0));

    // Adjency matrix (flat) for H2
    //
    // This matrix is flat on purpose because the type "Gecode::IntSharedArray" suits
    // perfectly well with "Gecode::element" constraint signature when a position is in
    // the form "w * y + x". (x, y) being the coordinates of the cell, and w the row length.
    Gecode::IntSharedArray flatMatrixH2(nbr_edge_h1 * nbr_vertex_h1);

    { // H1 hypergraph adjacency matrix
        unsigned int i = 0;
        for (boost::shared_ptr<HyperEdge>& e : edgeH1) {
            unsigned int j = 0;
            for (boost::shared_ptr<HyperVertex>& v : vertexH1) {
                matrixH1[i][j] = e->containVertex(v) ? 1 : 0;
                j++;
            }
            i++;
        }
    }
    { // H2 hypergraph adjacency matrix (flat)
        unsigned int p = 0;
        for (boost::shared_ptr<HyperEdge>& e : edgeH2) {
            unsigned int q = 0;
            for (boost::shared_ptr<HyperVertex>& v : vertexH2) {
                flatMatrixH2[q + nbr_vertex_h1 * p] = e->containVertex(v) ? 1 : 0;
                q++;
            }
            p++;
        }
    }

    // Hypergraph Edge Sizes
    std::vector<unsigned int> edgeSizeH1(nbr_edge_h1, 0);
    std::vector<unsigned int> edgeSizeH2(nbr_edge_h1, 0);

    // Hypergraph Vertex degrees
    std::vector<unsigned int> degH1(nbr_vertex_h1, 0);
    std::vector<unsigned int> degH2(nbr_vertex_h1, 0);

    // Counting edge size and vertex degrees
    // for H1
    for (unsigned int i = 0; i < nbr_edge_h1; i++) {
        for (unsigned int j = 0; j < nbr_vertex_h1; j++) {
            edgeSizeH1[i] += matrixH1[i][j];
            degH1[j]      += matrixH1[i][j];
        }
    }

    // Counting edge size and vertex degrees
    // for H2
    for (unsigned int p = 0; p < nbr_edge_h1; p++) {
        for (unsigned int q = 0; q < nbr_vertex_h1; q++) {
            edgeSizeH2[p] += flatMatrixH2[nbr_vertex_h1 * p + q];
            degH2[q]      += flatMatrixH2[nbr_vertex_h1 * p + q];
        }
    }

    // Seizing the opportunity to elagate the domain according to the size of the
    // edges. Basically, it builds the domain of each _edgeMapping[i] according to
    // the encoutered edges of same size: a mapping between two edges is possible
    // if these two edges are of the same size.
    for (unsigned int i = 0; i < nbr_edge_h1; i++) {
        std::vector<unsigned int> candidate;
        for (unsigned int p = 0; p < nbr_edge_h1; p++) {
            if (edgeSizeH1[i] == edgeSizeH2[p]) {
                // Same size ? Candidate for mapping !
                candidate.push_back(p);
            }
        }

        // If not any corresponding size has been found for edgeSizeH2[p]
        // during this iteration, then not any proper mapping will be feasible
        // at all, thus, returning.
        if (candidate.empty()) {
            this->fail();
            return;
        }

        // Domain constraint on the list of possible mapping destinations for _edgeMapping[i]
        // See https://www.gecode.dev/doc-latest/reference/group__TaskModelIntDomain.html#ga66976d758bbdbdfaf4eb2a8d59d3e4d0
        Gecode::dom(
            *this,
            _edgeMapping[i],
            // See https://www.gecode.dev/doc-latest/reference/classGecode_1_1IntSet.html#ac7917f4d0977fbbebb1a8386ef61a9af
            Gecode::IntSet(candidate.data(), candidate.size())
        );
    }

    // Seizing the opportunity to elagate the domain according to the degree of the
    // vertex. Basically, it builds the domain of each _vertexMapping[i] according to
    // the encoutered vertex of same degree: a mapping between two vertex is possible
    // if these two vertex are of the same degree.
    for (unsigned int j = 0; j < nbr_vertex_h1; j++) {
        std::vector<unsigned int> candidate;
        for (unsigned int q = 0; q < nbr_vertex_h1; q++) {
            if (degH1[j] == degH2[q]) {
                // Same degree ? Candidate for mapping !
                candidate.push_back(q);
            }
        }

        // If not any corresponding degree has been found for degH2[q]
        // during this iteration, then not any proper mapping will be feasible
        // at all, thus, returning.
        if (candidate.empty()) {
            this->fail();
            return;
        }

        // Domain constraint on the list of possible mapping destinations for  for _vertexMapping[j]
        // See https://www.gecode.dev/doc-latest/reference/group__TaskModelIntDomain.html#ga66976d758bbdbdfaf4eb2a8d59d3e4d0
        Gecode::dom(
            *this,
            _vertexMapping[j],
            // See https://www.gecode.dev/doc-latest/reference/classGecode_1_1IntSet.html#ac7917f4d0977fbbebb1a8386ef61a9af
            Gecode::IntSet(candidate.data(), candidate.size())
        );
    }

    // It enforces the following constraint:
    // flatMatrixH2[nbr_vertex_h1 * _edgeMapping[i] + _vertexMapping[j] ] == cell
    //
    // For the Element constraint specification,
    // see https://www.gecode.dev/doc-latest/reference/group__TaskModelIntElement.html#ga0e909a81b9429d91bf2cf8a8ec23dd11
    //
    // This contraints makes sure the matrix of H1 equals the MAPPED matrix of H2,
    // mapping occuring through the _edgeMapping[i] and _vertexMapping[j] maps.
    //
    // note: nbr_edge_h1 argument is the height limitation, to comply with Gecode's Element call.
    for (unsigned int i = 0; i < nbr_edge_h1; i++) {
        for (unsigned int j = 0; j < nbr_vertex_h1; j++) {
            Gecode::IntVar cell(*this, 0, 1);
            //
            Gecode::rel(*this, matrixH1[i][j], Gecode::IRT_EQ, cell);
            Gecode::element(
                *this,
                flatMatrixH2,
                _vertexMapping[j],
                nbr_vertex_h1,
                _edgeMapping[i],
                nbr_edge_h1,
                cell
            );
        }
    }

    // Enforces bijection
    // See https://www.gecode.dev/doc-latest/reference/group__TaskModelIntDistinct.html#ga4b178060150e551615bf637c0846f1eb
    Gecode::distinct(*this, _edgeMapping);
    Gecode::distinct(*this, _vertexMapping);

    // Exploration tree is built such that it starts exploring the smallest possible value
    // of the array cell having the smallest domain size.
    Gecode::branch(*this, _edgeMapping,  Gecode::INT_VAR_SIZE_MIN(), Gecode::INT_VAL_MIN());
    Gecode::branch(*this, _vertexMapping, Gecode::INT_VAR_SIZE_MIN(), Gecode::INT_VAL_MIN());
}

IsomorphSpace::IsomorphSpace(IsomorphSpace& p) :
    Gecode::Space(p),
    _ptrH1(p._ptrH1),
    _ptrH2(p._ptrH2) {

    _edgeMapping.update(*this, p._edgeMapping);
    _vertexMapping.update(*this, p._vertexMapping);
}

Gecode::Space*
IsomorphSpace::copy() {
    return new IsomorphSpace(*this);
}

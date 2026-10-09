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


#include "Hypergraph/model/Hypergraph.hh"
#include "Hypergraph/model/HyperVertex.hh"
#include "Hypergraph/model/HyperEdge.hh"

#include <stdexcept>

Hypergraph::Hypergraph()
    : AbstractHypergraph() {
}

std::shared_ptr<HyperVertex>
Hypergraph::addHyperVertex() {
	std::shared_ptr<HyperVertex> hyperVertex(new HyperVertex(_listHyperVertex.size()));
	_listHyperVertex.push_back(hyperVertex);
	_isIncidenceMatrixOutdated = true;
	return hyperVertex;
}

std::shared_ptr<HyperEdge>
Hypergraph::addHyperEdge() {
	std::shared_ptr<HyperEdge> hyperEdge(new HyperEdge(_listHyperEdge.size()));
	_listHyperEdge.push_back(hyperEdge);
	_isIncidenceMatrixOutdated = true;
	return hyperEdge;
}

void Hypergraph::link(const std::shared_ptr<HyperVertex>& hyperVertex, const std::shared_ptr<HyperEdge>& hyperEdge) {
	const unsigned int vertexId(hyperVertex->getIdentifier());
	const unsigned int edgeId(hyperEdge->getIdentifier());

	if (vertexId >= _listHyperVertex.size() || _listHyperVertex[vertexId] != hyperVertex)
		throw std::invalid_argument("Hypergraph::link: the hypervertex does not belong to this hypergraph");
	if (edgeId >= _listHyperEdge.size() || _listHyperEdge[edgeId] != hyperEdge)
		throw std::invalid_argument("Hypergraph::link: the hyperedge does not belong to this hypergraph");

	hyperVertex->addHyperEdge(hyperEdge);
	hyperEdge->addHyperVertex(hyperVertex);
	_isIncidenceMatrixOutdated = true;
}

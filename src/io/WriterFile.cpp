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


#include "Hypergraph/io/WriterFile.hh"

#include "Hypergraph/model/AbstractHypergraph.hh"
#include "Hypergraph/model/HyperVertex.hh"
#include "Hypergraph/model/HyperEdge.hh"

#include <tuple>
#include <ostream>
#include <string>

WriterFile::WriterFile(const std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph)
    : AbstractWriter(ptrAbstractHypergraph) {
}

void WriterFile::writeAdjacentMatrix(std::ostream& output) const {
	LibType::AdjacentMatrixContainerBool
	    adjacentMatrixBool(_ptrAbstractHypergraph->getAdjacentMatrix().getBoolAdjacentMatrix());

	std::tuple<unsigned int, unsigned int>
	    matrixDimension(_ptrAbstractHypergraph->getAdjacentMatrix().getMatrixDimension());

	unsigned int n(std::get<0>(matrixDimension)), m(std::get<1>(matrixDimension));

	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < m; j++) {
			output << adjacentMatrixBool(j, i) << " ";
		}
		output << " " << "\n";
	}
}

void WriterFile::writeHypergraph(std::ostream& output) const {
	writeHypergraphHyperVertex(output);
	writeHypergraphHyperEdge(output);

	LibType::ListHyperEdge listEdge(_ptrAbstractHypergraph->getHyperEdgeList());

	for (const auto& edge : listEdge) {
		LibType::ListHyperVertex vertexList(edge->getHyperVertexList());
		for (const auto& vertex : vertexList) {
			output << edge->getIdentifier() << " " << vertex->getIdentifier() << std::endl;
		}
	}
}

void WriterFile::writeHypergraphHyperVertex(std::ostream& output) const {
	LibType::ListHyperVertex listVertex(_ptrAbstractHypergraph->getHyperVertexList());

	for (const auto& vertex : listVertex) {
		output << vertex->getIdentifier() << " ";
	}

	output << "\n";
}

void WriterFile::writeHypergraphHyperEdge(std::ostream& output) const {
	LibType::ListHyperEdge listEdge(_ptrAbstractHypergraph->getHyperEdgeList());

	for (const auto& edge : listEdge) {
		output << edge->getIdentifier() << " ";
	}

	output << "\n";
}

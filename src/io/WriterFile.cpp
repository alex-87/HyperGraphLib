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

#include <ostream>
#include <string>

WriterFile::WriterFile(const std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph)
    : AbstractWriter(ptrAbstractHypergraph) {
}

void WriterFile::writeIncidenceMatrix(std::ostream& output) const {
	const IncidenceMatrix& incidenceMatrix(_ptrAbstractHypergraph->getIncidenceMatrix());

	for (unsigned int i = 0; i < incidenceMatrix.getEdgeCount(); i++) {
		for (unsigned int j = 0; j < incidenceMatrix.getVertexCount(); j++) {
			output << incidenceMatrix.isVertexInEdge(j, i) << " ";
		}
		output << " " << "\n";
	}
}

void WriterFile::writeHypergraph(std::ostream& output) const {
	writeHypergraphHyperVertex(output);
	writeHypergraphHyperEdge(output);

	for (const auto& edge : _ptrAbstractHypergraph->getHyperEdgeList()) {
		for (const auto& vertex : edge->getHyperVertexList()) {
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

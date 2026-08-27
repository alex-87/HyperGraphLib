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


#include "Hypergraph/algorithm/Dual.hh"
#include "Hypergraph/model/Hypergraph.hh"
#include "Hypergraph/model/HyperEdge.hh"
#include "Hypergraph/model/HyperVertex.hh"


Dual::Dual(const std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph)
    : _ptrDualHypergraph(new Hypergraph()) {
	_ptrAbstractHypergraph = ptrAbstractHypergraph;
}

ResultStructure
Dual::getResult() const {
	return _result;
}

void Dual::run() {
	const AdjacentMatrix& matrix(_ptrAbstractHypergraph->getAdjacentMatrix());

	// Each hypervertex of the original becomes a hyperedge of the dual, and vice versa.
	LibType::ListHyperVertex listVertex;
	LibType::ListHyperEdge listEdge;

	for (unsigned int i = 0; i < matrix.getVertexCount(); i++) {
		listEdge.push_back(_ptrDualHypergraph->addHyperEdge());
	}

	for (unsigned int i = 0; i < matrix.getEdgeCount(); i++) {
		listVertex.push_back(_ptrDualHypergraph->addHyperVertex());
	}

	for (const auto& itemVertex : listVertex) {
		for (const auto& itemEdge : listEdge) {
			if (matrix.isVertexInEdge(itemEdge->getIdentifier(), itemVertex->getIdentifier())) {
				_ptrDualHypergraph->link(itemVertex, itemEdge);
			}
		}
	}

	_result.setHypergraphResult(_ptrDualHypergraph);
}

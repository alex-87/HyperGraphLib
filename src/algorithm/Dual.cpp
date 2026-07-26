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
#include "Hypergraph/model/HyperFactory.hh"
#include "Hypergraph/model/Hypergraphe.hh"
#include "Hypergraph/model/HyperEdge.hh"
#include "Hypergraph/model/HyperVertex.hh"


Dual::Dual(const std::shared_ptr<HypergrapheAbstrait>& ptrAbstractHypergraph)
    : _ptrDualHypergraph(new Hypergraphe()) {
	_ptrAbstractHypergraph = ptrAbstractHypergraph;
}

RStructure
Dual::getResult() const {
	return _result;
}

void Dual::runAlgorithme() {
	LibType::IndexerHyperVertex indexVertex(_ptrAbstractHypergraph->getIndexHyperVertex());
	LibType::IndexerHyperEdge indexEdge(_ptrAbstractHypergraph->getIndexHyperEdge());

	LibType::ListHyperVertex listVertex;
	LibType::ListHyperEdge listEdge;

	HyperFactory::startSession(_ptrDualHypergraph);

	for (unsigned int i = 0; i < indexVertex.size(); i++) {
		listEdge.push_back(HyperFactory::newHyperEdge());
	}

	for (unsigned int i = 0; i < indexEdge.size(); i++) {
		listVertex.push_back(HyperFactory::newHyperVertex());
	}

	for (auto& itemVertex : listVertex) {
		for (auto& itemEdge : listEdge) {
			if (_ptrAbstractHypergraph->getAdjacentMatrix().isVertexInEdge(itemEdge->getIdentifier(), itemVertex->getIdentifier())) {
				HyperFactory::link(itemVertex, itemEdge);
			}
		}
	}

	for (auto& itemVertex : listVertex) {
		_ptrDualHypergraph->addHyperVertex(itemVertex);
	}

	for (auto& itemEdge : listEdge) {
		_ptrDualHypergraph->addHyperEdge(itemEdge);
	}

	HyperFactory::closeSession();

	_ptrDualHypergraph->flush();
	_result.setHypergrapheResult(_ptrDualHypergraph);
}

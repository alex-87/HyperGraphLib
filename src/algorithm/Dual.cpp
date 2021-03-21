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


#include "include/Dual.hh"
#include "../model/include/HyperFactory.hh"
#include "../model/include/Hypergraphe.hh"
#include "../model/include/HyperEdge.hh"
#include "../model/include/HyperVertex.hh"
#include <boost/foreach.hpp>


Dual::Dual(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) : _ptrDualHypergraphe( new Hypergraphe() ) {
	_ptrHypergrapheAbstrait = ptrHypergrapheAbstrait;
}

RStructure
Dual::getResult() const {
	return _result;
}

void
Dual::runAlgorithme() {

	LibType::IndexerHyperVertex indexVertex ( _ptrHypergrapheAbstrait->getIndexHyperVertex() );
	LibType::IndexerHyperEdge   indexEdge   ( _ptrHypergrapheAbstrait->getIndexHyperEdge()   );

	LibType::ListHyperVertex listVertex;
	LibType::ListHyperEdge   listEdge;

	HyperFactory::startSession(_ptrDualHypergraphe);
#pragma omp parallel sections
		{
#pragma omp section
		{
	for(unsigned int i=0; i<indexVertex.size(); i++) {
		listEdge.push_back( HyperFactory::newHyperEdge() );
	}
		}
#pragma omp section
		{
	for(unsigned int i=0; i<indexEdge.size(); i++) {
		listVertex.push_back( HyperFactory::newHyperVertex() );
	}
		}
		}
	BOOST_FOREACH(auto& itemVertex, listVertex) {
		BOOST_FOREACH(auto& itemEdge, listEdge) {
			if( _ptrHypergrapheAbstrait->getAdjacentMatrix().isVertexInEdge(itemEdge->getIdentifier(), itemVertex->getIdentifier())) {
				HyperFactory::link(itemVertex, itemEdge);
			}
		}
	}

#pragma omp parallel sections
		{
#pragma omp section
		{
	BOOST_FOREACH(auto& itemVertex, listVertex) {
		_ptrDualHypergraphe->addHyperVertex(itemVertex);
	}
		}
#pragma omp section
		{
	BOOST_FOREACH(auto& itemEdge, listEdge) {
		_ptrDualHypergraphe->addHyperEdge(itemEdge);
	}
		}
		}
	HyperFactory::closeSession();

	_ptrDualHypergraphe->flush();
	_result.setHypergrapheResult( _ptrDualHypergraphe );
}

Dual::~Dual() {
}

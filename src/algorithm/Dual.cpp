
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

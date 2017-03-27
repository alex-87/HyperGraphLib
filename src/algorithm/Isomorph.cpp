
#include "include/Isomorph.hh"
#include "include/IsomorphSpace.hh"
#include "../model/include/Hypergraphe.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"
#include <boost/graph/isomorphism.hpp>
#include <gecode/search.hh>

Isomorph::Isomorph(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
				   const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB)
				   : _ptrHypergrapheAbstraitA(ptrHypergrapheAbstraitA),
					 _ptrHypergrapheAbstraitB(ptrHypergrapheAbstraitB) {

}

void
Isomorph::runAlgorithme() {

	bool ret = false;

	if( _ptrHypergrapheAbstraitA->getHyperEdgeList().size() != _ptrHypergrapheAbstraitB->getHyperEdgeList().size() ||
		_ptrHypergrapheAbstraitA->getHyperVertexList().size() != _ptrHypergrapheAbstraitB->getHyperVertexList().size()
	  ) {
		_result.setBooleanResult( ret );
		return;
	}

	IsomorphSpace * is = new IsomorphSpace(_ptrHypergrapheAbstraitA, _ptrHypergrapheAbstraitB);
	is->postConstraints();

	Gecode::DFS<IsomorphSpace> ensembleSolution( is );

	if( ensembleSolution.next() ) ret = true;
	else ret = false;

	delete is;

	_result.setBooleanResult( ret );
}

RStructure
Isomorph::getResult() const {
	return _result;
}

Isomorph::~Isomorph() {
}


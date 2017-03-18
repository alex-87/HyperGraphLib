
#include "include/Isomorph.hh"
#include "include/IsomorphSpace.hh"
#include "../model/include/Hypergraphe.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"
#include <boost/graph/isomorphism.hpp>

Isomorph::Isomorph(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
				   const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB)
				   : _ptrHypergrapheAbstraitA(ptrHypergrapheAbstraitA),
					 _ptrHypergrapheAbstraitB(ptrHypergrapheAbstraitB) {

}

void
Isomorph::runAlgorithme() {

	bool ret = false;
	IsomorphSpace is(_ptrHypergrapheAbstraitA, _ptrHypergrapheAbstraitB);
	Gecode::DFS<IsomorphSpace> ensembleSolution( is );
	ensembleSolution.next();
	_result.setBooleanResult( ret );
}

RStructure
Isomorph::getResult() const {
	return _result;
}

Isomorph::~Isomorph() {
}


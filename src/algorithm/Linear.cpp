
#include "include/Linear.hh"
#include "include/Simple.hh"
#include <boost/foreach.hpp>

Linear::Linear(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) :
				_ptrHypergrapheAbstrait( ptrHypergrapheAbstrait ) {

}

void
Linear::runAlgorithme() {

	Simple a( _ptrHypergrapheAbstrait );
	a.runAlgorithme();

	if( !a.getResult().getBooleanResult() ) {
		_result.setBooleanResult(false);
		return;
	}

	_result.setBooleanResult(true);

	LibType::ListHyperVertex listVertex( _ptrHypergrapheAbstrait->getHyperVertexList() );
	LibType::ListHyperEdge   listEdge  ( _ptrHypergrapheAbstrait->getHyperEdgeList()   );

	for(unsigned int i=0; i<listEdge.size(); i++) {
		for(unsigned int j=i+1; j<listEdge.size(); j++) {
			unsigned int counter( 0 );
			LibType::ListHyperVertex subListVertex( listEdge.at(i)->getHyperVertexList() );
			for(unsigned int k=0; k<subListVertex.size(); k++) {
				if( listEdge.at(j)->containVertex(subListVertex.at(k)) )counter++;
			};
			if( counter > 1 ) {
				_result.setBooleanResult(false);
				break;
			}
		}
	}

}

RStructure
Linear::getResult() const {
	return _result;
}

Linear::~Linear() {

}

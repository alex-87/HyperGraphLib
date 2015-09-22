
#include "include/kRegular.hh"
#include <boost/foreach.hpp>

kRegular::kRegular(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) {
	_ptrHypergrapheAbstrait = ptrHypergrapheAbstrait;
}

void
kRegular::runAlgorithme() {

	_result.setBooleanResult(true);
	AdjacentMatrix matrix ( _ptrHypergrapheAbstrait->getAdjacentMatrix() );

	int compteur = -1;
	BOOST_FOREACH(const auto& e, _ptrHypergrapheAbstrait->getIndexHyperVertex() ) {
		if(compteur==-1) {
			compteur = matrix.getVertexDegree(e.first);
		} else {
			if( (int)matrix.getVertexDegree(e.first) != compteur ) {
				_result.setBooleanResult(false);
			};
		};
	}

	if( compteur==-1 ) _result.setBooleanResult(true);
}

RStructure
kRegular::getResult() const {
	return _result;
}

kRegular::~kRegular() {

}


#include "include/kUniform.hh"
#include <boost/foreach.hpp>


kUniform::kUniform(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait, const unsigned int& k) :
					_ptrHypergrapheAbstrait( ptrHypergrapheAbstrait ),
					_k( k ) {
}

RStructure
kUniform::getResult() const {
	return _result;
}

void
kUniform::runAlgorithme() {

	AdjacentMatrix matrix ( _ptrHypergrapheAbstrait->getAdjacentMatrix() );
	_result.setBooleanResult(true);

	BOOST_FOREACH(const auto& e, _ptrHypergrapheAbstrait->getIndexHyperEdge() ) {
		if( matrix.getEdgeSize(e.first) != _k ) {
			_result.setBooleanResult(false);
		};
	}
}

kUniform::~kUniform() {

}

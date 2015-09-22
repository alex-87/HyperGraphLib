
#include "include/Simple.hh"
#include <boost/foreach.hpp>

Simple::Simple(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergraphe) : _ptrHypergrapheAbstrait( ptrHypergraphe ) {

}

void
Simple::runAlgorithme() {

	_result.setBooleanResult(true);

	LibType::ListHyperVertex listVertex( _ptrHypergrapheAbstrait->getHyperVertexList() );
	LibType::ListHyperEdge   listEdge  ( _ptrHypergrapheAbstrait->getHyperEdgeList()   );

	unsigned int i( 0 ), j( 0 );
	for(i=0; i < listEdge.size(); i++) {
		for(j=i; j < listEdge.size(); j++) {
			if( i!=j && subsetVertexList(listEdge.at(i).getHyperVertexList(), listEdge.at(j).getHyperVertexList()) ) {
				_result.setBooleanResult(false);
				break;
			};
		};
	};

}

bool
Simple::subsetVertexList(const LibType::ListHyperVertex& vList1, const LibType::ListHyperVertex& vList2) const {

	bool ret1( true ), ret2( true );

#pragma omp parallel sections
	{

#pragma omp section
	{

	BOOST_FOREACH(const auto& v, vList1) {
		if( !contains(vList2, v))ret1 = false;
	}

	}

#pragma omp section
	{

	BOOST_FOREACH(const auto& v, vList2) {
		if( !contains(vList1, v))ret2 = false;
	}

	}

	}

	return (ret1 || ret2);
}

bool
Simple::contains(const LibType::ListHyperVertex& vList, const HyperVertex& v) const {

	bool ret( false );
	BOOST_FOREACH(const auto& w, vList) {
		if( w==v ) {
			ret = true;
			break;
		}
	}
	return ret;
}

RStructure
Simple::getResult() const {
	return _result;
}

Simple::~Simple() {

}

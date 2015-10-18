
#include "include/HyperVertex.hh"
#include "include/HyperEdge.hh"
#include <boost/foreach.hpp>


HyperVertex::HyperVertex(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergraphe, unsigned int& identifier) :
	_ptrHypergraphe( ptrHypergraphe ),
	_identifier( identifier ){
}

void
HyperVertex::addHyperEdge(boost::shared_ptr<HyperEdge>& hyperEdge) {
	if( !containEdge(hyperEdge) ) {
		_listHyperEdge.push_back( hyperEdge );
	};
}

const unsigned int
HyperVertex::getVertexDegree() const {
	return _listHyperEdge.size();
}

const unsigned int&
HyperVertex::getIdentifier() const {
	return _identifier;
}

bool
HyperVertex::operator ==(const boost::shared_ptr<HyperVertex>& hyperVertex) const {
	return _identifier==hyperVertex->getIdentifier();
}

bool
HyperVertex::operator<(const boost::shared_ptr<HyperVertex>& hyperVertex) const {
	return _identifier < hyperVertex->getIdentifier();
}

bool
HyperVertex::operator>(const boost::shared_ptr<HyperVertex>& hyperVertex) const {
	return _identifier > hyperVertex->getIdentifier();
}

bool
HyperVertex::containEdge(boost::shared_ptr<HyperEdge>& hyperEdge) const {

	int i = 0;
	const int N = _listHyperEdge.size();
	bool ret = false;

	#pragma omp for schedule(dynamic)
	for( i=0 ; i<N ; i++ ) {
		if( _listHyperEdge[i]==hyperEdge) {
			ret = true;
		};
	};

	return ret;
}

const LibType::ListHyperEdge&
HyperVertex::getHyperEdgeList() const {
	return _listHyperEdge;
}

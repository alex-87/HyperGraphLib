
#include "include/HyperEdge.hh"
#include "include/HyperVertex.hh"
#include <boost/foreach.hpp>


HyperEdge::HyperEdge(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergraphe, unsigned int& identifier) :
	_ptrHypergraphe( ptrHypergraphe ),
	_identifier( identifier ){

}

void
HyperEdge::addHyperVertex(HyperVertex& hyperVertex) {
	if( !containVertex(hyperVertex) ) {
		_listHyperVertex.push_back( hyperVertex );
	};
}

void
HyperEdge::setHyperVertexList(LibType::ListHyperVertex& listHyperVertex) {
	_listHyperVertex = listHyperVertex;
}

const unsigned int
HyperEdge::getEffectif() const {
	return _listHyperVertex.size();
}

const unsigned int&
HyperEdge::getIdentifier() const {
	return _identifier;
}

bool HyperEdge::operator==(const HyperEdge& hyperEdge) const {
	return _identifier==hyperEdge.getIdentifier();
}

bool
HyperEdge::operator<(const HyperEdge& hyperEdge) const {
	return _identifier < hyperEdge.getIdentifier();
}

bool
HyperEdge::operator>(const HyperEdge& hyperEdge) const {
	return _identifier > hyperEdge.getIdentifier();
}

bool HyperEdge::containVertex(HyperVertex& hyperVertex) const {

	int i = 0;
	const int N = _listHyperVertex.size();
	bool ret = false;

	#pragma omp parallel for schedule(dynamic)
	for( i=0 ; i<N ; i++ ) {
		if( _listHyperVertex[i]==hyperVertex) {
			ret = true;
		};
	};

	return ret;
}

LibType::ListHyperVertex&
HyperEdge::getHyperVertexList() {
	return _listHyperVertex;
}

const LibType::ListHyperVertex&
HyperEdge::getHyperVertexList() const {
	return _listHyperVertex;
}

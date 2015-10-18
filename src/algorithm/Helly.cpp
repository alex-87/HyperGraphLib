
#include "include/Helly.hh"
#include "../model/include/Hypergraphe.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"
#include <boost/foreach.hpp>

Helly::Helly(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) :
				_ptrHypergrapheAbstrait( ptrHypergrapheAbstrait ) {

}

void
Helly::runAlgorithme() {

	_result.setBooleanResult(true);

	BOOST_FOREACH(auto& x, _ptrHypergrapheAbstrait->getHyperVertexList()) {
		BOOST_FOREACH(auto& y, _ptrHypergrapheAbstrait->getHyperVertexList()) {

			LibType::ListHyperEdge X_xy( allContainXY(x, y) );
			BOOST_FOREACH(auto& v, _ptrHypergrapheAbstrait->getHyperVertexList()) {

				if( voisin(x, v) && voisin(y, v) ) {
					LibType::ListHyperEdge X_xv( allContainXY(x, v) );
					LibType::ListHyperEdge X_yv( allContainXY(y, v) );

					LibType::ListHyperEdge X;
					concatenate(X, X_xy);
					concatenate(X, X_xv);
					concatenate(X, X_yv);

					if( !nonEmptyIntersection(X) ) {
						_result.setBooleanResult(false);
						return;
					}
				}
			}

		}
	}
}

bool
Helly::voisin(boost::shared_ptr<HyperVertex>& v1, boost::shared_ptr<HyperVertex>& v2) {
	BOOST_FOREACH(auto& element1, v1->getHyperEdgeList() ) {
		BOOST_FOREACH(auto& element2, v2->getHyperEdgeList() ) {
			if( element1==element2 ) {
				return true;
			}
		}
	}
	return false;
}

void
Helly::concatenate(LibType::ListHyperEdge& dest, LibType::ListHyperEdge& src) {
	BOOST_FOREACH(auto& e, src) {
		dest.push_back(e);
	}
}

bool
Helly::nonEmptyIntersection(LibType::ListHyperEdge& ensemble) {
	for(unsigned int i=0; i<ensemble.size(); i++) {
		for(unsigned int j=i+1; j<ensemble.size(); j++) {
			if( !nonEmptyBetween(ensemble.at(i), ensemble.at(j)) )
				return false;
		}
	}
	return true;
}

bool
Helly::nonEmptyBetween(boost::shared_ptr<HyperEdge>& e1, boost::shared_ptr<HyperEdge>& e2) {
	BOOST_FOREACH(auto& a, e1->getHyperVertexList()) {
		BOOST_FOREACH(auto& b, e2->getHyperVertexList()) {
			if(a==b)return true;
		}
	}
	return false;
}

LibType::ListHyperEdge&
Helly::allContainXY(boost::shared_ptr<HyperVertex>& v1, boost::shared_ptr<HyperVertex>& v2) {
	LibType::ListHyperEdge * elist = new LibType::ListHyperEdge();
	BOOST_FOREACH(auto& e, _ptrHypergrapheAbstrait->getHyperEdgeList()) {
		if( e->containVertex(v1) && e->containVertex(v2) ) {
			elist->push_back(e);
		}
	}
	return *elist;
}

RStructure
Helly::getResult() const {
	return _result;
}

Helly::~Helly() {

}

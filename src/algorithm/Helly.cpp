/*
 * MIT License
 * 
 * Copyright (c) 2015 Alexis LE GOADEC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */


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

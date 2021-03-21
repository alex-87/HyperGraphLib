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

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
			if( i!=j && subsetVertexList(listEdge.at(i)->getHyperVertexList(), listEdge.at(j)->getHyperVertexList()) ) {
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
Simple::contains(const LibType::ListHyperVertex& vList, const boost::shared_ptr<HyperVertex>& v) const {

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

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

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

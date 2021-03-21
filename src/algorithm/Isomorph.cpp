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


#include "include/Isomorph.hh"
#include "include/IsomorphSpace.hh"
#include "../model/include/Hypergraphe.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"
#include <thread>
#include <boost/graph/isomorphism.hpp>
#include <gecode/search.hh>

Isomorph::Isomorph(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
				   const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB)
				   : _ptrHypergrapheAbstraitA(ptrHypergrapheAbstraitA),
					 _ptrHypergrapheAbstraitB(ptrHypergrapheAbstraitB) {

}

void
Isomorph::runAlgorithme() {

	bool ret = false;

	if( _ptrHypergrapheAbstraitA->getHyperEdgeList().size() != _ptrHypergrapheAbstraitB->getHyperEdgeList().size() ||
		_ptrHypergrapheAbstraitA->getHyperVertexList().size() != _ptrHypergrapheAbstraitB->getHyperVertexList().size()
	  ) {
		_result.setBooleanResult( ret );
		return;
	}

	IsomorphSpace * is = new IsomorphSpace(_ptrHypergrapheAbstraitA, _ptrHypergrapheAbstraitB);
	is->postConstraints();

	unsigned int nbrThreadsSupported( std::thread::hardware_concurrency() );

	if( nbrThreadsSupported <= 0 ) {
		nbrThreadsSupported = 1;
	};

	Gecode::Search::Options opt;
	opt.threads = nbrThreadsSupported;

	Gecode::DFS<IsomorphSpace> ensembleSolution(is, opt);

	if( ensembleSolution.next() ) ret = true;
	else ret = false;

	delete is;

	_result.setBooleanResult( ret );
}

RStructure
Isomorph::getResult() const {
	return _result;
}

Isomorph::~Isomorph() {
}


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

#include "Hypergraph/algorithm/Simple.hh"

Simple::Simple(std::shared_ptr<HypergrapheAbstrait>& ptrHypergraph) : _ptrAbstractHypergraph( ptrHypergraph ) {

}

void Simple::runAlgorithme() {
	_result.setBooleanResult(true);

	LibType::ListHyperVertex listVertex( _ptrAbstractHypergraph->getHyperVertexList() );
	LibType::ListHyperEdge   listEdge  ( _ptrAbstractHypergraph->getHyperEdgeList()   );

	for(unsigned int i=0; i < listEdge.size(); i++) {
		for(unsigned int j=i; j < listEdge.size(); j++) {
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
	for(const auto& v : vList1) {
		if( !contains(vList2, v))
			ret1 = false;
	}
	for(const auto& v : vList2) {
		if( !contains(vList1, v))
			ret2 = false;
	}
	return (ret1 || ret2);
}

bool Simple::contains(const LibType::ListHyperVertex& vList, const std::shared_ptr<HyperVertex>& v) const {
	for (const auto& w : vList) {
		if (v == w)
			return true;
	}
	return false;
}

RStructure
Simple::getResult() const {
	return _result;
}

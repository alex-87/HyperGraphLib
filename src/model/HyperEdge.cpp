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


#include "include/HyperEdge.hh"
#include "include/HyperVertex.hh"


HyperEdge::HyperEdge(const std::shared_ptr<HypergrapheAbstrait>& ptrHypergraphe, unsigned int& identifier) :
	_ptrHypergraphe( ptrHypergraphe ),
	_identifier( identifier ){

}

void
HyperEdge::addHyperVertex(std::shared_ptr<HyperVertex>& hyperVertex) {
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

bool HyperEdge::operator==(const std::shared_ptr<HyperEdge>& hyperEdge) const {
	return _identifier==hyperEdge->getIdentifier();
}

bool
HyperEdge::operator<(const std::shared_ptr<HyperEdge>& hyperEdge) const {
	return _identifier < hyperEdge->getIdentifier();
}

bool
HyperEdge::operator>(const std::shared_ptr<HyperEdge>& hyperEdge) const {
	return _identifier > hyperEdge->getIdentifier();
}

bool HyperEdge::containVertex(std::shared_ptr<HyperVertex>& hyperVertex) const {

	int i = 0;
	const int N = _listHyperVertex.size();

	for( i=0 ; i<N ; i++ ) {
		if( _listHyperVertex[i]==hyperVertex) {
			return true;
		};
	};

	return false;
}

LibType::ListHyperVertex&
HyperEdge::getHyperVertexList() {
	return _listHyperVertex;
}

const LibType::ListHyperVertex&
HyperEdge::getHyperVertexList() const {
	return _listHyperVertex;
}

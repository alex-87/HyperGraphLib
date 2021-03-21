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


#include "include/Hypergraphe.hh"
#include "include/HyperVertex.hh"
#include "include/HyperEdge.hh"
#include <boost/foreach.hpp>

#include <iostream>

Hypergraphe::Hypergraphe() : HypergrapheAbstrait() {

}

void
Hypergraphe::addHyperVertex(const boost::shared_ptr<HyperVertex>& hyperVertex) {
	_indexHyperVertex[hyperVertex] = hyperVertex->getIdentifier();
	_hyperVertexIndexer.insert( std::pair<unsigned int, boost::shared_ptr<HyperVertex> >(hyperVertex->getIdentifier(), hyperVertex));
	_listHyperVertex.push_back(hyperVertex);
}

void
Hypergraphe::addHyperEdge(const boost::shared_ptr<HyperEdge>& hyperEdge) {
	_indexHyperEdge[hyperEdge] = hyperEdge->getIdentifier();
	_hyperEdgeIndexer.insert( std::pair<unsigned int, boost::shared_ptr<HyperEdge> >(hyperEdge->getIdentifier() ,hyperEdge));
	_listHyperEdge.push_back(hyperEdge);
}

boost::shared_ptr<HyperVertex>&
Hypergraphe::getHyperVertexById(const unsigned int& id) {
	return _hyperVertexIndexer.at(id);

	BOOST_FOREACH(auto& e, _listHyperVertex) {
		if(e->getIdentifier() == id )return e;
	}
}

boost::shared_ptr<HyperEdge>&
Hypergraphe::getHyperEdgeById(const unsigned int& id) {
	return _hyperEdgeIndexer.at(id);

	BOOST_FOREACH(auto& e, _listHyperEdge) {
		if(e->getIdentifier() == id )return e;
	}
}

void
Hypergraphe::flush() {

	unsigned int m( _hyperVertexIndexer.size() );
	unsigned int n( _hyperEdgeIndexer.size() );

	_adjacentMatrix.resize(0, 0);
	_adjacentMatrix.resize(m, n);

#pragma omp parallel sections
		{

#pragma omp section
		{

	for(const auto& it : _hyperVertexIndexer ) {
				_adjacentMatrix.addHyperVertex( it.second );
	}
		}

#pragma omp section
		{

	for(const auto& it : _hyperEdgeIndexer ) {
				_adjacentMatrix.addHyperEdge( it.second );
	}
		}

		}
}

Hypergraphe::~Hypergraphe() {

}

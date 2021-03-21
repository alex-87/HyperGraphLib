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


#include "include/ReaderFile.hh"
#include "../model/include/HyperFactory.hh"
#include "../model/include/Hypergraphe.hh"

#include <boost/foreach.hpp>
#include <string>

ReaderFile::ReaderFile() : ReaderAbstrait( boost::shared_ptr<HypergrapheAbstrait>( new Hypergraphe() ) ) {

}

void
ReaderFile::readHypergraphe(std::istream& entree) {

	while( HyperFactory::isSession() );
	HyperFactory::startSession( _ptrHypergrapheAbstrait );

	readHypergrapheHyperVertex( entree );
	readHypergrapheHyperEdge( entree );

	unsigned int vertex( 0 );
	unsigned int edge( 0 );

	entree >> edge;
	entree >> vertex;

	while( entree ) {

		HyperFactory::link( hyperVertexById(vertex), hyperEdgeById(edge) );

		entree >> edge;
		entree >> vertex;

	};

	flush();

	HyperFactory::closeSession();
}

void
ReaderFile::readHypergrapheHyperVertex(std::istream& entree) {

	std::string s;
	std::getline(entree, s);

	std::stringstream k( s );

	unsigned int i( 0 );
	while( k >> i ) {
		boost::shared_ptr<HyperVertex> ptrHv( new HyperVertex(_ptrHypergrapheAbstrait, i) );
		_listHyperVertex.push_back( ptrHv );
	}
}

void
ReaderFile::readHypergrapheHyperEdge(std::istream& entree) {

	std::string s;
	std::getline(entree, s);

	std::stringstream k( s );

	unsigned int i( 0 );
	while( k >> i ) {
		boost::shared_ptr<HyperEdge> ptrHe( new HyperEdge(_ptrHypergrapheAbstrait, i) );
		_listHyperEdge.push_back( ptrHe );
	}
}

void
ReaderFile::flush() {

#pragma omp parallel sections
	{

#pragma omp section
	{
	BOOST_FOREACH(auto& vertex, _listHyperVertex) {
		_ptrHypergrapheAbstrait->addHyperVertex( vertex );
	}
	}

#pragma omp section
	{
	BOOST_FOREACH(auto& edge, _listHyperEdge) {
		_ptrHypergrapheAbstrait->addHyperEdge( edge );
	}
	}

	}

	_ptrHypergrapheAbstrait->flush();
}

boost::shared_ptr<HyperVertex>&
ReaderFile::hyperVertexById(unsigned int& id) {
	int r = 0;
	for(unsigned int i = 0; i < _listHyperVertex.size(); i++)
			if( id == _listHyperVertex.at(i)->getIdentifier() )
				r = i;
	return _listHyperVertex.at( r );
}

boost::shared_ptr<HyperEdge>&
ReaderFile::hyperEdgeById(unsigned int& id) {
	int r = 0;
	for(unsigned int i = 0; i < _listHyperEdge.size(); i++)
			if( id == _listHyperEdge.at(i)->getIdentifier() )
				r = i;
	return _listHyperEdge.at( r );
}

ReaderFile::~ReaderFile() {

}

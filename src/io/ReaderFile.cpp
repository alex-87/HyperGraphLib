
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
		_listHyperVertex.push_back( HyperVertex(_ptrHypergrapheAbstrait, i) );
	}
}

void
ReaderFile::readHypergrapheHyperEdge(std::istream& entree) {

	std::string s;
	std::getline(entree, s);

	std::stringstream k( s );

	unsigned int i( 0 );
	while( k >> i ) {
		_listHyperEdge.push_back( HyperEdge(_ptrHypergrapheAbstrait, i) );
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

HyperVertex&
ReaderFile::hyperVertexById(unsigned int& id) {
	BOOST_FOREACH(auto& vertex, _listHyperVertex) {
		if( id==vertex.getIdentifier() ) {
			return vertex;
		}
	}
}

HyperEdge&
ReaderFile::hyperEdgeById(unsigned int& id) {
	BOOST_FOREACH(auto& edge, _listHyperEdge) {
		if( id==edge.getIdentifier() ) {
			return edge;
		}
	}
}

ReaderFile::~ReaderFile() {

}


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

	_adjacentMatrix = AdjacentMatrix(0, 0);
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

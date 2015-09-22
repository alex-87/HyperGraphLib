
#include "include/AdjacentMatrix.hh"
#include "include/HyperVertex.hh"
#include "include/HyperEdge.hh"

#include <boost/foreach.hpp>

AdjacentMatrix::AdjacentMatrix() : AdjacentMatrix(0, 0) {

}

AdjacentMatrix::AdjacentMatrix(const unsigned int& m, const unsigned int& n) : _m( m ), _n( n ) {
	_adjacentMatrixBool.resize(boost::extents[m][n]);
}

void
AdjacentMatrix::resize(const unsigned int& m, const unsigned int& n) {
	_m = m;
	_n = n ;
	_adjacentMatrixBool.resize(boost::extents[m][n]);
}

void
AdjacentMatrix::addHyperVertex(const HyperVertex& hyperVertex) {

	const unsigned int id( hyperVertex.getIdentifier() );
	LibType::ListHyperEdge heList( hyperVertex.getHyperEdgeList() );

	BOOST_FOREACH( auto& he, heList ) {
		_adjacentMatrixBool[id][he.getIdentifier()] = true;
	};
}

void
AdjacentMatrix::addHyperEdge(const HyperEdge& hyperEdge) {

	const unsigned int id( hyperEdge.getIdentifier() );
	LibType::ListHyperVertex hvList( hyperEdge.getHyperVertexList() );

	BOOST_FOREACH( HyperVertex& hv, hvList ) {
		_adjacentMatrixBool[hv.getIdentifier()][id] = true;
	};
}

unsigned int AdjacentMatrix::getVertexDegree(const HyperVertex& hyperVertex) const {

	unsigned int sum( 0 );

#pragma omp for schedule( dynamic )
	for(unsigned int i=0; i < _m; i++) {
		sum += _adjacentMatrixBool[hyperVertex.getIdentifier()][i];
	};

	return sum;
}

unsigned int
AdjacentMatrix::getEdgeSize(const HyperEdge& hyperEdge) const {

	unsigned int sum( 0 );

#pragma omp for schedule( dynamic )
	for(unsigned int i=0; i < _n; i++) {
		sum += _adjacentMatrixBool[i][hyperEdge.getIdentifier()];
	};

	return sum;
}

boost::tuple<unsigned int, unsigned int>&
AdjacentMatrix::getMatrixDimension() {
	boost::tuple<unsigned int, unsigned int>
	*p = new boost::tuple<unsigned int, unsigned int>(_n, _m);
	return *p;
}

bool
AdjacentMatrix::isVertexInEdge(const int& vertexId, const int& edgeId) const {
	return _adjacentMatrixBool[vertexId][edgeId];
}

bool
AdjacentMatrix::isEdgeInVertex(const int& edgeId, const int& vertexId) const {
	return _adjacentMatrixBool[edgeId][vertexId];
}

LibType::AdjacentMatrixContainerBool&
AdjacentMatrix::getBoolAdjacentMatrix() {
	return _adjacentMatrixBool;
}
/*
void AdjacentMatrix::display() const {
	for(unsigned int i=0; i<_n; i++) {
		for(unsigned int j=0; j<_m; j++) {
			std::cout << _adjacentMatrixBool[j][i] << " ";
		}
		std::cout << " " << std::endl;
	}
}*/


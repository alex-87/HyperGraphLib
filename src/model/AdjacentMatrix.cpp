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
AdjacentMatrix::addHyperVertex(const boost::shared_ptr<HyperVertex>& hyperVertex) {

	const unsigned int id( hyperVertex->getIdentifier() );
	LibType::ListHyperEdge heList( hyperVertex->getHyperEdgeList() );

	for(unsigned int u=0; u < heList.size(); u++)_adjacentMatrixBool[id][heList[u]->getIdentifier()] = true;

}

void
AdjacentMatrix::addHyperEdge(const boost::shared_ptr<HyperEdge>& hyperEdge) {

	const unsigned int id( hyperEdge->getIdentifier() );
	LibType::ListHyperVertex hvList( hyperEdge->getHyperVertexList() );

	for(unsigned int u=0; u < hvList.size(); u++)_adjacentMatrixBool[hvList[u]->getIdentifier()][id] = true;

}

unsigned int AdjacentMatrix::getVertexDegree(const boost::shared_ptr<HyperVertex>& hyperVertex) const {

	unsigned int sum( 0 );

#pragma omp for schedule( dynamic )
	for(unsigned int i=0; i < _n; i++) {
		sum += _adjacentMatrixBool[hyperVertex->getIdentifier()][i];
	};

	return sum;
}

unsigned int
AdjacentMatrix::getEdgeSize(const boost::shared_ptr<HyperEdge>& hyperEdge) const {

	unsigned int sum( 0 );

#pragma omp for schedule( dynamic )
	for(unsigned int i=0; i < _m; i++) {
		sum += _adjacentMatrixBool[i][hyperEdge->getIdentifier()];
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

bool
AdjacentMatrix::isEdgeInVertex(const boost::shared_ptr<HyperEdge>& hEdge, const boost::shared_ptr<HyperVertex>& hVertex) const {
	return isEdgeInVertex(hEdge->getIdentifier(), hVertex->getIdentifier());
}

bool
AdjacentMatrix::isVertexInEdge(const boost::shared_ptr<HyperVertex>& hVertex, const boost::shared_ptr<HyperEdge>& hEdge) const {
	return isVertexInEdge(hVertex->getIdentifier(), hEdge->getIdentifier());
}

unsigned int
AdjacentMatrix::getCoRank() const {

	auto edgeSize = [&](const int& edgeId) {
		unsigned int sum( 0 );
		for(unsigned int i=0; i < _m; i++) {
			sum += _adjacentMatrixBool[i][edgeId];
		}
		return sum;
	};

	unsigned int corank( -1 );
	for(unsigned int k=0; k < _n; k++) {
		corank = (edgeSize(k) < corank ? edgeSize(k) : corank);
	}

	return corank;
}


unsigned int
AdjacentMatrix::getRank() const {

	auto edgeSize = [&](const int& edgeId) {
		unsigned int sum( 0 );
		for(unsigned int i=0; i < _m; i++) {
			sum += _adjacentMatrixBool[i][edgeId];
		}
		return sum;
	};

	unsigned int rank(0);
	for(unsigned int k=0; k < _n; k++) {
		rank = (edgeSize(k) > rank ? edgeSize(k) : rank);
	}

	return rank;
}

LibType::AdjacentMatrixContainerBool&
AdjacentMatrix::getBoolAdjacentMatrix() {
	return _adjacentMatrixBool;
}


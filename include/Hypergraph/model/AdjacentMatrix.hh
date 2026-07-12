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

/*
 * Model of the adjacency matrix associated with the hypergraph.
 *
 */

#ifndef MODEL_INCLUDE_ADJACENTMATRIX_HH_
#define MODEL_INCLUDE_ADJACENTMATRIX_HH_

#include "LibType.hh"
#include <tuple>

class HyperEdge;

class HyperVertex;


/**
 * Declaration of the adjacency matrix.
 */
class AdjacentMatrix {
  public:
	/**
	 * Default constructor.
	 */
	AdjacentMatrix();

	/**
	 * Constructor with an explicit size.
	 * @param x L'abscisse
	 * @param y the matrix ordinate.
	 */
	AdjacentMatrix(const unsigned int&, const unsigned int&);

	/**
	 * Resize the matrix.
	 * @param x L'abscisse
	 * @param y the matrix ordinate.
	 */
	void resize(const unsigned int&, const unsigned int&);

	/**
	 * Add a hyper-vertex to the matrix.
	 * @param hyperVertex the hyper-vertex to add.
	 */
	void addHyperVertex(const std::shared_ptr<HyperVertex>&);

	/**
	 * Add a hyper-edge to the matrix.
	 * @param hyperEdge the hyper-edge to add.
	 */
	void addHyperEdge(const std::shared_ptr<HyperEdge>&);

	/**
	 * Check whether the hyper-vertex is in the hyper-edge.
	 * @param the hyper-vertex to check.
	 * @param the hyper-edge in which to check for the hyper-vertex.
	 * @return true if the hyper-vertex is in the hyper-edge, false otherwise.
	 */
	bool isVertexInEdge(const std::shared_ptr<HyperVertex>&, const std::shared_ptr<HyperEdge>&) const;

	/**
	 * Check whether a hyper-edge is in a hyper-vertex's edge list.
	 * @param the hyper-edge to check.
	 * @param the hyper-vertex.
	 * @return true if the hyper-vertex has the hyper-edge in its list, false otherwise.
	 */
	bool isEdgeInVertex(const std::shared_ptr<HyperEdge>&, const std::shared_ptr<HyperVertex>&) const;

	/**
	 * Check whether hyper-vertex i is in hyper-edge j.
	 * @param the hyper-vertex identifier.
	 * @param the hyper-edge identifier.
	 * @return True si c'est le cas, False sinon.
	 */
	bool isVertexInEdge(const int&, const int&) const;

	/**
	 * Check whether hyper-edge i is in the list of hyper-vertex j.
	 * @param the hyper-edge identifier.
	 * @param the hyper-vertex identifier.
	 * @return True si c'est le cas, False sinon.
	 */
	bool isEdgeInVertex(const int&, const int&) const;

	/**
	 * Get the boolean adjacency matrix.
	 * @return the boolean adjacency matrix.
	 */
	LibType::AdjacentMatrixContainerBool& getBoolAdjacentMatrix();

	/**
	 * Get the integer adjacency matrix.
	 * @return the integer adjacency matrix.
	 */
	LibType::AdjacentMatrixContainerInt& getUIntAdjacentMatrix();

	/**
	 * Get the degree of a hyper-vertex.
	 * @param the hyper-vertex whose degree is wanted.
	 * @return a positive integer, the degree of the hyper-vertex.
	 */
	unsigned int getVertexDegree(const std::shared_ptr<HyperVertex>&) const;

	/**
	 * Get the cardinality of a hyper-edge.
	 * @param the hyper-edge whose cardinality is wanted.
	 * @return a positive integer, the number of hyper-vertices in the hyper-edge.
	 */
	unsigned int getEdgeSize(const std::shared_ptr<HyperEdge>&) const;

	/**
	 * Get the co-rank of the hypergraph.
	 * @return Un entie correspondant au co-rang.
	 */
	unsigned int getCoRank() const;

	/**
	 * Get the rank of the hypergraph.
	 * @return Un entie correspondant au rang.
	 */
	unsigned int getRank() const;

	/**
	 * Get the dimensions of the adjacency matrix.
	 * @return a tuple whose first number is the abscissa and second the ordinate.
	 */
	std::tuple<unsigned int, unsigned int>
	getMatrixDimension();

	/**
	 * Debug function printing the matrix to standard output - DO NOT USE.
	 */
	void display() const;

  protected:
	/**
	 * The abscissa.
	 */
	unsigned int _m;

	/**
	 * The ordinate.
	 */
	unsigned int _n;

	/**
	 * The boolean adjacency matrix data.
	 */
	LibType::AdjacentMatrixContainerBool _adjacentMatrixBool;

	/**
	 * The integer adjacency matrix data.
	 */
	LibType::AdjacentMatrixContainerInt _adjacentMatrixUInt;
};


#endif

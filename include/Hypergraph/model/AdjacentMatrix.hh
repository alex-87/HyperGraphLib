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

#ifndef MODEL_INCLUDE_ADJACENTMATRIX_HH_
#define MODEL_INCLUDE_ADJACENTMATRIX_HH_

#include "LibType.hh"
#include <tuple>

class HyperEdge;

class HyperVertex;


/**
 * @brief Adjacency matrix associated with a hypergraph.
 *
 * The matrix rows represent hypervertices and the columns represent
 * hyperedges; a `true` cell means the hypervertex belongs to the
 * hyperedge.
 */
class AdjacentMatrix {
  public:
	/**
	 * @brief Construct a new AdjacentMatrix object.
	 */
	AdjacentMatrix();

	/**
	 * @brief Construct a new AdjacentMatrix object with an explicit size.
	 * @param number of hypervertices (rows).
	 * @param number of hyperedges (columns).
	 */
	AdjacentMatrix(const unsigned int&, const unsigned int&);

	/**
	 * @brief Resize the matrix.
	 * @param number of hypervertices (rows).
	 * @param number of hyperedges (columns).
	 */
	void resize(const unsigned int&, const unsigned int&);

	/**
	 * @brief Add a hypervertex to the matrix.
	 * @param hypervertex to add.
	 */
	void addHyperVertex(const std::shared_ptr<HyperVertex>&);

	/**
	 * @brief Add a hyperedge to the matrix.
	 * @param hyperedge to add.
	 */
	void addHyperEdge(const std::shared_ptr<HyperEdge>&);

	/**
	 * @brief Check whether the hypervertex is in the hyperedge.
	 * @param hypervertex to check.
	 * @param hyperedge in which to check for the hypervertex.
	 * @return `true` if the hypervertex is in the hyperedge, `false` otherwise.
	 */
	bool isVertexInEdge(const std::shared_ptr<HyperVertex>&, const std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Check whether hypervertex i is in hyperedge j.
	 * @param hypervertex identifier.
	 * @param hyperedge identifier.
	 * @return `true` if the hypervertex is in the hyperedge, `false` otherwise.
	 */
	bool isVertexInEdge(const int&, const int&) const;

	/**
	 * @brief Get the boolean adjacency matrix.
	 * @return the boolean adjacency matrix.
	 */
	LibType::AdjacentMatrixContainerBool& getBoolAdjacentMatrix();

	/**
	 * @brief Get the degree of a hypervertex.
	 * @param hypervertex whose degree is wanted.
	 * @return a positive integer, the degree of the hypervertex.
	 */
	unsigned int getVertexDegree(const std::shared_ptr<HyperVertex>&) const;

	/**
	 * @brief Get the cardinality of a hyperedge.
	 * @param hyperedge whose cardinality is wanted.
	 * @return a positive integer, the number of hypervertices in the hyperedge.
	 */
	unsigned int getEdgeSize(const std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Get the co-rank of the hypergraph.
	 * @return the co-rank of the hypergraph.
	 */
	unsigned int getCoRank() const;

	/**
	 * @brief Get the rank of the hypergraph.
	 * @return the rank of the hypergraph.
	 */
	unsigned int getRank() const;

	/**
	 * @brief Get the dimensions of the adjacency matrix.
	 * @return a tuple whose first number is the abscissa and second the ordinate.
	 */
	std::tuple<unsigned int, unsigned int>
	getMatrixDimension();

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
};


#endif

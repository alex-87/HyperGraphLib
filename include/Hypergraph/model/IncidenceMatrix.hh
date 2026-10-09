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

#ifndef MODEL_INCLUDE_INCIDENCEMATRIX_HH_
#define MODEL_INCLUDE_INCIDENCEMATRIX_HH_

#include "LibType.hh"

class HyperEdge;

class HyperVertex;


/**
 * @brief Incidence matrix associated with a hypergraph.
 *
 * The matrix rows represent hypervertices and the columns represent
 * hyperedges; a `true` cell means the hypervertex belongs to the
 * hyperedge. The matrix is read-only: it is built from the hypergraph
 * elements and is kept up to date by the hypergraph itself.
 */
class IncidenceMatrix {
  public:
	/**
	 * @brief Construct an empty IncidenceMatrix object.
	 */
	IncidenceMatrix();

	/**
	 * @brief Construct the IncidenceMatrix of a set of hypervertices and hyperedges.
	 *
	 * Identifiers must be dense: every hypervertex identifier is lower than
	 * the number of hypervertices, and likewise for hyperedges.
	 * @param list of hypervertices (rows).
	 * @param list of hyperedges (columns).
	 */
	IncidenceMatrix(const LibType::ListHyperVertex&, const LibType::ListHyperEdge&);

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
	 * @return `true` if the hypervertex is in the hyperedge, `false` otherwise
	 * (including when an identifier is out of range).
	 */
	bool isVertexInEdge(unsigned int, unsigned int) const;

	/**
	 * @brief Get the boolean incidence matrix.
	 * @return the boolean incidence matrix.
	 */
	const LibType::IncidenceMatrixContainerBool& getBoolIncidenceMatrix() const;

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
	 * @return the co-rank of the hypergraph, 0 if it has no hyperedge.
	 */
	unsigned int getCoRank() const;

	/**
	 * @brief Get the rank of the hypergraph.
	 * @return the rank of the hypergraph, 0 if it has no hyperedge.
	 */
	unsigned int getRank() const;

	/**
	 * @brief Get the number of hypervertices (rows).
	 * @return the number of hypervertices.
	 */
	unsigned int getVertexCount() const;

	/**
	 * @brief Get the number of hyperedges (columns).
	 * @return the number of hyperedges.
	 */
	unsigned int getEdgeCount() const;

  protected:
	/**
	 * The boolean incidence matrix data.
	 */
	LibType::IncidenceMatrixContainerBool _incidenceMatrixBool;

	/**
	 * Degree of each hypervertex, indexed by identifier.
	 */
	std::vector<unsigned int> _vertexDegree;

	/**
	 * Cardinality of each hyperedge, indexed by identifier.
	 */
	std::vector<unsigned int> _edgeSize;
};


#endif // MODEL_INCLUDE_INCIDENCEMATRIX_HH_

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

#ifndef ABSTRACT_HYPERGRAPH_HH_
#define ABSTRACT_HYPERGRAPH_HH_

#include "IncidenceMatrix.hh"

/**
 * @brief Interface defining a hypergraph.
 *
 * A hypergraph is a generalisation of a graph in which a hyperedge can
 * link any number of hypervertices, rather than exactly two.
 *
 * Hypervertices and hyperedges are created by the hypergraph itself,
 * which assigns them dense identifiers (0, 1, 2, ...) in creation order.
 */
class AbstractHypergraph {
  public:
	/**
	 * @brief Construct a new AbstractHypergraph object.
	 */
	AbstractHypergraph();

	/**
	 * @brief Create a new hypervertex in the hypergraph.
	 * @return the new hypervertex.
	 */
	virtual std::shared_ptr<HyperVertex> addHyperVertex() = 0;

	/**
	 * @brief Create a new hyperedge in the hypergraph.
	 * @return the new hyperedge.
	 */
	virtual std::shared_ptr<HyperEdge> addHyperEdge() = 0;

	/**
	 * @brief Make the hypervertex belong to the hyperedge.
	 * @param hypervertex of this hypergraph.
	 * @param hyperedge of this hypergraph.
	 * @throw std::invalid_argument if an element does not belong to this hypergraph.
	 */
	virtual void link(const std::shared_ptr<HyperVertex>&, const std::shared_ptr<HyperEdge>&) = 0;

	/**
	 * @brief Get the incidence matrix of the hypergraph.
	 *
	 * The matrix is rebuilt on demand when the hypergraph changed since the
	 * previous call.
	 * @return the incidence matrix.
	 */
	const IncidenceMatrix& getIncidenceMatrix() const;

	/**
	 * @brief Get a hypervertex by its identifier.
	 * @param identifier of the hypervertex to get.
	 * @return the hypervertex.
	 * @throw std::out_of_range if the identifier is unknown.
	 */
	const std::shared_ptr<HyperVertex>& getHyperVertexById(unsigned int) const;

	/**
	 * @brief Get a hyperedge by its identifier.
	 * @param identifier of the hyperedge to get.
	 * @return the hyperedge.
	 * @throw std::out_of_range if the identifier is unknown.
	 */
	const std::shared_ptr<HyperEdge>& getHyperEdgeById(unsigned int) const;

	/**
	 * @brief Get the list of hypervertices of the hypergraph, ordered by identifier.
	 * @return the list of hypervertices of the hypergraph.
	 */
	const LibType::ListHyperVertex& getHyperVertexList() const;


	/**
	 * @brief Get the list of hyperedges of the hypergraph, ordered by identifier.
	 * @return the list of hyperedges of the hypergraph.
	 */
	const LibType::ListHyperEdge& getHyperEdgeList() const;

	/**
	 * @brief Check whether the hypervertex is contained in the hyperedge.
	 * @param hypervertex to check.
	 * @param hyperedge to check.
	 * @return `true` if the hypervertex belongs to the hyperedge, `false` otherwise.
	 */
	bool isHyperVertexInHyperEdge(const std::shared_ptr<HyperVertex>&, const std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Destructor.
	 */
	virtual ~AbstractHypergraph() = default;

  protected:
	/**
	 * List of hypervertices, indexed by identifier.
	 */
	LibType::ListHyperVertex _listHyperVertex;

	/**
	 * List of hyperedges, indexed by identifier.
	 */
	LibType::ListHyperEdge _listHyperEdge;

	/**
	 * The incidence matrix, a cache rebuilt from the hyperedges when outdated.
	 */
	mutable IncidenceMatrix _incidenceMatrix;

	/**
	 * Whether the hypergraph changed since the incidence matrix was built.
	 */
	mutable bool _isIncidenceMatrixOutdated;
};

#endif // ABSTRACT_HYPERGRAPH_HH_

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

#include "AdjacentMatrix.hh"

/**
 * @brief Interface defining a hypergraph.
 *
 * A hypergraph is a generalisation of a graph in which a hyperedge can
 * link any number of hypervertices, rather than exactly two.
 */
class AbstractHypergraph {
  public:
	/**
	 * @brief Construct a new AbstractHypergraph object.
	 */
	AbstractHypergraph();

	/**
	 * @brief Add a hypervertex to the hypergraph.
	 * @param hypervertex to add.
	 */
	virtual void addHyperVertex(const std::shared_ptr<HyperVertex>&) = 0;

	/**
	 * @brief Add a hyperedge to the hypergraph.
	 * @param hyperedge to add.
	 */
	virtual void addHyperEdge(const std::shared_ptr<HyperEdge>&) = 0;

	/**
	 * @brief Get the adjacency matrix of the hypergraph.
	 * @return the adjacency matrix.
	 */
	AdjacentMatrix& getAdjacentMatrix();

	/**
	 * @brief Get the hypervertex index table.
	 * @return the hypervertex index table.
	 */
	LibType::IndexerHyperVertex& getIndexHyperVertex();

	/**
	 * @brief Get the hyperedge index table.
	 * @return the hyperedge index table.
	 */
	LibType::IndexerHyperEdge& getIndexHyperEdge();

	/**
	 * @brief Get a hypervertex by its identifier.
	 * @param identifier of the hypervertex to get.
	 * @return the hypervertex. Undefined behaviour otherwise.
	 */
	virtual std::shared_ptr<HyperVertex>& getHyperVertexById(const unsigned int&) = 0;

	/**
	 * @brief Get a hyperedge by its identifier.
	 * @param identifier of the hyperedge to get.
	 * @return the hyperedge. Undefined behaviour otherwise.
	 */
	virtual std::shared_ptr<HyperEdge>& getHyperEdgeById(const unsigned int&) = 0;

	/**
	 * @brief Get the list of hypervertices of the hypergraph.
	 * @return the list of hypervertices of the hypergraph.
	 */
	LibType::ListHyperVertex& getHyperVertexList();


	/**
	 * @brief Get the list of hyperedges of the hypergraph.
	 * @return the list of hyperedges of the hypergraph.
	 */
	LibType::ListHyperEdge& getHyperEdgeList();

	/**
	 * @brief Check whether the hypervertex is contained in the hyperedge.
	 * @param hypervertex to check.
	 * @param hyperedge to check.
	 * @return `true` if the hypervertex belongs to the hyperedge, `false` otherwise.
	 */
	bool isHyperVertexInHyperEdge(std::shared_ptr<HyperVertex>&, std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Internal build of the hypergraph after construction.
	 */
	virtual void flush() = 0;

	/**
	 * @brief Destructor.
	 */
	virtual ~AbstractHypergraph() = default;

  protected:
	/**
	 * The hypervertex table (identifier, hypervertex).
	 */
	LibType::IndexerHyperVertex _indexHyperVertex;

	/**
	 * The hyperedge table (identifier, hyperedge).
	 */
	LibType::IndexerHyperEdge _indexHyperEdge;

	/**
	 * List of hypervertices.
	 */
	LibType::ListHyperVertex _listHyperVertex;

	/**
	 * List of hyperedges.
	 */
	LibType::ListHyperEdge _listHyperEdge;

	/**
	 * The hypervertex table (hypervertex, identifier).
	 */
	LibType::HyperVertexIndexer _hyperVertexIndexer;

	/**
	 * The hyperedge table (hyperedge, identifier).
	 */
	LibType::HyperEdgeIndexer _hyperEdgeIndexer;

	/**
	 * The adjacency matrix.
	 */
	AdjacentMatrix _adjacentMatrix;
};

#endif // ABSTRACT_HYPERGRAPH_HH_

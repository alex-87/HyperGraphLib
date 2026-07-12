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

/**
 * Declaration of the standard hypergraph interface.
 */

#ifndef HYPERGRAPHE_HH_
#define HYPERGRAPHE_HH_

#include "AdjacentMatrix.hh"

/**
 * Definition of the hypergraph interface.
 */
class HypergrapheAbstrait {
  public:
	/**
	 * Constructor.
	 */
	HypergrapheAbstrait();

	/**
	 * Add a hyper-vertex to the hypergraph.
	 * @param the hyper-vertex to add.
	 */
	virtual void addHyperVertex(const std::shared_ptr<HyperVertex>&) = 0;

	/**
	 * Add a hyper-edge to the hypergraph.
	 * @param the hyper-edge to add.
	 */
	virtual void addHyperEdge(const std::shared_ptr<HyperEdge>&) = 0;

	/**
	 * Get the adjacency matrix of the hypergraph.
	 * @return La matrice d'adjacence.
	 */
	AdjacentMatrix& getAdjacentMatrix();

	/**
	 * Get the hyper-vertex index table.
	 * @return the hyper-vertex index table.
	 */
	LibType::IndexerHyperVertex& getIndexHyperVertex();

	/**
	 * Get the hyper-edge index table.
	 * @return the hyper-edge index table.
	 */
	LibType::IndexerHyperEdge& getIndexHyperEdge();

	/**
	 * Get a hyper-vertex by its identifier.
	 * @return the hyper-vertex. Undefined behaviour otherwise.
	 */
	virtual std::shared_ptr<HyperVertex>& getHyperVertexById(const unsigned int&) = 0;

	/**
	 * Get a hyper-edge by its identifier.
	 * @return the hyper-edge. Undefined behaviour otherwise.
	 */
	virtual std::shared_ptr<HyperEdge>& getHyperEdgeById(const unsigned int&) = 0;

	/**
	 * Get the list of hyper-vertices of the hypergraph.
	 * @return the list of hyper-vertices of the hypergraph.
	 */
	LibType::ListHyperVertex& getHyperVertexList();


	/**
	 * Get the list of hyper-edges of the hypergraph.
	 * @return the list of hyper-edges of the hypergraph.
	 */
	LibType::ListHyperEdge& getHyperEdgeList();

	/**
	 * Check whether the hyper-vertex is contained in the hyper-edge
	 * @param hyper-vertex
	 * @param hyper-edge
	 * @return True or False
	 */
	bool isHyperVertexInHyperEdge(std::shared_ptr<HyperVertex>&, std::shared_ptr<HyperEdge>&) const;

	/**
	 * Internal build of the hypergraph after construction.
	 */
	virtual void flush() = 0;

	/**
	 * Virtual destructor.
	 */
	virtual ~HypergrapheAbstrait() = default;

  protected:
	/**
	 * The hyper-vertex table (identifier, hyper-vertex).
	 */
	LibType::IndexerHyperVertex _indexHyperVertex;

	/**
	 * The hyper-edge table (identifier, hyper-edge).
	 */
	LibType::IndexerHyperEdge _indexHyperEdge;

	/**
	 * List of hyper-vertices.
	 */
	LibType::ListHyperVertex _listHyperVertex;

	/**
	 * List of hyper-edges.
	 */
	LibType::ListHyperEdge _listHyperEdge;

	/**
	 * The hyper-vertex table (hyper-vertex, identifier).
	 */
	LibType::HyperVertexIndexer _hyperVertexIndexer;

	/**
	 * The hyper-edge table (hyper-edge, identifier).
	 */
	LibType::HyperEdgeIndexer _hyperEdgeIndexer;

	/**
	 * La matrice d'adjacence.
	 */
	AdjacentMatrix _adjacentMatrix;
};

#endif

/**
 * Definition of the Hypergraphe's Interface
 */

#ifndef HYPERGRAPHE_HH_
#define HYPERGRAPHE_HH_

#include "AdjacentMatrix.hh"

/**
 * Definition of the Hypergraphe's Interface
 */
class HypergrapheAbstrait {

public:

	/**
	 * Constructor
	 */
	HypergrapheAbstrait();

	/**
	 * Add hyper-vertex
	 * @param Hyper-vertex to add
	 */
	virtual void addHyperVertex(const boost::shared_ptr<HyperVertex>&) = 0;

	/**
	 * Add hyper-edge
	 * @param Hyper-edge to add
	 */
	virtual void addHyperEdge(const boost::shared_ptr<HyperEdge>&)     = 0;

	/**
	 * Get the the adjacency matrix
	 * @return The adjacency matrix
	 */
	AdjacentMatrix& getAdjacentMatrix();

	/**
	 * Get the hyper-vertex Id table
	 * @return The hyper-vertex Id table
	 */
	LibType::IndexerHyperVertex& getIndexHyperVertex();

	/**
	 * Get the hyper-edge Id table
	 * @return The hyper-edge Id table
	 */
	LibType::IndexerHyperEdge& getIndexHyperEdge();

	/**
	 * Get hyper-vertex by Id
	 * @param Hyper-vertex's Id
	 */
	virtual boost::shared_ptr<HyperVertex>& getHyperVertexById(const unsigned int&) = 0;

	/**
	 * Get hyper-edge by Id
	 * @param Hyper-edge's Id
	 */
	virtual boost::shared_ptr<HyperEdge>& getHyperEdgeById(const unsigned int&) = 0;

	/**
	 * Get the hyper-vertex's list
	 * @return The hyper-vertex's list
	 */
	LibType::ListHyperVertex& getHyperVertexList();


	/**
	 * Get the hyper-edge list
	 * @return The hyper-edge list
	 */
	LibType::ListHyperEdge&   getHyperEdgeList();

	/**
	 * Check whether the hyper-vertex is contained in the hyper-edge
	 * @param Hyper-vertex
	 * @param Hyper-edge
	 * @return True or False
	 */
	bool isHyperVertexInHyperEdge(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Build the adjacency matrix
	 */
	virtual void flush() = 0;

	/**
	 * Virtual destructor
	 */
	virtual ~HypergrapheAbstrait();

protected:

	/**
	 * Hyper-vertex Id table
	 */
	LibType::IndexerHyperVertex _indexHyperVertex;

	/**
	 * Hyper-edge Id table
	 */
	LibType::IndexerHyperEdge   _indexHyperEdge;

	/**
	 * Hyper-vertex's list
	 */
	LibType::ListHyperVertex    _listHyperVertex;

	/**
	 * Hyper-edge's list
	 */
	LibType::ListHyperEdge      _listHyperEdge;

	/**
	 * Hyper-vertex Id table
	 */
	LibType::HyperVertexIndexer _hyperVertexIndexer;

	/**
	 * Hyper-edge Id table
	 */
	LibType::HyperEdgeIndexer   _hyperEdgeIndexer;

	/**
	 * Adjacency matrix
	 */
	AdjacentMatrix 				_adjacentMatrix;

};

#endif

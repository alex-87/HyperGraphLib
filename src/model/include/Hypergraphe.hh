/**
 * Hypergraph object
 */
#ifndef MODEL_INCLUDE_HYPERGRAPHE_HH_
#define MODEL_INCLUDE_HYPERGRAPHE_HH_

#include "HypergrapheAbstrait.hh"

/**
 * Hypergraph object
 */
class Hypergraphe : public HypergrapheAbstrait {

public:

	/**
	 * Default constructor
	 */
	Hypergraphe();

	/**
	 * Add hyper-vertex
	 * @param Hyper-vertex to add
	 */
	void addHyperVertex(const boost::shared_ptr<HyperVertex>&);

	/**
	 * Add hyper-edge
	 * @param Hyper-edge to add
	 */
	void addHyperEdge(const boost::shared_ptr<HyperEdge>&);

	/**
	 * Get hyper-vertex by Id
	 * @param Hyper-vertex's Id
	 */
	boost::shared_ptr<HyperVertex>& getHyperVertexById(const unsigned int&);

	/**
	 * Get hyper-edge by Id
	 * @param Hyper-edge's Id
	 */
	boost::shared_ptr<HyperEdge>& getHyperEdgeById(const unsigned int&);

	/**
	 * Build the adjacency matrix
	 */
	void flush();

	/**
	 * Destructor
	 */
	~Hypergraphe();

protected:

};



#endif /* MODEL_INCLUDE_HYPERGRAPHE_HH_ */

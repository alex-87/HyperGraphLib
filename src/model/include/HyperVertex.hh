/**
 * Hyper-vertex object
 */

#ifndef HYPER_VERTEX_HH
#define HYPER_VERTEX_HH

#include <boost/shared_ptr.hpp>

#include "LibType.hh"
#include "HypergrapheAbstrait.hh"

/**
 * Hyper-vertex object
 */
class HyperVertex {

public:

	/**
	 * Constructor
	 * @param Hypergraph shared pointer
	 * @param Hyper-vertex Id
	 */
	HyperVertex(const boost::shared_ptr<HypergrapheAbstrait>&, unsigned int& identifier);

	/**
	 * Add hyper-edge
	 * @param Hyper-edge to add
	 */
	void addHyperEdge(boost::shared_ptr<HyperEdge>&);

	/**
	 * Get the hyper-vertex's degree
	 * @return The hyper-vertex's degree
	 */
	const unsigned int getVertexDegree() const;

	/**
	 * Check whether the hyper-vertex is contained into the specified hyper-edge
	 * @param Hyper-edge
	 * @return True or False
	 */
	bool containEdge(boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Get the hyper-vertex's Id
	 * @return The hyper-vertex's Id
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * Operator == overload. Based on the Id
	 */
	bool operator==(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Operator < overload. Based on the Id
	 */
	bool operator<(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Operator > overload. Based on the Id
	 */
	bool operator>(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Get the hyper-edges list containing the hyper-vertex
	 * @return The hyper-edges list containing the hyper-vertex
	 */
	const LibType::ListHyperEdge& getHyperEdgeList() const;


protected:

	/**
	 * HypergrapheAbstrait shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergraphe;

	/**
	 * Id
	 */
	unsigned int _identifier;

	/**
	 * Hyper-edges list containing the hyper-vertex
	 */
	LibType::ListHyperEdge
	_listHyperEdge;

};

#endif

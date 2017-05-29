/**
 * Hyper-edge object
 */
#ifndef _HYPEREDGE_HH
#define _HYPEREDGE_HH

#include <boost/shared_ptr.hpp>

#include "LibType.hh"
#include "HypergrapheAbstrait.hh"

/**
 * Hyper-edge object
 */
class HyperEdge {

public:

	/**
	 * Constructor
	 * @param HypergrapheAbstrait shared pointer
	 * @param Hyper-edge Id
	 */
	HyperEdge(const boost::shared_ptr<HypergrapheAbstrait>&, unsigned int& identifier);

	/**
	 * Add hyper-vertex
	 * @param Hyper-vertex to add
	 */
	void addHyperVertex(boost::shared_ptr<HyperVertex>&);

	/**
	 * Assignment of the list of hyper-vertex contained in the hyper-edge
	 * @param Hyper-vertex list.
	 */
	void setHyperVertexList(LibType::ListHyperVertex&);

	/**
	 * Get the hyper-vertex list containing the hyper-edge
	 * @return The hyper-vertex list containing the hyper-edge
	 */
	LibType::ListHyperVertex& getHyperVertexList();

	/**
	 * Get the count of contained hyper-vertex
	 * @return The count
	 */
	const unsigned int getEffectif() const;

	/**
	 * Get the ID
	 * @return The Id
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * Check whether the hyper-edge contains the specified hyper-vertex
	 * @param Hyper-vertex
	 * @return True or False
	 */
	bool containVertex(boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Operator == overload. Based on the Id
	 */
	bool operator==(const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Operator < overload. Based on the Id
	 */
	bool operator<(const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Operator > overload. Based on the Id
	 */
	bool operator>(const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Get the hyper-vertex list contained the hyper-edge
	 * @return The hyper-vertex list contained the hyper-edge
	 */
	const LibType::ListHyperVertex& getHyperVertexList() const;

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
	 * Hyper-vertex list
	 */
	LibType::ListHyperVertex
	_listHyperVertex;

};

#endif

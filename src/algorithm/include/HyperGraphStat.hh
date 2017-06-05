/**
 * Stats on hypergraph
 */

#ifndef ALGORITHM_INCLUDE_HPGSTAT
#define ALGORITHM_INCLUDE_HPGSTAT

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"


/**
 * Stats on hypergraph
 */
class HyperGraphStat : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor.
	 * @param Hypergraph shared pointer
	 */
	HyperGraphStat(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Unused here
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~HyperGraphStat();


public:

	/**
	 * Get hyper-edge count
	 */
	unsigned int getNbrHyperEdge() const;

	/**
	 * Get hyper-vertex count
	 */
	unsigned int getNbrHyperVertex() const;

	/**
	 * Get links count
	 */
	unsigned int getNbrLinks() const;

	/**
	 * Get hypergraph's rank
	 */
	unsigned int getRang() const;

	/**
	 * Get hypergraph's co-rank
	 */
	unsigned int getCoRang() const;

protected:

	/**
	 * Run the algorithm
	 */
	void runAlgorithme();

protected:

	/**
	 * Hypergraph shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Unused here
	 */
	RStructure _result;

	/**
	 * Hyper-edge count
	 */
	unsigned int _nhEdge;

	/**
	 * Hyper-vertex count
	 */
	unsigned int _nhVertex;

	/**
	 * Links count
	 */
	unsigned int _nhLink;

	/**
	 * Hypergraph's rank
	 */
	unsigned int _rang;

	/**
	 * Hypergraph's co-rank
	 */
	unsigned int _coRang;

};


#endif

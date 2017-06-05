/**
 * Isomorphism algorithm
 */

#ifndef ALGORITHM_INCLUDE_ISOMORPHISM_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISM_HH_

#include <boost/config.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>

#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"

/**
 * Isomorphism algorithm
 */
class Isomorph : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor.
	 * @param Hypergraph shared pointer
	 * @param Hypergraph shared pointer
	 */
	Isomorph(const boost::shared_ptr<HypergrapheAbstrait>&, const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Get result structure
	 * @Result structure
	 */
	RStructure getResult() const;

	/**
	 * Destructor
	 */
	~Isomorph();

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
	_ptrHypergrapheAbstraitA;

	/**
	 * Hypergraph shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstraitB;

	/**
	 * Result structure
	 */
	RStructure _result;

};



#endif

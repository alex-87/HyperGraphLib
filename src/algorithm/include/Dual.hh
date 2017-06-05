/**
 * Hypergraph dual algorithm
 */

#ifndef ALGORITHM_INCLUDE_DUAL_HH_
#define ALGORITHM_INCLUDE_DUAL_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"

/**
 * Hypergraph dual algorithm
 */
class Dual : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor.
	 * @param Hypergraph shareedpointer
	 */
	Dual(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Get result structure
	 * @return Result structure
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~Dual();

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
	 * Dual hypergraph shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrDualHypergraphe;

	/**
	 * Result structure
	 */
	RStructure _result;

};



#endif

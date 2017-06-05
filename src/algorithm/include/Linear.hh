/**
 * Linear algorithm
 */
#ifndef ALGORITHM_INCLUDE_LINEAR_HH_
#define ALGORITHM_INCLUDE_LINEAR_HH_

#include "../../model/include/AlgorithmeAbstrait.hh"

/**
 * Linear algorithm
 */
class Linear : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor
	 * @param Hypergraph shared pointer
	 */
	Linear(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * get result structure
	 * @return Result structure
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Linear();


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
	 * Result structure
	 */
	RStructure _result;

};



#endif /* ALGORITHM_INCLUDE_LINEAR_HH_ */

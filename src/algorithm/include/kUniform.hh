/**
 * K-uniforme algorithm
 */
#ifndef ALGORITHM_INCLUDE_KUNIFORM_HH_
#define ALGORITHM_INCLUDE_KUNIFORM_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"

/**
 * K-uniforme algorithm
 */
class kUniform : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor
	 * @param Hypergraph shared pointer
	 * @param K value
	 */
	kUniform(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait, const unsigned int&);

	/**
	 * Get result structure
	 * @return Result structure
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~kUniform();


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
	 * K value
	 */
	unsigned int _k;

	/**
	 * Result structure
	 */
	RStructure _result;

};



#endif /* ALGORITHM_INCLUDE_KUNIFORM_HH_ */

/**
 * Definition of the algorithm deciding the connectivity of a hypergraph.
 */
#ifndef ALGORITHM_INCLUDE_CONNECTED_HH_
#define ALGORITHM_INCLUDE_CONNECTED_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"

#include <boost/shared_ptr.hpp>
#include <stack>
#include <vector>

/**
 * Definition of the algorithm deciding the connectivity of a hypergraph.
 */
class Connected : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor.
	 * @param boost::shared_ptr<HypergrapheAbstrait> Hypergraph shared pointer
	 */
	Connected(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Get result structure
	 * @return Result structure
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~Connected();


protected:

	/**
	 * Run the algorithm
	 */
	void runAlgorithme();

	/**
	 * Vertical scan of a path of the matrix
	 * @param Visited
	 * @param To-visit stack
	 * @param Row Id
	 */
	void exploreVertical(std::vector<unsigned int>&, std::stack<unsigned int>&, unsigned int);

	/**
	 * Horizontal  scan of a path of the matrix
	 * @param Visited
	 * @param To-visit stack
	 * @param Column Id
	 */
	void exploreHorizontal(std::vector<unsigned int>&, std::stack<unsigned int>&, unsigned int);

	/**
	 * Check whether hyper-vertex already visited
	 * @param Visited
	 * @param Hyper-vertex Id to visit
	 * @return True or False
	 */
	bool isVertexVisited(std::vector<unsigned int>&, unsigned int) const;

	/**
	 * Check whether hyper-edge already visited
	 * @param Visited
	 * @param Hyper-edge Id to visit
	 * @return True or False
	 */
	bool isEdgeVisited(std::vector<unsigned int>&, unsigned int) const;


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


#endif /* ALGORITHM_INCLUDE_CONNECTED_HH_ */

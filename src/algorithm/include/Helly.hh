/**
 * Helly property algorithm
 */
#ifndef ALGORITHM_INCLUDE_HELLY_HH_
#define ALGORITHM_INCLUDE_HELLY_HH_

#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"

/**
 * Helly property algorithm
 */
class Helly : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor.
	 * @param Hypergraph shared pointer
	 */
	Helly(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Get result structure
	 * @return Result structure
	 */
	RStructure getResult() const;

	/**
	 * Déstructor.
	 */
	~Helly();

protected:

	/**
	 * Run the algorithm
	 */
	void runAlgorithme();

	/**
	 * Constructs the hyper-edge list containing the two hyper-vertices
	 * @param First hyper-vertex.
	 * @param Second hyper-vertex.
	 * @return List containing the two hyper-vertices
	 */
	LibType::ListHyperEdge& allContainXY(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperVertex>&);

	/**
	 * Checks whether the intersection between the elements in the list is not empty
	 * @param Hyper-edge list
	 * @return True or False
	 */
	bool nonEmptyIntersection(LibType::ListHyperEdge&);

	/**
	 * Checks whether the intersection between these two hyper-edges is not empty
	 * @param First hyper-edge
	 * @param Second hyper-edge
	 * @return True or False
	 */
	bool nonEmptyBetween(boost::shared_ptr<HyperEdge>&, boost::shared_ptr<HyperEdge>&);

	/**
	 * Checks whether the two hyper-vertexes are neighbors
	 * @param First hyper-vertex
	 * @param Second hyper-vertex
	 * @return True or False
	 */
	bool voisin(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperVertex>&);

	/**
	 * Concatenation of two lists of hyper-edges
	 * @param Destination
	 * @param Source to concatenate
	 */
	void concatenate(LibType::ListHyperEdge&, LibType::ListHyperEdge&);


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



#endif

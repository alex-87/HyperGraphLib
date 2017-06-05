/**
 * Simple algorithm
 */
#ifndef ALGORITHM_INCLUDE_SIMPLE_HH_
#define ALGORITHM_INCLUDE_SIMPLE_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"
#include "Linear.hh"

/**
 * Simple algorithm
 */
class Simple : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor
	 * @param Hypergraph shared pointer
	 */
	Simple(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * get result structure
	 * @return Result structure
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~Simple();


protected:

	friend class Linear;

	/**
	 * Run the algoithm
	 */
	void runAlgorithme();

	/**
	 * Verification of inclusion between hyper-vertex via vertex
	 * @param First list
	 * @param Seconde list
	 * @return True or False
	 */
	bool subsetVertexList(const LibType::ListHyperVertex&, const LibType::ListHyperVertex&) const;

	/**
	 * Checks if a hyper-vertex is contained in the list
	 * @param Hyper-vertex list
	 * @param The hyer-vertex.
	 * @return True or False
	 */
	bool contains(const LibType::ListHyperVertex&, const boost::shared_ptr<HyperVertex>&) const;


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



#endif /* ALGORITHM_INCLUDE_SIMPLE_HH_ */

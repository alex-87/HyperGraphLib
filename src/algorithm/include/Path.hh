/**
 * Search algorithm for paths from hyper-vertex e1 to hyper-vertex e2
 */

#ifndef ALGORITHM_INCLUDE_PATH_HH_
#define ALGORITHM_INCLUDE_PATH_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructurePath.hh"

/**
 * Search algorithm for paths from hyper-vertex e1 to hyper-vertex e2
 */
class Path : public AlgorithmeAbstrait {

public:

	/*
	 * Constructor.
	 * @param boost::shared_ptr<HypergrapheAbstrait> Hypergraph shared pointer
	 */
	Path(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Configure the vertices to use to list paths
	 */
	void setHyperVertex(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperVertex>&);

	/**
	 * Get result structure
	 * @return Result structure
	 */
	RStructure getResult() const;

	/**
	 * Get path result structure
	 * @return Path result structure
	 */
	RStructurePath getPathResult() const;

	/**
	 * Set the limit of paths. Default 0 if not set
	 */
	void setLimit(unsigned int);

	/**
	 * Get limit
	 */
	unsigned int getLimit() const;

	/**
	 * Destructor.
	 */
	~Path();


protected:

	/**
	 * Run the algorithm
	 */
	void runAlgorithme();

	/**
	 * Checks if HyperVertex is contained in the list
	 */
	bool vertexContained(LibType::ListHyperVertex&, boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Add the Hyper-vertex of an hyper-edge to the mentioned list
	 */
	void addVertexList(LibType::ListHyperVertex&, LibType::ListHyperVertex&, const boost::shared_ptr<HyperEdge>&) const;


	void buildPathToPathList(LibType::PathList&, LibType::ListHyperVertex&);

protected:

	/**
	 * Hypergraph shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Source hyper-vertex
	 */
	boost::shared_ptr<HyperVertex> _source;

	/**
	 * Destination hyper-vertex
	 */
	boost::shared_ptr<HyperVertex> _destination;

	/**
	 * Path result structure
	 */
	RStructurePath _result;

	/**
	 * Limit
	 */
	unsigned int _limite;
};


#endif /* SRC_ALGORITHM_INCLUDE_PATH_HH_ */

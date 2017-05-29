/*
 * Adjacency matrix object
 *
 */

#ifndef MODEL_INCLUDE_ADJACENTMATRIX_HH_
#define MODEL_INCLUDE_ADJACENTMATRIX_HH_

#include "LibType.hh"
#include <boost/tuple/tuple.hpp>

class HyperEdge;

class HyperVertex;


/**
 * Adjacency matrix object
 */
class AdjacentMatrix {

public:

	/**
	 * Constructor
	 */
	AdjacentMatrix();

	/**
	 * Constructor
	 * @param x The abscissa
	 * @param y The ordinate
	 */
	AdjacentMatrix(const unsigned int&, const unsigned int&);

	/**
	 * Matrix resize
	 * @param x The abscissa
	 * @param y The ordinate
	 */
	void resize(const unsigned int&, const unsigned int&);

	/**
	 * Add hyper-vertex
	 * @param HyperVertex Hyper-vertex to add
	 */
	void addHyperVertex(const boost::shared_ptr<HyperVertex>&);

	/**
	 * Add hyper-edge
	 * @param HyperEdge Hyper-edge to add
	 */
	void addHyperEdge(const boost::shared_ptr<HyperEdge>&);

	/**
	 * Check whether the hyper-vertex is contained into the specified hyper-edge
	 * @param Hyper-vertex
	 * @param Hyper-edge
	 * @return True or False
	 */
	bool isVertexInEdge(const boost::shared_ptr<HyperVertex>&, const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Check whether the hyper-edge contains the specified hyper-vertex
	 * @param Hyper-edge
	 * @param Hyper-vertex
	 * @return True or False
	 */
	bool isEdgeInVertex(const boost::shared_ptr<HyperEdge>&, const boost::shared_ptr<HyperVertex>&) const;


	/**
	 * Check whether the hyper-vertex is contained into the specified hyper-edge
	 * @param Hyper-vertex's Id
	 * @param Hyper-edge's Id
	 * @return True or False
	 */
	bool isVertexInEdge(const int&, const int&) const;

	/**
	 * Check whether the hyper-edge contains the specified hyper-vertex
	 * @param Hyper-edge's Id
	 * @param Hyper-vertex's Id
	 * @return True or False
	 */
	bool isEdgeInVertex(const int&, const int&) const;

	/**
	 * Get the boolean adajency matrix
	 * @return The boolean adajency matrix
	 */
	LibType::AdjacentMatrixContainerBool& getBoolAdjacentMatrix();

	/**
	 * Get the integer adajency matrix
	 * @return The integer adajency matrix
	 */
	LibType::AdjacentMatrixContainerInt& getUIntAdjacentMatrix();

	/**
	 * Get the hyper-vertex's degree
	 * @param Hyper-vertex
	 * @return The hyper-vertex's degree
	 */
	unsigned int getVertexDegree(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Get the hyper-edge degree
	 * @param Hyper-edge
	 * @return The hyper-edge degree
	 */
	unsigned int getEdgeSize(const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Get co-rank
	 * @return Co-rank
	 */
	unsigned int getCoRank() const;

	/**
	 * Get rank
	 * @return Rank
	 */
	unsigned int getRank() const;

	/**
	 * Get the matrix's size
	 * @return Tuple containing the abscissa and the ordinate
	 */
	boost::tuple<unsigned int, unsigned int>&
	getMatrixDimension();

	/**
	 * Displaying the matrix - DO NOT USE
	 */
	void display() const;

protected:

	/**
	 * Abscissa
	 */
	unsigned int _m;

	/**
	 * Ordinate
	 */
	unsigned int _n;

	/**
	 * Boolean matrix
	 */
	LibType::AdjacentMatrixContainerBool _adjacentMatrixBool;

	/**
	 * Integer matrix
	 */
	LibType::AdjacentMatrixContainerInt  _adjacentMatrixUInt;

};



#endif


/*
 * MIT License
 * 
 * Copyright (c) 2015 Alexis LE GOADEC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

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

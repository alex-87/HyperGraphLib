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
 * Definition of the algorithm checking the Helly property of the hypergraph.
 */
#ifndef ALGORITHM_INCLUDE_HELLY_HH_
#define ALGORITHM_INCLUDE_HELLY_HH_

#include "../model/AbstractAlgorithm.hh"
#include "../model/ResultStructure.hh"

/**
 * Algorithm checking the Helly property of the hypergraph.
 */
class Helly : public AbstractAlgorithm {
  public:
	/**
	 * Constructor.
	 * @param shared pointer to the hypergraph.
	 */
	Helly(const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * Get the result structure.
	 * @return the result structure.
	 */
	ResultStructure getResult() const;

	/**
	 * Destructor.
	 */
	~Helly() = default;

  protected:
	/**
	 * Run the algorithm.
	 */
	void run();

	/**
	 * Build the list of hyper-edges containing both hyper-vertices.
	 * @param the first hyper-vertex.
	 * @param the second hyper-vertex.
	 * @return the list of hyper-edges containing both hyper-vertices.
	 */
	LibType::ListHyperEdge allContainXY(std::shared_ptr<HyperVertex>&, std::shared_ptr<HyperVertex>&);

	/**
	 * Check whether the intersection of the list elements is non-empty.
	 * @param the list of hyper-edges.
	 * @return true if no empty intersections, false otherwise.
	 */
	bool nonEmptyIntersection(LibType::ListHyperEdge&);

	/**
	 * Check whether the intersection of these two hyper-edges is non-empty.
	 * @param the first hyper-edge.
	 * @param the second hyper-edge.
	 * @return true if non-empty intersection, false otherwise.
	 */
	bool nonEmptyBetween(std::shared_ptr<HyperEdge>&, std::shared_ptr<HyperEdge>&);

	/**
	 * Check whether the two hyper-vertices are neighbours.
	 * @param the first hyper-vertex.
	 * @param the second hyper-vertex.
	 * @return true if neighbours, false otherwise.
	 */
	bool areNeighbours(std::shared_ptr<HyperVertex>&, std::shared_ptr<HyperVertex>&);

	/**
	 * Concatenation of two hyper-edge lists.
	 * @param Destination.
	 * @param source to concatenate.
	 */
	void concatenate(LibType::ListHyperEdge&, LibType::ListHyperEdge&);


  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraph;

	/**
	 * Result structure.
	 */
	ResultStructure _result;
};


#endif

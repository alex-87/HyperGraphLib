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


#ifndef ALGORITHM_INCLUDE_DIAMETER_HH_
#define ALGORITHM_INCLUDE_DIAMETER_HH_

#include <limits>
#include <memory>
#include <vector>
#include "../model/AbstractHypergraph.hh"
#include "../model/AbstractAlgorithm.hh"

/**
 * @brief Implementation of the `DIAMETER` algorithm.
 *
 * The distance between two hypervertices is the minimum number of
 * hyperedges needed to go from one to the other, i.e. the length of a
 * shortest chain `v0 e1 v1 ... ek vk`. The diameter is the greatest
 * distance between two hypervertices.
 *
 * The diameter is finite only if the hypergraph is connected: the boolean
 * result of the algorithm tells whether it is. A hypergraph with at most
 * one hypervertex has a diameter of 0.
 */
class Diameter : public AbstractAlgorithm {
  public:
	/**
	 * Value returned by getDiameter() when the hypergraph is not connected.
	 */
	static constexpr unsigned int INFINITE_DIAMETER = std::numeric_limits<unsigned int>::max();

	/**
	 * @brief Construct a new Diameter object.
	 * @param hypergraph to which the algorithm is applied.
	 */
	Diameter(const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Get the result.
	 *
	 * The boolean result is `true` if the diameter is finite, that is if
	 * the hypergraph is connected.
	 * @return ResultStructure
	 */
	ResultStructure getResult() const;

	/**
	 * @brief Get the diameter of the hypergraph, once the algorithm ran.
	 * @return the diameter, or INFINITE_DIAMETER if the hypergraph is not connected.
	 */
	unsigned int getDiameter() const;

	/**
	 * @brief Run the algorithm.
	 */
	void run();

	/**
	 * @brief Destructor.
	 */
	~Diameter() = default;


  protected:
	/**
	 * @brief Compute the distances from a hyper-vertex to all the others.
	 * @param identifier of the source hyper-vertex.
	 * @param for each hyper-vertex, the identifiers of the hyper-edges containing it.
	 * @return the greatest distance from the source, or INFINITE_DIAMETER if
	 * a hypervertex cannot be reached.
	 */
	unsigned int eccentricity(unsigned int, const std::vector<std::vector<unsigned int>>&) const;


  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraph;

	/**
	 * The diameter.
	 */
	unsigned int _diameter;

	/**
	 * Result structure.
	 */
	ResultStructure _result;
};


#endif /* ALGORITHM_INCLUDE_DIAMETER_HH_ */

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


#ifndef ALGORITHM_INCLUDE_ISOMORPHISM_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISM_HH_

#include <memory>

#include "../model/AbstractHypergraph.hh"
#include "../model/AbstractAlgorithm.hh"

/**
 * @brief Implementation of the `ISOMORPH` algorithm.
 *
 * This algorithm determines whether two hypergraphs are **isomorphic**,
 * i.e. whether there exists a mapping between their hyper-vertices and
 * hyper-edges that preserves incidence.
 */
class Isomorph : public AbstractAlgorithm {
  public:
	/**
	 * @brief Construct a new Isomorph object.
	 * @param first hypergraph to compare.
	 * @param second hypergraph to compare.
	 */
	Isomorph(const std::shared_ptr<AbstractHypergraph>&, const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Get the result.
	 * @return ResultStructure
	 */
	ResultStructure getResult() const;

	/**
	 * @brief Destructor.
	 */
	~Isomorph() = default;

  protected:
	/**
	 * @brief Run the algorithm.
	 */
	void run();

  protected:
	/**
	 * Shared pointer to the first hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraphA;

	/**
	 * Shared pointer to the second hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraphB;

	/**
	 * Result structure.
	 */
	ResultStructure _result;
};


#endif

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

#ifndef ALGORITHM_INCLUDE_DUAL_HH_
#define ALGORITHM_INCLUDE_DUAL_HH_

#include <memory>
#include "../model/AbstractHypergraph.hh"
#include "../model/AbstractAlgorithm.hh"

/**
 * @brief Implementation of the `DUAL` algorithm.
 *
 * This algorithm builds the **dual hypergraph**: a hyper-vertex is
 * created for each hyper-edge of the original hypergraph, and a
 * hyper-edge is created for each hyper-vertex, preserving incidence.
 */
class Dual : public AbstractAlgorithm {
  public:
	/**
	 * @brief Construct a new Dual object.
	 * @param hypergraph to which the algorithm is applied.
	 */
	Dual(const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Get the result.
	 * @return ResultStructure
	 */
	ResultStructure getResult() const;

	/**
	 * @brief Destructor.
	 */
	~Dual() = default;

  protected:
	/**
	 * @brief Run the algorithm.
	 */
	void run();

  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraph;

	/**
	 * Shared pointer to the dual hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrDualHypergraph;

	/**
	 * Result structure.
	 */
	ResultStructure _result;
};


#endif

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

#ifndef ALGORITHM_INCLUDE_KUNIFORM_HH_
#define ALGORITHM_INCLUDE_KUNIFORM_HH_

#include <memory>
#include "../model/AbstractHypergraph.hh"
#include "../model/Hypergraph.hh"
#include "../model/HyperVertex.hh"
#include "../model/HyperEdge.hh"
#include "../model/AbstractAlgorithm.hh"
#include "../model/ResultStructure.hh"

/**
 * @brief Implementation of the `KUNIFORM` algorithm.
 *
 * This algorithm determines whether a hypergraph is **k-uniform**,
 * i.e. whether every hyper-edge has exactly `k` hyper-vertices.
 */
class kUniform : public AbstractAlgorithm {
  public:
	/**
	 * @brief Construct a new kUniform object.
	 * @param hypergraph to which the algorithm is applied.
	 * @param value of k.
	 */
	kUniform(std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph, const unsigned int&);

	/**
	 * @brief Get the result.
	 * @return ResultStructure
	 */
	ResultStructure getResult() const;

	/**
	 * @brief Destructor.
	 */
	~kUniform() = default;


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
	 * Value of k.
	 */
	unsigned int _k;

	/**
	 * Result structure.
	 */
	ResultStructure _result;
};


#endif /* ALGORITHM_INCLUDE_KUNIFORM_HH_ */

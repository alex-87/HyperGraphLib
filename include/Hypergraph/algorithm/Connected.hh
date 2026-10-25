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

#ifndef ALGORITHM_INCLUDE_CONNECTED_HH_
#define ALGORITHM_INCLUDE_CONNECTED_HH_

#include "../model/AbstractHypergraph.hh"
#include "../model/AbstractAlgorithm.hh"

#include <memory>
#include <stack>
#include <vector>

/**
 * @brief Implementation of the `CONNECTED` algorithm.
 * 
 * This algorithm determines if a hypergraph is **Connected**. It
 * determines whether a path of alternating hypervertices and hyperedges
 * exists between any given pair of nodes in a hypergraph.
 */
class Connected : public AbstractAlgorithm {

  public:

	/**
	 * @brief Construct a new Connected object.
	 * @param hypergraph to which the algorithm is applied.
	 */
	Connected(std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Get the result.
	 * @return ResultStructure
	 */
	ResultStructure getResult() const;

	/**
	 * @brief Destructor.
	 */
	~Connected() = default;


  protected:
	/**
	 * @brief Run the algorithm.
	 */
	void run();

	/**
	 * @brief Explore vertically through the incidence matrix.
	 * @param incidence matrix of the hypergraph.
	 * @param visited hyperedges, indexed by identifier.
	 * @param stack of hyperedges to visit.
	 * @param row identifier.
	 */
	void exploreVertical(const IncidenceMatrix&, const std::vector<bool>&, std::stack<unsigned int>&, unsigned int) const;

	/**
	 * @brief Explore horizontally through the incidence matrix.
	 * @param incidence matrix of the hypergraph.
	 * @param visited hypervertices, indexed by identifier.
	 * @param stack of hypervertices to visit.
	 * @param column identifier.
	 */
	void exploreHorizontal(const IncidenceMatrix&, const std::vector<bool>&, std::stack<unsigned int>&, unsigned int) const;


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


#endif /* ALGORITHM_INCLUDE_CONNECTED_HH_ */

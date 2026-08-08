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
	 * @brief Explore vertically through the adjacency matrix.
	 * @param vector of visited elements.
	 * @param stack of vertices to visit.
	 * @param row identifier.
	 */
	void exploreVertical(std::vector<unsigned int>&, std::stack<unsigned int>&, unsigned int);

	/**
	 * @brief Explore horizontally through the adjacency matrix.
	 * @param vector of visited elements.
	 * @param stack of vertices to visit.
	 * @param column identifier.
	 */
	void exploreHorizontal(std::vector<unsigned int>&, std::stack<unsigned int>&, unsigned int);

	/**
	 * @brief Check whether a hyper-vertex has already been visited.
	 * @param vector of visited hyper-vertices.
	 * @param identifier to check.
	 * @return `true` if already visited, `false` otherwise.
	 */
	bool isVertexVisited(std::vector<unsigned int>&, unsigned int) const;

	/**
	 * @brief Check whether a hyper-edge has already been visited.
	 * @param vector of visited hyper-edges.
	 * @param identifier to check.
	 * @return `true` if already visited, `false` otherwise.
	 */
	bool isEdgeVisited(std::vector<unsigned int>&, unsigned int) const;


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

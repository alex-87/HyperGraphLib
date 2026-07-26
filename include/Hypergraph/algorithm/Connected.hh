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
 * Definition of the algorithm deciding the connectivity of a hypergraph.
 */
#ifndef ALGORITHM_INCLUDE_CONNECTED_HH_
#define ALGORITHM_INCLUDE_CONNECTED_HH_

#include "../model/HypergrapheAbstrait.hh"
#include "../model/AlgorithmeAbstrait.hh"

#include <memory>
#include <stack>
#include <vector>

/**
 * Algorithm deciding the connectivity of a hypergraph.
 */
class Connected : public AlgorithmeAbstrait {
  public:
	/**
	 * Constructor.
	 * @param std::shared_ptr<HypergrapheAbstrait> shared pointer to the hypergraph.
	 */
	Connected(std::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Get the result structure.
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~Connected() = default;


  protected:
	/**
	 * Run the algorithm.
	 */
	void runAlgorithme();

	/**
	 * Exploration verticale d'un chemin de la matrice.
	 * @param vector of visited elements.
	 * @param stack of vertices to visit.
	 * @param row identifier.
	 */
	void exploreVertical(std::vector<unsigned int>&, std::stack<unsigned int>&, unsigned int);

	/**
	 * Exploration horizontale d'un chemin dans la matrice.
	 * @param vector of visited elements.
	 * @param stack of vertices to visit.
	 * @param column identifier.
	 */
	void exploreHorizontal(std::vector<unsigned int>&, std::stack<unsigned int>&, unsigned int);

	/**
	 * Check whether a hyper-vertex has already been visited.
	 * @param vector of visited hyper-vertices.
	 * @param identifier to check.
	 * @return true if already visited, false otherwise.
	 */
	bool isVertexVisited(std::vector<unsigned int>&, unsigned int) const;

	/**
	 * Check whether a hyper-edge has already been visited.
	 * @param vector of visited hyper-edges.
	 * @param identifier to check.
	 * @return true if already visited, false otherwise.
	 */
	bool isEdgeVisited(std::vector<unsigned int>&, unsigned int) const;


  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<HypergrapheAbstrait>
	    _ptrAbstractHypergraph;

	/**
	 * Result structure.
	 */
	RStructure _result;
};


#endif /* ALGORITHM_INCLUDE_CONNECTED_HH_ */

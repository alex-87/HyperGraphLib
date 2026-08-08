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

#ifndef ALGORITHM_INCLUDE_SIMPLE_HH_
#define ALGORITHM_INCLUDE_SIMPLE_HH_

#include <memory>
#include "../model/AbstractHypergraph.hh"
#include "../model/Hypergraph.hh"
#include "../model/HyperVertex.hh"
#include "../model/HyperEdge.hh"
#include "../model/AbstractAlgorithm.hh"
#include "../model/ResultStructure.hh"
#include "Linear.hh"

/**
 * @brief Implementation of the `SIMPLE` algorithm.
 *
 * This algorithm determines whether a hypergraph is **simple**, i.e.
 * whether no hyper-edge is included in another through its hyper-vertices.
 */
class Simple : public AbstractAlgorithm {
  public:
	/**
	 * @brief Construct a new Simple object.
	 * @param hypergraph to which the algorithm is applied.
	 */
	Simple(std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Get the result.
	 * @return ResultStructure
	 */
	ResultStructure getResult() const;

	/**
	 * @brief Destructor.
	 */
	~Simple() = default;


  protected:
	friend class Linear;

	/**
	 * @brief Run the algorithm.
	 */
	void run();

	/**
	 * @brief Check inclusion between hyper-edges through their vertices.
	 * @param first list of hyper-vertices.
	 * @param second list of hyper-vertices.
	 * @return `true` if one list is included in the other, `false` otherwise.
	 */
	bool subsetVertexList(const LibType::ListHyperVertex&, const LibType::ListHyperVertex&) const;

	/**
	 * @brief Check whether a hyper-vertex is contained in the list.
	 * @param list of hyper-vertices.
	 * @param hyper-vertex to look for.
	 * @return `true` if contained, `false` otherwise.
	 */
	bool contains(const LibType::ListHyperVertex&, const std::shared_ptr<HyperVertex>&) const;


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


#endif /* ALGORITHM_INCLUDE_SIMPLE_HH_ */

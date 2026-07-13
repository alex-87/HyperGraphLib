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
 * Definition of the simple algorithm class.
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
 * simple algorithm on the hypergraph.
 */
class Simple : public AbstractAlgorithm {
  public:
	/**
	 * Constructor
	 * @param shared pointer to the hypergraph.
	 */
	Simple(std::shared_ptr<AbstractHypergraph>&);

	/**
	 * Get the result structure.
	 * @return the result structure.
	 */
	ResultStructure getResult() const;

	/**
	 * Destructor.
	 */
	~Simple() = default;


  protected:
	friend class Linear;

	/**
	 * Run the algorithm.
	 */
	void run();

	/**
	 * Check inclusion between hyper-edges through their vertices.
	 * @param the first list.
	 * @param the second list.
	 * @return True if included; False otherwise.
	 */
	bool subsetVertexList(const LibType::ListHyperVertex&, const LibType::ListHyperVertex&) const;

	/**
	 * Check whether a hyper-vertex is contained in the list.
	 * @param list of hyper-vertices.
	 * @param L'hyer-vertex.
	 * @return True if contained; False otherwise.
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

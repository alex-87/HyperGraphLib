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

#ifndef MODEL_INCLUDE_HYPERGRAPH_HH_
#define MODEL_INCLUDE_HYPERGRAPH_HH_

#include "AbstractHypergraph.hh"
#include "HyperVertex.hh"
#include "HyperEdge.hh"

/**
 * @brief Concrete implementation of a hypergraph.
 */
class Hypergraph : public AbstractHypergraph {
  public:
	/**
	 * @brief Construct a new Hypergraph object.
	 */
	Hypergraph();

	/**
	 * @brief Create a new hypervertex in the hypergraph.
	 * @return the new hypervertex, whose identifier is the previous number of hypervertices.
	 */
	std::shared_ptr<HyperVertex> addHyperVertex();

	/**
	 * @brief Create a new hyperedge in the hypergraph.
	 * @return the new hyperedge, whose identifier is the previous number of hyperedges.
	 */
	std::shared_ptr<HyperEdge> addHyperEdge();

	/**
	 * @brief Make the hypervertex belong to the hyperedge.
	 * @param hypervertex of this hypergraph.
	 * @param hyperedge of this hypergraph.
	 * @throw std::invalid_argument if an element does not belong to this hypergraph.
	 */
	void link(const std::shared_ptr<HyperVertex>&, const std::shared_ptr<HyperEdge>&);

	/**
	 * @brief Destructor.
	 */
	~Hypergraph() = default;

  protected:
};


#endif /* MODEL_INCLUDE_HYPERGRAPH_HH_ */

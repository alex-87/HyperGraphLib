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
	 * @brief Add a hypervertex to the hypergraph.
	 * @param hypervertex to add.
	 */
	void addHyperVertex(const std::shared_ptr<HyperVertex>&);

	/**
	 * @brief Add a hyperedge to the hypergraph.
	 * @param hyperedge to add.
	 */
	void addHyperEdge(const std::shared_ptr<HyperEdge>&);

	/**
	 * @brief Get a hypervertex by its identifier.
	 * @param identifier of the hypervertex to get.
	 * @return the hypervertex.
	 */
	std::shared_ptr<HyperVertex>& getHyperVertexById(const unsigned int&);

	/**
	 * @brief Get a hyperedge by its identifier.
	 * @param identifier of the hyperedge to get.
	 * @return the hyperedge.
	 */
	std::shared_ptr<HyperEdge>& getHyperEdgeById(const unsigned int&);

	/**
	 * @brief Build the hypergraph, in particular its adjacency matrix.
	 */
	void flush();

	/**
	 * @brief Destructor.
	 */
	~Hypergraph() = default;

  protected:
};


#endif /* MODEL_INCLUDE_HYPERGRAPH_HH_ */

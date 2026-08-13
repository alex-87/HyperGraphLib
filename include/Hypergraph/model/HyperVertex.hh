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

#ifndef HYPER_VERTEX_HH
#define HYPER_VERTEX_HH

#include <memory>

#include "LibType.hh"
#include "AbstractHypergraph.hh"

/**
 * @brief Implementation of a hypervertex.
 *
 * A hypervertex belongs to an arbitrary number of hyperedges within a
 * hypergraph.
 */
class HyperVertex {
  public:
	/**
	 * @brief Construct a new HyperVertex object.
	 * @param hypergraph the hypervertex belongs to.
	 * @param numeric identifier of the hypervertex.
	 */
	HyperVertex(const std::shared_ptr<AbstractHypergraph>&, unsigned int& identifier);

	/**
	 * @brief Add a hyperedge to the hypervertex.
	 * @param hyperedge to add.
	 */
	void addHyperEdge(std::shared_ptr<HyperEdge>&);

	/**
	 * @brief Get the number of hyperedges the hypervertex belongs to.
	 * @return the number of hyperedges the hypervertex belongs to.
	 */
	const unsigned int getVertexDegree() const;

	/**
	 * @brief Check whether the hyperedge contains this hypervertex.
	 * @param hyperedge to check.
	 * @return true if the hypervertex belongs to the hyperedge.
	 */
	bool containEdge(std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Get the numeric identifier of the hypervertex.
	 * @return the numeric identifier of the hypervertex.
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * @brief Operator overload based on the numeric identifier.
	 */
	bool operator==(const std::shared_ptr<HyperVertex>&) const;

	/**
	 * @brief Operator overload based on the numeric identifier.
	 */
	bool operator<(const std::shared_ptr<HyperVertex>&) const;

	/**
	 * @brief Operator overload based on the numeric identifier.
	 */
	bool operator>(const std::shared_ptr<HyperVertex>&) const;

	/**
	 * @brief Get the list of hyperedges containing the hypervertex.
	 * @return the list of hyperedges containing the hypervertex.
	 */
	const LibType::ListHyperEdge& getHyperEdgeList() const;


  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrHypergraph;

	/**
	 * Numeric identifier.
	 */
	unsigned int _identifier;

	/**
	 * List of hyperedges containing the hypervertex.
	 */
	LibType::ListHyperEdge
	    _listHyperEdge;
};

#endif

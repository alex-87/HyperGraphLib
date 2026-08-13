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

#ifndef _HYPEREDGE_HH
#define _HYPEREDGE_HH

#include <memory>

#include "LibType.hh"
#include "AbstractHypergraph.hh"

/**
 * @brief Implementation of a hyperedge.
 *
 * A hyperedge links an arbitrary number of hypervertices within a
 * hypergraph.
 */
class HyperEdge {
  public:
	/**
	 * @brief Construct a new HyperEdge object.
	 * @param hypergraph the hyperedge belongs to.
	 * @param numeric identifier of the hyperedge.
	 */
	HyperEdge(const std::shared_ptr<AbstractHypergraph>&, unsigned int& identifier);

	/**
	 * @brief Add a hypervertex to the hyperedge.
	 * @param hypervertex to add.
	 */
	void addHyperVertex(std::shared_ptr<HyperVertex>&);

	/**
	 * @brief Set the list of hypervertices contained in the hyperedge.
	 * @param list of hypervertices.
	 */
	void setHyperVertexList(LibType::ListHyperVertex&);

	/**
	 * @brief Get the list of hypervertices contained in the hyperedge.
	 * @return the list of hypervertices.
	 */
	LibType::ListHyperVertex& getHyperVertexList();

	/**
	 * @brief Get the cardinality of the hyperedge.
	 * @return the cardinality of the hyperedge.
	 */
	const unsigned int getEffectif() const;

	/**
	 * @brief Get the numeric identifier of the hyperedge.
	 * @return the hyperedge identifier.
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * @brief Check whether a hypervertex belongs to the hyperedge.
	 * @param hypervertex to check.
	 * @return `true` if the hypervertex is present in the hyperedge, `false` otherwise.
	 */
	bool containVertex(std::shared_ptr<HyperVertex>&) const;

	/**
	 * @brief Operator overload comparing on the numeric identifier.
	 */
	bool operator==(const std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Operator overload comparing on the numeric identifier.
	 */
	bool operator<(const std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Operator overload comparing on the numeric identifier.
	 */
	bool operator>(const std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Get the list of hypervertices contained in the hyperedge.
	 * @return the list of hypervertices.
	 */
	const LibType::ListHyperVertex& getHyperVertexList() const;

  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrHypergraph;

	/**
	 * The numeric identifier.
	 */
	unsigned int _identifier;

	/**
	 * List of hypervertices.
	 */
	LibType::ListHyperVertex
	    _listHyperVertex;
};

#endif

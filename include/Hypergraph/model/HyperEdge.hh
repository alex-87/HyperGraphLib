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
 * Model of a hyper-edge.
 */
#ifndef _HYPEREDGE_HH
#define _HYPEREDGE_HH

#include <memory>

#include "LibType.hh"
#include "HypergrapheAbstrait.hh"

/**
 * Definition of the hyper-edge.
 */
class HyperEdge {
  public:
	/**
	 * Constructor.
	 * @param shared pointer to the hypergraph.
	 * @param numeric identifier of the hyper-edge.
	 */
	HyperEdge(const std::shared_ptr<HypergrapheAbstrait>&, unsigned int& identifier);

	/**
	 * Add a hyper-vertex to the hyper-edge.
	 * @param the hyper-vertex to add.
	 */
	void addHyperVertex(std::shared_ptr<HyperVertex>&);

	/**
	 * Set the list of hyper-vertices contained in the hyper-edge.
	 * @param list of hyper-vertices.
	 */
	void setHyperVertexList(LibType::ListHyperVertex&);

	/**
	 * Get the list of hyper-vertices contained in the hyper-edge.
	 * @return the list of hyper-vertices.
	 */
	LibType::ListHyperVertex& getHyperVertexList();

	/**
	 * Get the cardinality of the hyper-edge.
	 * @return L'effectif.
	 */
	const unsigned int getEffectif() const;

	/**
	 * Get the numeric identifier of the hyper-edge.
	 * @return the hyper-edge identifier.
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * Check whether a hyper-vertex belongs to the hyper-edge.
	 * @param Le vertex
	 * @return true if the hyper-vertex is present in the hyper-edge, false otherwise.
	 */
	bool containVertex(std::shared_ptr<HyperVertex>&) const;

	/**
	 * Operator overload comparing on the numeric identifier.
	 */
	bool operator==(const std::shared_ptr<HyperEdge>&) const;

	/**
	 * Operator overload comparing on the numeric identifier.
	 */
	bool operator<(const std::shared_ptr<HyperEdge>&) const;

	/**
	 * Operator overload comparing on the numeric identifier.
	 */
	bool operator>(const std::shared_ptr<HyperEdge>&) const;

	/**
	 * Get the list of hyper-vertices contained in the hyper-edge.
	 * @return the list of hyper-vertices.
	 */
	const LibType::ListHyperVertex& getHyperVertexList() const;

  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<HypergrapheAbstrait>
	    _ptrHypergraph;

	/**
	 * The numeric identifier.
	 */
	unsigned int _identifier;

	/**
	 * List of hyper-vertices.
	 */
	LibType::ListHyperVertex
	    _listHyperVertex;
};

#endif

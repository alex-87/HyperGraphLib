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
 * Model of the hyper-vertex.
 */

#ifndef HYPER_VERTEX_HH
#define HYPER_VERTEX_HH

#include <memory>

#include "LibType.hh"
#include "AbstractHypergraph.hh"

/**
 * Declaration of the hyper-vertex class.
 */
class HyperVertex {
  public:
	/**
	 * Constructor.
	 * @param shared pointer to the hypergraph the hyper-vertex belongs to.
	 * @param the numeric identifier of the hyper-vertex.
	 */
	HyperVertex(const std::shared_ptr<AbstractHypergraph>&, unsigned int& identifier);

	/**
	 * Add a hyper-edge to the hyper-vertex.
	 * @param the hyper-edge to add.
	 */
	void addHyperEdge(std::shared_ptr<HyperEdge>&);

	/**
	 * Get the number of hyper-edges the hyper-vertex belongs to.
	 * @return the number of hyper-edges the hyper-vertex belongs to.
	 */
	const unsigned int getVertexDegree() const;

	/**
	 * Check whether the hyper-edge contains this hyper-vertex.
	 * @param the hyper-edge.
	 * @return true if the hyper-vertex belongs to the hyper-edge.
	 */
	bool containEdge(std::shared_ptr<HyperEdge>&) const;

	/**
	 * Get the numeric identifier of the hyper-vertex.
	 * @return the numeric identifier of the hyper-vertex.
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * Operator overload based on the numeric identifier.
	 */
	bool operator==(const std::shared_ptr<HyperVertex>&) const;

	/**
	 * Operator overload based on the numeric identifier.
	 */
	bool operator<(const std::shared_ptr<HyperVertex>&) const;

	/**
	 * Operator overload based on the numeric identifier.
	 */
	bool operator>(const std::shared_ptr<HyperVertex>&) const;

	/**
	 * Get the list of hyper-edges containing the hyper-vertex.
	 * @return the list of hyper-edges containing the hyper-vertex.
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
	 * List of hyper-edges containing the hyper-vertex.
	 */
	LibType::ListHyperEdge
	    _listHyperEdge;
};

#endif

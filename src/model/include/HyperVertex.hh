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
 * Hyper-vertex object
 */

#ifndef HYPER_VERTEX_HH
#define HYPER_VERTEX_HH

#include <boost/shared_ptr.hpp>

#include "LibType.hh"
#include "HypergrapheAbstrait.hh"

/**
 * Hyper-vertex object
 */
class HyperVertex {

public:

	/**
	 * Constructor
	 * @param Hypergraph shared pointer
	 * @param Hyper-vertex Id
	 */
	HyperVertex(const boost::shared_ptr<HypergrapheAbstrait>&, unsigned int& identifier);

	/**
	 * Add hyper-edge
	 * @param Hyper-edge to add
	 */
	void addHyperEdge(boost::shared_ptr<HyperEdge>&);

	/**
	 * Get the hyper-vertex's degree
	 * @return The hyper-vertex's degree
	 */
	const unsigned int getVertexDegree() const;

	/**
	 * Check whether the hyper-vertex is contained into the specified hyper-edge
	 * @param Hyper-edge
	 * @return True or False
	 */
	bool containEdge(boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Get the hyper-vertex's Id
	 * @return The hyper-vertex's Id
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * Operator == overload. Based on the Id
	 */
	bool operator==(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Operator < overload. Based on the Id
	 */
	bool operator<(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Operator > overload. Based on the Id
	 */
	bool operator>(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Get the hyper-edges list containing the hyper-vertex
	 * @return The hyper-edges list containing the hyper-vertex
	 */
	const LibType::ListHyperEdge& getHyperEdgeList() const;


protected:

	/**
	 * HypergrapheAbstrait shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergraphe;

	/**
	 * Id
	 */
	unsigned int _identifier;

	/**
	 * Hyper-edges list containing the hyper-vertex
	 */
	LibType::ListHyperEdge
	_listHyperEdge;

};

#endif

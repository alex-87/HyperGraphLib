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
 * Hypergraph object
 */
#ifndef MODEL_INCLUDE_HYPERGRAPHE_HH_
#define MODEL_INCLUDE_HYPERGRAPHE_HH_

#include "HypergrapheAbstrait.hh"

/**
 * Hypergraph object
 */
class Hypergraphe : public HypergrapheAbstrait {

public:

	/**
	 * Default constructor
	 */
	Hypergraphe();

	/**
	 * Add hyper-vertex
	 * @param Hyper-vertex to add
	 */
	void addHyperVertex(const boost::shared_ptr<HyperVertex>&);

	/**
	 * Add hyper-edge
	 * @param Hyper-edge to add
	 */
	void addHyperEdge(const boost::shared_ptr<HyperEdge>&);

	/**
	 * Get hyper-vertex by Id
	 * @param Hyper-vertex's Id
	 */
	boost::shared_ptr<HyperVertex>& getHyperVertexById(const unsigned int&);

	/**
	 * Get hyper-edge by Id
	 * @param Hyper-edge's Id
	 */
	boost::shared_ptr<HyperEdge>& getHyperEdgeById(const unsigned int&);

	/**
	 * Build the adjacency matrix
	 */
	void flush();

	/**
	 * Destructor
	 */
	~Hypergraphe();

protected:

};



#endif /* MODEL_INCLUDE_HYPERGRAPHE_HH_ */

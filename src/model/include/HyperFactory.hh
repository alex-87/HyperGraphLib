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
 * Hypergraph factory object
 */
#ifndef MODEL_INCLUDE_HYPERFACTORY_HH_
#define MODEL_INCLUDE_HYPERFACTORY_HH_

#include "HyperVertex.hh"
#include "HyperEdge.hh"

/**
 * Hypergraph factory object
 */
class HyperFactory {

public:

	/**
	 * Singleton instance
	 */
	static HyperFactory& Instance();


public:

	/**
	 * Start a factory session
	 * @param Hypergraph shared pointer
	 */
	static void startSession(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait);

	/**
	 * Create a hyper-vertex
	 * @return New hyper-vertex
	 */
	static const boost::shared_ptr<HyperVertex> newHyperVertex();

	/**
	 * Create a hyper-edge
	 * @return New hyper-edge
	 */
	static const boost::shared_ptr<HyperEdge> newHyperEdge();

	/**
	 * Link hyper-edge to hyper-vertex
	 * @param L'hyper-vertex
	 * @param L'hyper-edge
	 */
	static void link(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperEdge>&);

	/**
	 * Check whether a session is already started
	 * @return True or False
	 */
	static bool isSession();

	/**
	 * End the factory session
	 */
	static void closeSession();


private:

	/**
	 * Constructor
	 */
	HyperFactory();

	/**
	 * Constructor
	 */
	HyperFactory(const HyperFactory&);

	/**
	 * Constructor
	 */
	HyperFactory& operator= (const HyperFactory&);

	/**
	 * Destructor
	 */
	~HyperFactory();


private:

	/**
	 * Singleton instance
	 */
	static HyperFactory _instance;

	/**
	 * Hyper-vertex counter
	 */
	static unsigned int _indexVertex;

	/**
	 * Hyper-edge counter
	 */
	static unsigned int _indexEdge;

	/**
	 * Session flag
	 */
	static bool         _isSession;

	/**
	 * HypergrapheAbstrait shared pointer
	 */
	static boost::shared_ptr<HypergrapheAbstrait> _ptrHypergrapheAbstrait;

};


#endif /* MODEL_INCLUDE_HYPERFACTORY_HH_ */

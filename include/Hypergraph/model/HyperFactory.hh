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
 * Definition of the hypergraph factory.
 */
#ifndef MODEL_INCLUDE_HYPERFACTORY_HH_
#define MODEL_INCLUDE_HYPERFACTORY_HH_

#include "HyperVertex.hh"
#include "HyperEdge.hh"

/**
 * Class modelling the hypergraph factory.
 */
class HyperFactory {
  public:
	/**
	 * Instance unique de la fabrique.
	 */
	static HyperFactory& Instance();


  public:
	/**
	 * Start a hypergraph construction session.
	 * @param shared pointer to the hypergraph.
	 */
	static void startSession(std::shared_ptr<HypergrapheAbstrait>& ptrAbstractHypergraph);

	/**
	 * Create a new hyper-vertex.
	 * @return the new hyper-vertex.
	 */
	static const std::shared_ptr<HyperVertex> newHyperVertex();

	/**
	 * Create a new hyper-edge.
	 * @return the new hyper-edge.
	 */
	static const std::shared_ptr<HyperEdge> newHyperEdge();

	/**
	 * Link a hyper-edge to a hyper-vertex.
	 * @param the hyper-vertex to link.
	 * @param the hyper-edge to link.
	 */
	static void link(std::shared_ptr<HyperVertex>&, std::shared_ptr<HyperEdge>&);

	/**
	 * Test whether a session is already open.
	 * @return True si c'est le cas, False sinon.
	 */
	static bool isSession();

	/**
	 * Terminer la session de construction.
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
	HyperFactory& operator=(const HyperFactory&);

	/**
	 * Destructor
	 */
	~HyperFactory() = default;


  private:
	/**
	 * Instnce unique de la fabrique.
	 */
	static HyperFactory _instance;

	/**
	 * Counter of hyper-vertex indices.
	 */
	static unsigned int _indexVertex;

	/**
	 * Counter of hyper-edge indices.
	 */
	static unsigned int _indexEdge;

	/**
	 * Indicateur de session.
	 */
	static bool _isSession;

	/**
	 * Shared pointer to the hypergraph.
	 */
	static std::shared_ptr<HypergrapheAbstrait> _ptrAbstractHypergraph;
};


#endif /* MODEL_INCLUDE_HYPERFACTORY_HH_ */

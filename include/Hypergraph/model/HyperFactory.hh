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

#ifndef MODEL_INCLUDE_HYPERFACTORY_HH_
#define MODEL_INCLUDE_HYPERFACTORY_HH_

#include "HyperVertex.hh"
#include "HyperEdge.hh"

/**
 * @brief Factory building a hypergraph.
 *
 * hypervertices and hyperedges are created and linked through a
 * construction session opened with `startSession` and closed with
 * `closeSession`.
 */
class HyperFactory {
  public:
	/**
	 * @brief Start a hypergraph construction session.
	 * @param hypergraph to build.
	 */
	static void startSession(std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph);

	/**
	 * @brief Create a new hypervertex.
	 * @return the new hypervertex.
	 */
	static const std::shared_ptr<HyperVertex> newHyperVertex();

	/**
	 * @brief Create a new hyperedge.
	 * @return the new hyperedge.
	 */
	static const std::shared_ptr<HyperEdge> newHyperEdge();

	/**
	 * @brief Link a hyperedge to a hypervertex.
	 * @param hypervertex to link.
	 * @param hyperedge to link.
	 */
	static void link(std::shared_ptr<HyperVertex>&, std::shared_ptr<HyperEdge>&);

	/**
	 * @brief Test whether a session is already open.
	 * @return `true` if a session is open, `false` otherwise.
	 */
	static bool isSession();

	/**
	 * @brief Close the construction session.
	 */
	static void closeSession();


  private:
	/**
	 * @brief Construct a new HyperFactory object.
	 */
	HyperFactory();

	/**
	 * @brief Copy constructor, disabled to enforce the static-only usage.
	 */
	HyperFactory(const HyperFactory&);

	/**
	 * @brief Assignment operator, disabled to enforce the static-only usage.
	 */
	HyperFactory& operator=(const HyperFactory&);

	/**
	 * @brief Destructor.
	 */
	~HyperFactory() = default;

  private:
	/**
	 * Counter of hypervertex indices.
	 */
	static unsigned int _indexVertex;

	/**
	 * Counter of hyperedge indices.
	 */
	static unsigned int _indexEdge;

	/**
	 * Session state flag.
	 */
	static bool _isSession;

	/**
	 * Shared pointer to the hypergraph.
	 */
	static std::shared_ptr<AbstractHypergraph> _ptrAbstractHypergraph;
};


#endif /* MODEL_INCLUDE_HYPERFACTORY_HH_ */

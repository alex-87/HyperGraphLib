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


#ifndef ALGORITHM_INCLUDE_ISOMORPHISMSPACE_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISMSPACE_HH_

#include <gecode/int.hh>
#include <gecode/search.hh>
#include <memory>

#include "../model/LibType.hh"
#include "../model/Hypergraph.hh"
#include "../model/HyperVertex.hh"
#include "../model/HyperEdge.hh"

class AbstractHypergraph;

/**
 * @brief Gecode constraint-programming space used to search for an
 * isomorphism between two hypergraphs.
 *
 * The hyper-edge and hyper-vertex mappings between the two hypergraphs
 * are modelled as Gecode integer variable arrays, constrained by
 * `postConstraints` so that a valid assignment corresponds to an
 * isomorphism.
 */
class IsomorphSpace : public Gecode::Space {
  public:
	/**
	 * @brief Construct a new IsomorphSpace object.
	 * @param first hypergraph to compare.
	 * @param second hypergraph to compare.
	 */
	IsomorphSpace(const std::shared_ptr<AbstractHypergraph>&, const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Post the constraints modelling the isomorphism between the two hypergraphs.
	 */
	void postConstraints();

	/**
	 * @brief Copy the space, as required by Gecode search.
	 * @return Gecode::Space*
	 */
	Gecode::Space* copy();

	/**
	 * @brief Copy constructor, as required by Gecode search.
	 * @param space to copy.
	 */
	IsomorphSpace(IsomorphSpace& p);


  protected:
	/**
	 * Mapping variables between the hyper-edges of both hypergraphs.
	 */
	Gecode::IntVarArray _edgeMapping;

	/**
	 * Mapping variables between the hyper-vertices of both hypergraphs.
	 */
	Gecode::IntVarArray _vertexMapping;

	/**
	 * Shared pointer to the first hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph> _ptrH1;

	/**
	 * Shared pointer to the second hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph> _ptrH2;
};

#endif

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
 * Definition of the algorithm generating the hypergraph statistics.
 */

#ifndef ALGORITHM_INCLUDE_HPGSTAT
#define ALGORITHM_INCLUDE_HPGSTAT

#include <memory>
#include "../model/HypergrapheAbstrait.hh"
#include "../model/Hypergraphe.hh"
#include "../model/HyperVertex.hh"
#include "../model/HyperEdge.hh"
#include "../model/AlgorithmeAbstrait.hh"
#include "../model/RStructure.hh"


/**
 * Algorithm generating the hypergraph statistics.
 */
class HyperGraphStat : public AlgorithmeAbstrait {
  public:
	/**
	 * Constructor.
	 * @param shared pointer to the hypergraph.
	 */
	HyperGraphStat(const std::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Get the result structure - unused here.
	 * @return the result structure - unused here.
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~HyperGraphStat() = default;


  public:
	/**
	 * Get the number of hyper-edges.
	 */
	unsigned int getNbrHyperEdge() const;

	/**
	 * Get the number of hyper-vertices.
	 */
	unsigned int getNbrHyperVertex() const;

	/**
	 * Get the number of vertex-edge connections.
	 */
	unsigned int getNbrLinks() const;

	/**
	 * Get the rank of the hypergraph.
	 */
	unsigned int getRang() const;

	/**
	 * Get the co-rank of the hypergraph.
	 */
	unsigned int getCoRang() const;

  protected:
	/**
	 * Lancment de l'algorithme.
	 */
	void runAlgorithme();

  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<HypergrapheAbstrait>
	    _ptrAbstractHypergraph;

	/**
	 * The result structure - unused here.
	 */
	RStructure _result;

	/**
	 * The number of hyper-edges.
	 */
	unsigned int _nhEdge;

	/**
	 * The number of hyper-vertices.
	 */
	unsigned int _nhVertex;

	/**
	 * The number of vertex-edge connections.
	 */
	unsigned int _nhLink;

	/**
	 * The rank of the hypergraph.
	 */
	unsigned int _rank;

	/**
	 * The co-rank of the hypergraph.
	 */
	unsigned int _coRank;
};


#endif

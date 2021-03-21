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
 * Stats on hypergraph
 */

#ifndef ALGORITHM_INCLUDE_HPGSTAT
#define ALGORITHM_INCLUDE_HPGSTAT

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"


/**
 * Stats on hypergraph
 */
class HyperGraphStat : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor.
	 * @param Hypergraph shared pointer
	 */
	HyperGraphStat(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Unused here
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~HyperGraphStat();


public:

	/**
	 * Get hyper-edge count
	 */
	unsigned int getNbrHyperEdge() const;

	/**
	 * Get hyper-vertex count
	 */
	unsigned int getNbrHyperVertex() const;

	/**
	 * Get links count
	 */
	unsigned int getNbrLinks() const;

	/**
	 * Get hypergraph's rank
	 */
	unsigned int getRang() const;

	/**
	 * Get hypergraph's co-rank
	 */
	unsigned int getCoRang() const;

protected:

	/**
	 * Run the algorithm
	 */
	void runAlgorithme();

protected:

	/**
	 * Hypergraph shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Unused here
	 */
	RStructure _result;

	/**
	 * Hyper-edge count
	 */
	unsigned int _nhEdge;

	/**
	 * Hyper-vertex count
	 */
	unsigned int _nhVertex;

	/**
	 * Links count
	 */
	unsigned int _nhLink;

	/**
	 * Hypergraph's rank
	 */
	unsigned int _rang;

	/**
	 * Hypergraph's co-rank
	 */
	unsigned int _coRang;

};


#endif

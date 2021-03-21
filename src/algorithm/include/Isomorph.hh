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
 * Isomorphism algorithm
 */

#ifndef ALGORITHM_INCLUDE_ISOMORPHISM_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISM_HH_

#include <boost/config.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>

#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"

/**
 * Isomorphism algorithm
 */
class Isomorph : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor.
	 * @param Hypergraph shared pointer
	 * @param Hypergraph shared pointer
	 */
	Isomorph(const boost::shared_ptr<HypergrapheAbstrait>&, const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Get result structure
	 * @Result structure
	 */
	RStructure getResult() const;

	/**
	 * Destructor
	 */
	~Isomorph();

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
	_ptrHypergrapheAbstraitA;

	/**
	 * Hypergraph shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstraitB;

	/**
	 * Result structure
	 */
	RStructure _result;

};



#endif

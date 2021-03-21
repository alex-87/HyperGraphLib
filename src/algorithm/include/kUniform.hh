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
 * K-uniforme algorithm
 */
#ifndef ALGORITHM_INCLUDE_KUNIFORM_HH_
#define ALGORITHM_INCLUDE_KUNIFORM_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"

/**
 * K-uniforme algorithm
 */
class kUniform : public AlgorithmeAbstrait {

public:

	/**
	 * Constructor
	 * @param Hypergraph shared pointer
	 * @param K value
	 */
	kUniform(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait, const unsigned int&);

	/**
	 * Get result structure
	 * @return Result structure
	 */
	RStructure getResult() const;

	/**
	 * Destructor.
	 */
	~kUniform();


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
	 * K value
	 */
	unsigned int _k;

	/**
	 * Result structure
	 */
	RStructure _result;

};



#endif /* ALGORITHM_INCLUDE_KUNIFORM_HH_ */

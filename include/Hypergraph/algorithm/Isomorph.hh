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


#ifndef ALGORITHM_INCLUDE_ISOMORPHISM_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISM_HH_

#include <boost/config.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>

#include "../model/HypergrapheAbstrait.hh"
#include "../model/AlgorithmeAbstrait.hh"

class Isomorph : public AlgorithmeAbstrait {

public:

	Isomorph(const boost::shared_ptr<HypergrapheAbstrait>&, const boost::shared_ptr<HypergrapheAbstrait>&);

	RStructure getResult() const;

	~Isomorph();

protected:

	typedef boost::adjacency_list<boost::vecS, boost::listS, boost::undirectedS, boost::property<boost::vertex_index_t, int> >
	graph_t;

	void hypergraphTranspose(const boost::shared_ptr<HypergrapheAbstrait>&, graph_t&);

	void runAlgorithme();

protected:

	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstraitA;

	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstraitB;

	RStructure _result;

};



#endif

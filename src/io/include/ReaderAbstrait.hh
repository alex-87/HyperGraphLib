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
 * Input interface
 */
#ifndef IO_INCLUDE_READERABSTRAIT_HH_
#define IO_INCLUDE_READERABSTRAIT_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Input interface
 */
class ReaderAbstrait {

public:

	/**
	 * Constructor
	 * @param HypergrapheAbstrait shared pointer
	 */
	ReaderAbstrait(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Read and build the hypergraph
	 * @param Input flow
	 */
	virtual void readHypergraphe(std::istream&) = 0;

	/**
	 * Get the hypergraph after building
	 */
	boost::shared_ptr<HypergrapheAbstrait>&
	getHypergraphe();

	/**
	 * Virtual destructor
	 */
	virtual ~ReaderAbstrait();


protected:

	/**
	 * Read hyper-vertex
	 * @param Input flow
	 */
	virtual void readHypergrapheHyperVertex(std::istream&) = 0;

	/**
	 * Read hyper-edge
	 * @param Input flow
	 */
	virtual void readHypergrapheHyperEdge(std::istream&) = 0;


protected:

	/**
	 * HypergrapheAbstrait shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

};



#endif /* IO_INCLUDE_READERABSTRAIT_HH_ */

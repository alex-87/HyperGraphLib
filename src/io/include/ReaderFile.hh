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
 * Input module
 */
#ifndef IO_INCLUDE_READERFILE_HH_
#define IO_INCLUDE_READERFILE_HH_

#include "ReaderAbstrait.hh"
#include <istream>


/**
 * Input module
 */
class ReaderFile : public ReaderAbstrait {

public:

	/**
	 * Constructor
	 */
	ReaderFile();

	/**
	 * Read and build the hypergraph
	 * @param Input flow
	 */
	void readHypergraphe(std::istream&);

	/**
	 * Destructor
	 */
	~ReaderFile();


protected:

	/**
	 * Read hyper-vertex
	 * @param Input flow
	 */
	void readHypergrapheHyperVertex(std::istream&);

	/**
	 * Read hyper-edge
	 * @param Input flow
	 */
	void readHypergrapheHyperEdge(std::istream&);

	/**
	 * Get hyper-vertex by Id
	 * @param Id
	 */
	boost::shared_ptr<HyperVertex>& hyperVertexById(unsigned int&);

	/**
	 * Get hyper-edge by Id
	 * @param Id
	 */
	boost::shared_ptr<HyperEdge>& hyperEdgeById(unsigned int&);

	/**
	 * Build the hypergraph
	 */
	void flush();


protected:

	/**
	 * Read hyper-vertex
	 */
	LibType::ListHyperVertex
	_listHyperVertex;

	/**
	 * Read hyper-edge
	 */
	LibType::ListHyperEdge
	_listHyperEdge;

};


#endif /* IO_INCLUDE_READERFILE_HH_ */

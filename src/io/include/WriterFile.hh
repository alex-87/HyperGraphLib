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
 * Output module
 */
#ifndef IO_INCLUDE_WRITERFILE_HH_
#define IO_INCLUDE_WRITERFILE_HH_

#include "WriterAbstrait.hh"

/**
 * Output module
 */
class WriterFile : public WriterAbstrait {

public:

	/**
	 * Constructor
	 * @param HypergrapheAbstrait shared pointer
	 */
	WriterFile(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Adajency matrix output
	 * @param Output flow
	 */
	void writeAdjacentMatrix(std::ostream&) const;

	/**
	 * Hypergraph output write
	 * @param Output flow
	 */
	void writeHypergraph(std::ostream&) const;


protected:

	/**
	 * Output hyper-vertex write
	 * @param Output flow
	 */
	void writeHypergrapheHyperVertex(std::ostream&) const;

	/**
	 * Output hyper-edge write
	 * @param Output flow
	 */
	void writeHypergrapheHyperEdge(std::ostream&) const;


protected:

};



#endif /* IO_INCLUDE_READERFILE_HH_ */

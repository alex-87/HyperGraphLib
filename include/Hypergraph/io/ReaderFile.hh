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
 * Module de lecture.
 */
#ifndef IO_INCLUDE_READERFILE_HH_
#define IO_INCLUDE_READERFILE_HH_

#include "AbstractReader.hh"
#include <istream>


/**
 * Declaration of the reader module.
 */
class ReaderFile : public AbstractReader {
  public:
	/**
	 * Constructor.
	 */
	ReaderFile();

	/**
	 * Read the hypergraph instance.
	 * @param input stream.
	 */
	void readHypergraph(std::istream&);

	/**
	 * Destructor.
	 */
	~ReaderFile() = default;


  protected:
	/**
	 * Read the hyper-vertices of the instance.
	 * @param input stream.
	 */
	void readHypergraphHyperVertex(std::istream&);

	/**
	 * Read the hyper-edges of the instance.
	 * @param input stream.
	 */
	void readHypergraphHyperEdge(std::istream&);

	/**
	 * Get the hyper-vertex by its numeric identifier.
	 * @param the numeric identifier.
	 */
	std::shared_ptr<HyperVertex>& hyperVertexById(unsigned int&);

	/**
	 * Get the hyper-edge by its numeric identifier.
	 * @param the numeric identifier.
	 */
	std::shared_ptr<HyperEdge>& hyperEdgeById(unsigned int&);

	/**
	 * Build the instance after reading.
	 */
	void flush();


  protected:
	/**
	 * List of hyper-vertices read.
	 */
	LibType::ListHyperVertex
	    _listHyperVertex;

	/**
	 * List of hyper-edges read.
	 */
	LibType::ListHyperEdge
	    _listHyperEdge;
};


#endif /* IO_INCLUDE_READERFILE_HH_ */

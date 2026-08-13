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

#ifndef IO_INCLUDE_READERFILE_HH_
#define IO_INCLUDE_READERFILE_HH_

#include "AbstractReader.hh"
#include <istream>


/**
 * @brief Implementation of the plain-text hypergraph instance reader.
 *
 * The expected format is a first line listing the hypervertex
 * identifiers, a second line listing the hyperedge identifiers, then
 * one `edge vertex` pair per line describing the incidence relation.
 */
class ReaderFile : public AbstractReader {
  public:
	/**
	 * @brief Construct a new ReaderFile object.
	 */
	ReaderFile();

	/**
	 * @brief Read the hypergraph instance.
	 * @param input stream.
	 */
	void readHypergraph(std::istream&);

	/**
	 * @brief Destructor.
	 */
	~ReaderFile() = default;


  protected:
	/**
	 * @brief Read the hypervertices of the instance.
	 * @param input stream.
	 */
	void readHypergraphHyperVertex(std::istream&);

	/**
	 * @brief Read the hyperedges of the instance.
	 * @param input stream.
	 */
	void readHypergraphHyperEdge(std::istream&);

	/**
	 * @brief Get the hypervertex by its numeric identifier.
	 * @param identifier.
	 * @return the hypervertex.
	 */
	std::shared_ptr<HyperVertex>& hyperVertexById(unsigned int&);

	/**
	 * @brief Get the hyperedge by its numeric identifier.
	 * @param identifier.
	 * @return the hyperedge.
	 */
	std::shared_ptr<HyperEdge>& hyperEdgeById(unsigned int&);

	/**
	 * @brief Build the instance after reading.
	 */
	void flush();


  protected:
	/**
	 * List of hypervertices read.
	 */
	LibType::ListHyperVertex
	    _listHyperVertex;

	/**
	 * List of hyperedges read.
	 */
	LibType::ListHyperEdge
	    _listHyperEdge;
};


#endif /* IO_INCLUDE_READERFILE_HH_ */

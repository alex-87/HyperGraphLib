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
#include <unordered_map>


/**
 * @brief Implementation of the plain-text hypergraph instance reader.
 *
 * The expected format is a first line listing the hypervertex
 * identifiers, a second line listing the hyperedge identifiers, then
 * one `edge vertex` pair per line describing the incidence relation.
 * File identifiers may be arbitrary: the hypergraph assigns its own dense
 * identifiers in reading order.
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
	 * @brief Get the hypervertex read with the given file identifier.
	 * @param identifier in the file.
	 * @return the hypervertex.
	 * @throw std::invalid_argument if the identifier was not declared.
	 */
	const std::shared_ptr<HyperVertex>& hyperVertexById(unsigned int) const;

	/**
	 * @brief Get the hyperedge read with the given file identifier.
	 * @param identifier in the file.
	 * @return the hyperedge.
	 * @throw std::invalid_argument if the identifier was not declared.
	 */
	const std::shared_ptr<HyperEdge>& hyperEdgeById(unsigned int) const;


  protected:
	/**
	 * Hypervertices read, by their identifier in the file.
	 */
	std::unordered_map<unsigned int, std::shared_ptr<HyperVertex>>
	    _hyperVertexByFileId;

	/**
	 * Hyperedges read, by their identifier in the file.
	 */
	std::unordered_map<unsigned int, std::shared_ptr<HyperEdge>>
	    _hyperEdgeByFileId;
};


#endif /* IO_INCLUDE_READERFILE_HH_ */

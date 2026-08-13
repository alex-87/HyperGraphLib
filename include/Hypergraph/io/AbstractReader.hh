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

#ifndef IO_INCLUDE_ABSTRACT_READER_HH_
#define IO_INCLUDE_ABSTRACT_READER_HH_

#include "../model/AbstractHypergraph.hh"
#include <memory>

/**
 * @brief Interface for the instance reader module.
 *
 * A reader builds a hypergraph from an input stream describing its
 * instance.
 */
class AbstractReader {
  public:
	/**
	 * @brief Construct a new AbstractReader object.
	 * @param hypergraph to build.
	 */
	AbstractReader(const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Read the instance and build the hypergraph.
	 * @param input stream.
	 */
	virtual void readHypergraph(std::istream&) = 0;

	/**
	 * @brief Get the hypergraph after construction.
	 * @return the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>&
	getHypergraph();

	/**
	 * @brief Destructor.
	 */
	virtual ~AbstractReader() = default;


  protected:
	/**
	 * @brief Read the hypervertices of the instance.
	 * @param input stream.
	 */
	virtual void readHypergraphHyperVertex(std::istream&) = 0;

	/**
	 * @brief Read the hyperedges of the instance.
	 * @param input stream.
	 */
	virtual void readHypergraphHyperEdge(std::istream&) = 0;


  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraph;
};


#endif /* IO_INCLUDE_ABSTRACT_READER_HH_ */

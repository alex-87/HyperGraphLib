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
 * Instance writer module interface.
 */
#ifndef IO_INCLUDE_ABSTRACT_WRITER_HH_
#define IO_INCLUDE_ABSTRACT_WRITER_HH_

#include "../model/AbstractHypergraph.hh"
#include <memory>

/**
 * Declaration of the instance writer module interface.
 */
class AbstractWriter {
  public:
	/**
	 * Constructor.
	 * @param shared pointer to the hypergraph.
	 */
	AbstractWriter(const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * Write the adjacency matrix to the given output stream.
	 * @param output stream.
	 */
	virtual void writeAdjacentMatrix(std::ostream&) const = 0;

	/**
	 * Write the hypergraph to the output stream.
	 * @param output stream.
	 */
	virtual void writeHypergraph(std::ostream&) const = 0;

	/**
	 * Virtual destructor.
	 */
	virtual ~AbstractWriter() = default;


  protected:
	/**
	 * Write the hyper-vertices to the output stream.
	 * @param output stream.
	 */
	virtual void writeHypergraphHyperVertex(std::ostream&) const = 0;

	/**
	 * Write the hyper-edges to the output stream.
	 * @param output stream.
	 */
	virtual void writeHypergraphHyperEdge(std::ostream&) const = 0;


  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraph;
};


#endif /* IO_INCLUDE_ABSTRACT_WRITER_HH_ */

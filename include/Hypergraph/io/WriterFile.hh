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

#ifndef IO_INCLUDE_WRITERFILE_HH_
#define IO_INCLUDE_WRITERFILE_HH_

#include "AbstractWriter.hh"

/**
 * @brief Implementation of the plain-text hypergraph instance writer.
 *
 * Writes the same format read by ReaderFile: a first line listing the
 * hypervertex identifiers, a second line listing the hyperedge
 * identifiers, then one `edge vertex` pair per line describing the
 * incidence relation.
 */
class WriterFile : public AbstractWriter {
  public:
	/**
	 * @brief Construct a new WriterFile object.
	 * @param hypergraph to write.
	 */
	WriterFile(const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Write the adjacency matrix to the output stream.
	 * @param output stream.
	 */
	void writeAdjacentMatrix(std::ostream&) const;

	/**
	 * @brief Write the hypergraph instance to the output stream.
	 * @param output stream.
	 */
	void writeHypergraph(std::ostream&) const;


  protected:
	/**
	 * @brief Write the hypervertices to the output stream.
	 * @param output stream.
	 */
	void writeHypergraphHyperVertex(std::ostream&) const;

	/**
	 * @brief Write the hyperedges to the output stream.
	 * @param output stream.
	 */
	void writeHypergraphHyperEdge(std::ostream&) const;


  protected:
};


#endif /* IO_INCLUDE_WRITERFILE_HH_ */

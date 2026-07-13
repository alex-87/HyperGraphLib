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
 * Result description structure. This object
 * is the representation of the result produced by any algorithm.
 */
#ifndef MODEL_INCLUDE_RESULT_STRUCTURE_HH_
#define MODEL_INCLUDE_RESULT_STRUCTURE_HH_

#include "AbstractHypergraph.hh"
#include <memory>

/**
 * Result description structure.
 */
class ResultStructure {
  public:
	/**
	 * Set a boolean result.
	 * @param the boolean result.
	 */
	void setBooleanResult(bool);

	/**
	 * Set a AbstractHypergraph result.
	 * @param the hypergraph used as the result.
	 */
	void setHypergraphResult(const std::shared_ptr<AbstractHypergraph>&);

  public:
	/**
	 * Read a boolean result.
	 * @return the result as a boolean value.
	 */
	bool getBooleanResult() const;

	/**
	 * Read a AbstractHypergraph result.
	 * @return the AbstractHypergraph result.
	 */
	std::shared_ptr<AbstractHypergraph> getHypergraphResult() const;

  protected:
	/**
	 * The boolean result value.
	 */
	bool _booleanResult;

	/**
	 * The hypergraph used as the result.
	 */
	std::shared_ptr<AbstractHypergraph> _hypergraphResult;
};


#endif /* MODEL_INCLUDE_RESULT_STRUCTURE_HH_ */

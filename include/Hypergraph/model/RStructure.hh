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
#ifndef MODEL_INCLUDE_RSTRUCTURE_HH_
#define MODEL_INCLUDE_RSTRUCTURE_HH_

#include "HypergrapheAbstrait.hh"
#include <memory>

/**
 * Result description structure.
 */
class RStructure {
  public:
	/**
	 * Set an integer result.
	 */
	void setIntegerResult();

	/**
	 * Set a boolean result.
	 * @param the boolean result.
	 */
	void setBooleanResult(bool);

	/**
	 * Set a HypergrapheAbstrait result.
	 * @param the hypergraph used as the result.
	 */
	void setHypergrapheResult(const std::shared_ptr<HypergrapheAbstrait>&);

  public:
	/**
	 * Read an integer result.
	 * @return the result as an integer.
	 */
	int getIntegerResult() const;

	/**
	 * Read a boolean result.
	 * @return the result as a boolean value.
	 */
	bool getBooleanResult() const;

	/**
	 * Read a HypergrapheAbstrait result.
	 * @return the HypergrapheAbstrait result.
	 */
	std::shared_ptr<HypergrapheAbstrait> getHypergrapheResult() const;

  protected:
	/**
	 * The integer result value.
	 */
	int _integerResult;

	/**
	 * The boolean result value.
	 */
	bool _booleanResult;

	/**
	 * The hypergraph used as the result.
	 */
	std::shared_ptr<HypergrapheAbstrait> _hypergraphResult;
};


#endif /* MODEL_INCLUDE_RSTRUCTURE_HH_ */

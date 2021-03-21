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
 * Result description structure
 */
#ifndef MODEL_INCLUDE_RSTRUCTURE_HH_
#define MODEL_INCLUDE_RSTRUCTURE_HH_

#include "HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Result description structure
 */
class RStructure {

public:

	/**
	 * Add integer result
	 */
	void setIntegerResult();

	/**
	 * Add boolean result
	 */
	void setBooleanResult(bool);

	/**
	 * Add HypergraphAbstrait result
	 */
	void setHypergrapheResult(const boost::shared_ptr<HypergrapheAbstrait>&);

public:

	/**
	 * Get integer result
	 * @return Integer result
	 */
	int getIntegerResult() const;

	/**
	 * Get boolean result
	 * @return Boolean result
	 */
	bool getBooleanResult() const;

	/**
	 * Get HypergraphAbstrait result
	 * @return HypergraphAbstrait result
	 */
	boost::shared_ptr<HypergrapheAbstrait> getHypergrapheResult() const;

protected:

	/**
	 * Integer result value
	 */
	int _integerResult;

	/**
	 * Boolean result value
	 */
	bool _booleanResult;

	/**
	 * HypergraphAbstrait result shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait> _hypergrapheResult;

};



#endif /* MODEL_INCLUDE_RSTRUCTURE_HH_ */


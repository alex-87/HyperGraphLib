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
 * Definition of the algorithm interface.
 */

#ifndef MODEL_INCLUDE_ABSTRACT_ALGORITHM_HH_
#define MODEL_INCLUDE_ABSTRACT_ALGORITHM_HH_

#include "ResultStructure.hh"

class AlgorithmEngine;

/**
 * Abstract class defining the mandatory methods of an algorithm.
 */
class AbstractAlgorithm {
  public:
	/**
	 * Get the result description structure.
	 * @return the result description structure.
	 */
	virtual ResultStructure getResult() const = 0;

	/**
	 * Abstract destructor.
	 */
	virtual ~AbstractAlgorithm() = default;


  protected:
	friend class AlgorithmEngine;

	/**
	 * Main entry point running the algorithm.
	 */
	virtual void run() = 0;
};


#endif /* MODEL_INCLUDE_ABSTRACT_ALGORITHM_HH_ */

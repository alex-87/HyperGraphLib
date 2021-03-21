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
 * Algorithmic engine
 */
#ifndef MODEL_INCLUDE_MOTORALGORITHM_HH_
#define MODEL_INCLUDE_MOTORALGORITHM_HH_

#include <boost/shared_ptr.hpp>

#include "AlgorithmeAbstrait.hh"

/**
 * Algorithmic engine
 */
class MotorAlgorithm {

public:

	/**
	 * Get the instance
	 * @return The instance
	 */
	static MotorAlgorithm& Instance();

	/**
	 * Set the algorithm
	 * @param The algorithm
	 */
	static void setAlgorithme(boost::shared_ptr<AlgorithmeAbstrait>&);

	/**
	 * Run the algorithm
	 */
	static void runAlgorithme();

	/**
	 * Check whether the engine is running
	 * @return True or False
	 */
	static bool isLock();

private:

	/**
	 * Lock the engine
	 */
	static void lock();

	/**
	 * Unlock the engine
	 */
	static void unlock();

private:

	/**
	 * Constructor
	 * @param The algorithm
	 */
	MotorAlgorithm(const MotorAlgorithm&);

	/**
	 * Constructor
	 * @param The algorithm
	 */
	MotorAlgorithm& operator= (const MotorAlgorithm&);

	/**
	 * Constructor
	 */
	MotorAlgorithm();

	/**
	 * Destructor
	 */
	~MotorAlgorithm();

private:

	/**
	 * Lock descriptor
	 */
	static bool               _lock;

	/**
	 * Singleton instance
	 */
	static MotorAlgorithm     _instance;

	/**
	 * The algorithm
	 */
	static boost::shared_ptr<AlgorithmeAbstrait> _algorithme;

};



#endif /* MODEL_INCLUDE_MOTORALGORITHM_HH_ */

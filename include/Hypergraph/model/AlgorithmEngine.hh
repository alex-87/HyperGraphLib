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
 * Algorithm engine. The engine is configured before running an algorithm
 * to act as a runner and avoid errors during concurrent execution.
 */
#ifndef MODEL_INCLUDE_AlgorithmEngine_HH_
#define MODEL_INCLUDE_AlgorithmEngine_HH_

#include <memory>

#include "AbstractAlgorithm.hh"

/**
 * Algorithm execution engine.
 */
class AlgorithmEngine {
  public:
	/**
	 * Get the engine instance.
	 * @return the engine instance.
	 */
	static AlgorithmEngine& getInstance();

	/**
	 * Set the algorithm to run.
	 * @param shared pointer to the algorithm.
	 */
	static void set(std::shared_ptr<AbstractAlgorithm>&);

	/**
	 * Execute the configured algorithm.
	 */
	static void run();

	/**
	 * Check whether the engine is locked.
	 * @return true if the runner is locked, false otherwise.
	 */
	static bool isLock();

  private:
	/**
	 * Lock the setters and runner.
	 */
	static void lock();

	/**
	 * Unlock the setters and the runner.
	 */
	static void unlock();

  private:
	/**
	 * Copy constructor.
	 */
	AlgorithmEngine(const AlgorithmEngine&);

	/**
	 * Constructor.
	 */
	AlgorithmEngine& operator=(const AlgorithmEngine&);

	/**
	 * Constructor.
	 */
	AlgorithmEngine();

	/**
	 * Destructor.
	 */
	~AlgorithmEngine() = default;

  private:
	/**
	 * Lock status flag.
	 */
	static bool _lock;

	/**
	 * Unique engine instance.
	 */
	static AlgorithmEngine _instance;

	/**
	 * Shared pointer to the algorithm.
	 */
	static std::shared_ptr<AbstractAlgorithm> _algorithme;
};


#endif /* MODEL_INCLUDE_AlgorithmEngine_HH_ */

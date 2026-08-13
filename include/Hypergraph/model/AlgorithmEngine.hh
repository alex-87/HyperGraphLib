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

#ifndef MODEL_INCLUDE_AlgorithmEngine_HH_
#define MODEL_INCLUDE_AlgorithmEngine_HH_

#include <memory>

#include "AbstractAlgorithm.hh"

/**
 * @brief Runner executing a configured algorithm.
 *
 * The engine is configured with an algorithm before it is run; it acts
 * as a singleton runner and guards against concurrent execution errors.
 */
class AlgorithmEngine {
  public:
	/**
	 * @brief Get the engine instance.
	 * @return the engine instance.
	 */
	static AlgorithmEngine& getInstance();

	/**
	 * @brief Set the algorithm to run.
	 * @param algorithm to run.
	 */
	static void set(std::shared_ptr<AbstractAlgorithm>&);

	/**
	 * @brief Run the configured algorithm.
	 */
	static void run();

	/**
	 * @brief Check whether the engine is locked.
	 * @return `true` if the runner is locked, `false` otherwise.
	 */
	static bool isLock();

  private:
	/**
	 * @brief Lock the setters and runner.
	 */
	static void lock();

	/**
	 * @brief Unlock the setters and the runner.
	 */
	static void unlock();

  private:
	/**
	 * @brief Copy constructor, disabled to enforce the singleton pattern.
	 */
	AlgorithmEngine(const AlgorithmEngine&);

	/**
	 * @brief Assignment operator, disabled to enforce the singleton pattern.
	 */
	AlgorithmEngine& operator=(const AlgorithmEngine&);

	/**
	 * @brief Construct a new AlgorithmEngine object.
	 */
	AlgorithmEngine();

	/**
	 * @brief Destructor.
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

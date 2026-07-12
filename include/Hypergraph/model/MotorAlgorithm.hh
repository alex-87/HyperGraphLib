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
 * Moteur des algorithmes. Avant de lancer un algorithme,
 * on configure le moteur, qui fait office de lanceur, afin
 * to avoid errors during parallelism.
 */
#ifndef MODEL_INCLUDE_MOTORALGORITHM_HH_
#define MODEL_INCLUDE_MOTORALGORITHM_HH_

#include <memory>

#include "AlgorithmeAbstrait.hh"

/**
 * Moteur algorithmique.
 */
class MotorAlgorithm {
  public:
	/**
	 * Get the engine instance.
	 * @return L'instance du moteur.
	 */
	static MotorAlgorithm& Instance();

	/**
	 * Set the algorithm to run.
	 * @param shared pointer to the algorithm.
	 */
	static void setAlgorithme(std::shared_ptr<AlgorithmeAbstrait>&);

	/**
	 * Lancer l'algorithme.
	 */
	static void runAlgorithme();

	/**
	 * Indicateur de bloquage du moteur.
	 * @return true if the runner is locked, false otherwise.
	 */
	static bool isLock();

  private:
	/**
	 * Bloquage des setters et du lanceur.
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
	MotorAlgorithm(const MotorAlgorithm&);

	/**
	 * Constructor.
	 */
	MotorAlgorithm& operator=(const MotorAlgorithm&);

	/**
	 * Constructor.
	 */
	MotorAlgorithm();

	/**
	 * Destructor.
	 */
	~MotorAlgorithm() = default;

  private:
	/**
	 * Descripteur du statut bloquant.
	 */
	static bool _lock;

	/**
	 * Instance unique du moteur.
	 */
	static MotorAlgorithm _instance;

	/**
	 * Shared pointer to the algorithm.
	 */
	static std::shared_ptr<AlgorithmeAbstrait> _algorithm;

};


#endif /* MODEL_INCLUDE_MOTORALGORITHM_HH_ */

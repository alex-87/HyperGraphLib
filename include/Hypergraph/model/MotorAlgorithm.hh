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
 * d'éviter les erreurs lors du paraléllisme.
 */
#ifndef MODEL_INCLUDE_MOTORALGORITHM_HH_
#define MODEL_INCLUDE_MOTORALGORITHM_HH_

#include <boost/shared_ptr.hpp>

#include "AlgorithmeAbstrait.hh"

/**
 * Moteur algorithmique.
 */
class MotorAlgorithm {

public:

	/**
	 * Obtenir l'instance du moteur.
	 * @return L'instance du moteur.
	 */
	static MotorAlgorithm& Instance();

	/**
	 * Insérer l'algorithme à lancer.
	 * @param Pointeur partagé sur l'algorithme.
	 */
	static void setAlgorithme(boost::shared_ptr<AlgorithmeAbstrait>&);

	/**
	 * Lancer l'algorithme.
	 */
	static void runAlgorithme();

	/**
	 * Indicateur de bloquage du moteur.
	 * @return True si le lanceur est bloqué, False sinon.
	 */
	static bool isLock();

private:

	/**
	 * Bloquage des setters et du lanceur.
	 */
	static void lock();

	/**
	 * Débloquage des setters et du lanceur.
	 */
	static void unlock();

private:

	/**
	 * Constructeur (copie).
	 */
	MotorAlgorithm(const MotorAlgorithm&);

	/**
	 * Constructeur.
	 */
	MotorAlgorithm& operator= (const MotorAlgorithm&);

	/**
	 * Constructeur.
	 */
	MotorAlgorithm();

	/**
	 * Déstructeur.
	 */
	~MotorAlgorithm();

private:

	/**
	 * Descripteur du statut bloquant.
	 */
	static bool               _lock;

	/**
	 * Instance unique du moteur.
	 */
	static MotorAlgorithm     _instance;

	/**
	 * Pointeur partagé de l'algorithme.
	 */
	static boost::shared_ptr<AlgorithmeAbstrait> _algorithme;

};



#endif /* MODEL_INCLUDE_MOTORALGORITHM_HH_ */

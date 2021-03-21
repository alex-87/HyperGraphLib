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
 * Définition de l'interface d'un algorithme.
 */


#ifndef MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_
#define MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_

#include "RStructure.hh"

class MotorAlgorithm;

/**
 * Classe abstraite définissant les méthodes obligatoires d'un algorithme.
 */
class AlgorithmeAbstrait {

public:

	/**
	 * Obtenir la structure de description du résultat.
	 * @return La structure de description du résultat.
	 */
	virtual RStructure getResult() const = 0;

	/**
	 * Destructeur abstrait.
	 */
	virtual ~AlgorithmeAbstrait();


protected:

	friend class MotorAlgorithm;

	/**
	 * Fonction princiale de lancement de l'algorithme.
	 */
	virtual void runAlgorithme() = 0;

};


#endif /* MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_ */

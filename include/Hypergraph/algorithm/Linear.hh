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
 * Définition de la classe de l'algorithme linear sur l'hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_LINEAR_HH_
#define ALGORITHM_INCLUDE_LINEAR_HH_

#include "../model/AlgorithmeAbstrait.hh"

/**
 * Algorithme linear sur l'hypergraphe.
 */
class Linear : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur
	 * @param Pointeur partagé sur l'hypergraphe.
	 */
	Linear(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résutats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Linear();


protected:

	/**
	 * Lancement de l'algorithme.
	 */
	void runAlgorithme();


protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Structure des résutats.
	 */
	RStructure _result;

};



#endif /* ALGORITHM_INCLUDE_LINEAR_HH_ */

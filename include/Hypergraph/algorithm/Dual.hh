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
 * Définition de l'algorithme du Dual de l'hypergraphe.
 */

#ifndef ALGORITHM_INCLUDE_DUAL_HH_
#define ALGORITHM_INCLUDE_DUAL_HH_

#include <boost/shared_ptr.hpp>
#include "../model/HypergrapheAbstrait.hh"
#include "../model/AlgorithmeAbstrait.hh"

/**
 * Algorithme du Dual de l'hypergraphe.
 */
class Dual : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	Dual(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résultats.
	 * @return La structure des résultats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Dual();

protected:

	/**
	 * Lancement de l'algorithme
	 */
	void runAlgorithme();

protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Pointeur partagé vers le dual de l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrDualHypergraphe;

	/**
	 * Structure de résultat.
	 */
	RStructure _result;

};



#endif

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
 * Structure de description du résultat. Cet objet
 * est la représentation du résultat produit par tout algorithme.
 */
#ifndef MODEL_INCLUDE_RSTRUCTURE_HH_
#define MODEL_INCLUDE_RSTRUCTURE_HH_

#include "HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Structure de description du résultat.
 */
class RStructure {

public:

	/**
	 * Ajouter un résultat entier.
	 */
	void setIntegerResult();

	/**
	 * Ajouter un résultat booléen.
	 * @param Le résultat booléen.
	 */
	void setBooleanResult(bool);

	/**
	 * Ajouter un résultat de type HypergrapheAbstrait.
	 * @param L'hypergraphe faisant office de résultat.
	 */
	void setHypergrapheResult(const boost::shared_ptr<HypergrapheAbstrait>&);

public:

	/**
	 * Lire un résultat entier.
	 * @return Le résutat en tant que nombre entier.
	 */
	int getIntegerResult() const;

	/**
	 * Lire un résutat booléen.
	 * @return Le résultat en tant que valeur booléenne.
	 */
	bool getBooleanResult() const;

	/**
	 * Lire un résultat de typ HypergrapheAbstrait
	 * @return Le résultat de type HypergrapheAbstrait
	 */
	boost::shared_ptr<HypergrapheAbstrait> getHypergrapheResult() const;

protected:

	/**
	 * La valeur du résultat entier.
	 */
	int _integerResult;

	/**
	 * La valeur du résultat booléen.
	 */
	bool _booleanResult;

	/**
	 * L'hypergraphe faisant office de résultat.
	 */
	boost::shared_ptr<HypergrapheAbstrait> _hypergrapheResult;

};



#endif /* MODEL_INCLUDE_RSTRUCTURE_HH_ */


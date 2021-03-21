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
 * Définition de la classe de l'algorithme simple sur l'hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_SIMPLE_HH_
#define ALGORITHM_INCLUDE_SIMPLE_HH_

#include <boost/shared_ptr.hpp>
#include "../model/HypergrapheAbstrait.hh"
#include "../model/Hypergraphe.hh"
#include "../model/HyperVertex.hh"
#include "../model/HyperEdge.hh"
#include "../model/AlgorithmeAbstrait.hh"
#include "../model/RStructure.hh"
#include "Linear.hh"

/**
 * Algorithme simple sur l'hypergraphe.
 */
class Simple : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur
	 * @param Pointeur partagé sur l'hypergraphe.
	 */
	Simple(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résultats.
	 * @return La structure des résultats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Simple();


protected:

	friend class Linear;

	/**
	 * Lancement de l'algorithme.
	 */
	void runAlgorithme();

	/**
	 * Vérification de l'inclusion entre hyper-arête via les vertex.
	 * @param Première liste.
	 * @param Seconde liste.
	 * @return True si c'est le cas, False sinon.
	 */
	bool subsetVertexList(const LibType::ListHyperVertex&, const LibType::ListHyperVertex&) const;

	/**
	 * Vérifie si un hyper-vertex est contenu dans la liste.
	 * @param Liste des hyper-vertex.
	 * @param L'hyer-vertex.
	 * @return True si c'est le cas, False sinon.
	 */
	bool contains(const LibType::ListHyperVertex&, const boost::shared_ptr<HyperVertex>&) const;


protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Structure des résultats.
	 */
	RStructure _result;


};



#endif /* ALGORITHM_INCLUDE_SIMPLE_HH_ */

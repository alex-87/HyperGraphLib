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
 * Définition de l'algorithme de génération des statistiques de l'hypergraphe.
 */

#ifndef ALGORITHM_INCLUDE_HPGSTAT
#define ALGORITHM_INCLUDE_HPGSTAT

#include <boost/shared_ptr.hpp>
#include "../model/HypergrapheAbstrait.hh"
#include "../model/Hypergraphe.hh"
#include "../model/HyperVertex.hh"
#include "../model/HyperEdge.hh"
#include "../model/AlgorithmeAbstrait.hh"
#include "../model/RStructure.hh"


/**
 * Algorithme de génération des statistiques de l'hypergraphe.
 */
class HyperGraphStat : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	HyperGraphStat(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résultats - inutilisé ici.
	 * @return La structure des résultats - inutilisé ici.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~HyperGraphStat();


public:

	/**
	 * Obtenir le nombre d'hyper-arêtes.
	 */
	unsigned int getNbrHyperEdge() const;

	/**
	 * Obtenir le nombre d'hyper-vertex.
	 */
	unsigned int getNbrHyperVertex() const;

	/**
	 * Obtenir le nombre de connexions vertex-arêtes.
	 */
	unsigned int getNbrLinks() const;

	/**
	 * Obtenir le rang de l'hypergraphe.
	 */
	unsigned int getRang() const;

	/**
	 * Obtenir le co-rang de l'hypergraphe.
	 */
	unsigned int getCoRang() const;

protected:

	/**
	 * Lancment de l'algorithme.
	 */
	void runAlgorithme();

protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * La structure des résultats - inutilisée ici.
	 */
	RStructure _result;

	/**
	 * Le nombre d'hyper-arêtes.
	 */
	unsigned int _nhEdge;

	/**
	 * Le nombre d'hyper-vertex.
	 */
	unsigned int _nhVertex;

	/**
	 * Le nombre de connexions vertex-arêtes
	 */
	unsigned int _nhLink;

	/**
	 * Le rang de l'hypergraphe
	 */
	unsigned int _rang;

	/**
	 * Le co-rang de l'hypergraphe
	 */
	unsigned int _coRang;

};


#endif

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
 * Définition de l'algorithme vérifiant la propriété de Helly dans l'hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_HELLY_HH_
#define ALGORITHM_INCLUDE_HELLY_HH_

#include "../model/AlgorithmeAbstrait.hh"
#include "../model/RStructure.hh"

/**
 * Algorithme vérifiant la propriété de Helly dans l'hypergraphe.
 */
class Helly : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	Helly(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résultats.
	 * @return La structure des résultats.
	 */
	RStructure getResult() const;

	/**
	 * Déstructeur.
	 */
	~Helly();

protected:

	/**
	 * Lancement de l'algorithme.
	 */
	void runAlgorithme();

	/**
	 * Construit la liste des hyper-arête contienant les deux hyper-vertex.
	 * @param Le premier hyper-vertex.
	 * @param Le second hyper-vertex.
	 * @return La liste des hyper-rêtes contennt les deux hyper-vertex.
	 */
	LibType::ListHyperEdge& allContainXY(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperVertex>&);

	/**
	 * Vérifie si l'intersection entre les éléments de la liste n'est pas vide.
	 * @param La liste des hyper-arêtes.
	 * @return True s'il n'y a aucune intersection vide, False sinon.
	 */
	bool nonEmptyIntersection(LibType::ListHyperEdge&);

	/**
	 * Vérifie si l'intersection entre ces deux hyper-arêtes n'est pas vide.
	 * @param Première hyper-arête.
	 * @param Seconde hyper-arête.
	 * @return True s'il y a intersection non-vide, False sinon.
	 */
	bool nonEmptyBetween(boost::shared_ptr<HyperEdge>&, boost::shared_ptr<HyperEdge>&);

	/**
	 * Vérifie si les deux hyper-vertex sont voisins.
	 * @param Premier hyper-vertex.
	 * @param Second hyper-vertex
	 * @return True s'il sont voisin, False sinon.
	 */
	bool voisin(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperVertex>&);

	/**
	 * Concaténation de deux listes d'hyper-arêtes.
	 * @param Destination.
	 * @param Source à concaténer.
	 */
	void concatenate(LibType::ListHyperEdge&, LibType::ListHyperEdge&);


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



#endif

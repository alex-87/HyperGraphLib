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
 * Modélisation de l'hyper-vertex.
 */

#ifndef HYPER_VERTEX_HH
#define HYPER_VERTEX_HH

#include <boost/shared_ptr.hpp>

#include "LibType.hh"
#include "HypergrapheAbstrait.hh"

/**
 * Déclaration de la classe de l'hyper-vertex.
 */
class HyperVertex {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe auquel appartient l'hyper-vertex.
	 * @param L'identifiant numérique de l'hyper-vertex.
	 */
	HyperVertex(const boost::shared_ptr<HypergrapheAbstrait>&, unsigned int& identifier);

	/**
	 * Ajouter une hyper-arête à l'hyper-vertex.
	 * @param L'hyper-arête à ajouter.
	 */
	void addHyperEdge(boost::shared_ptr<HyperEdge>&);

	/**
	 * Obtenir le nombre d'hyper-arêtes dans lequel l'hyper-vertex est inclus.
	 * @return Le nombre d'hyper-arêtes dans lequel l'hyper-vertex est inclus.
	 */
	const unsigned int getVertexDegree() const;

	/**
	 * Vérifier si l'hyper-arête contient cet hyer-vertex.
	 * @param L'hyper-arête
	 * @return True si l'hyper-vertex est inclus dans l'hyper-arête.
	 */
	bool containEdge(boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Obtenir l'identifiant numérique de l'hyper-vertex.
	 * @return L'identifiant numérique de l'hyper-vertex.
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * Surcharge de l'opérateur, dont l'expression est basé sur l'identifiant numérique.
	 */
	bool operator==(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Surcharge de l'opérateur, dont l'expression est basé sur l'identifiant numérique.
	 */
	bool operator<(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Surcharge de l'opérateur, dont l'expression est basé sur l'identifiant numérique.
	 */
	bool operator>(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Obtenir la liste des hyper-arêtes contenant l'hyper-vertex.
	 * @return La liste des hyper-arêtes contenant l'hyper-vertex.
	 */
	const LibType::ListHyperEdge& getHyperEdgeList() const;


protected:

	/**
	 * Pointeur partagé sur l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergraphe;

	/**
	 * Identifiant numérique.
	 */
	unsigned int _identifier;

	/**
	 * Liste des hyper-arêtes contenant l'hyper-vertex.
	 */
	LibType::ListHyperEdge
	_listHyperEdge;

};

#endif

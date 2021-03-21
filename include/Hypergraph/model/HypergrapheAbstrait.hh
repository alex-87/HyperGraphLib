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
 * Déclaraion de l'interface standard d'un hypergraphe
 */

#ifndef HYPERGRAPHE_HH_
#define HYPERGRAPHE_HH_

#include "AdjacentMatrix.hh"

/**
 * Définition de l'interface de l'hypergraphe.
 */
class HypergrapheAbstrait {

public:

	/**
	 * Constructeur.
	 */
	HypergrapheAbstrait();

	/**
	 * Ajouter un hyper-vertex à l'hypergraphe.
	 * @param L'hyper-vertex à ajouter.
	 */
	virtual void addHyperVertex(const boost::shared_ptr<HyperVertex>&) = 0;

	/**
	 * Ajouter une hyper-arête à l'hypergraphe.
	 * @param L'hyper-arête à ajouter.
	 */
	virtual void addHyperEdge(const boost::shared_ptr<HyperEdge>&)     = 0;

	/**
	 * Obtenir la matrice d'adjacence de l'hypergraphe.
	 * @return La matrice d'adjacence.
	 */
	AdjacentMatrix& getAdjacentMatrix();

	/**
	 * Obtenir la table d'index des hyper-vertex.
	 * @return la table d'index des hyper-vertex.
	 */
	LibType::IndexerHyperVertex& getIndexHyperVertex();

	/**
	 * Obtenir la table d'index des hyper-arêtes.
	 * @return la table d'index des hyper-arêtes.
	 */
	LibType::IndexerHyperEdge& getIndexHyperEdge();

	/**
	 * Obtenir un hyper-vertex à l'aide de son identifiant.
	 * @return L'hyper-vertex. Comportement indéfini sinon.
	 */
	virtual boost::shared_ptr<HyperVertex>& getHyperVertexById(const unsigned int&) = 0;

	/**
	 * Obtenir une hyper-arête à l'aide de son identifiant.
	 * @return L'hyper-arête. Comportement indéfini sinon.
	 */
	virtual boost::shared_ptr<HyperEdge>& getHyperEdgeById(const unsigned int&) = 0;

	/**
	 * Obtenir la liste des hyper-vertex de l'hypergraphe.
	 * @return la liste des hyper-vertex de l'hypergraphe.
	 */
	LibType::ListHyperVertex& getHyperVertexList();


	/**
	 * Obtenir la liste des hyper-arêtes de l'hypergraphe.
	 * @return la liste des hyper-arêtes de l'hypergraphe.
	 */
	LibType::ListHyperEdge&   getHyperEdgeList();

	/**
	 * Check whether the hyper-vertex is contained in the hyper-edge
	 * @param Hyper-vertex
	 * @param Hyper-edge
	 * @return True or False
	 */
	bool isHyperVertexInHyperEdge(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Construction interne de l'hypergraphe après fabrication.
	 */
	virtual void flush() = 0;

	/**
	 * Destructeur virtuel.
	 */
	virtual ~HypergrapheAbstrait();

protected:

	/**
	 * La table des hyper-vertex (identifiant, hyper-vertex).
	 */
	LibType::IndexerHyperVertex _indexHyperVertex;

	/**
	 * La table des hyper-arêtes (identifiant, hyper-arête).
	 */
	LibType::IndexerHyperEdge   _indexHyperEdge;

	/**
	 * Liste des hyper-vertex.
	 */
	LibType::ListHyperVertex    _listHyperVertex;

	/**
	 * Liste des hyper-arêtes.
	 */
	LibType::ListHyperEdge      _listHyperEdge;

	/**
	 * La table des hyper-arêtes (hyper-vertex, identifiant).
	 */
	LibType::HyperVertexIndexer _hyperVertexIndexer;

	/**
	 * La table des hyper-arêtes (hyper-arête, identifiant).
	 */
	LibType::HyperEdgeIndexer   _hyperEdgeIndexer;

	/**
	 * La matrice d'adjacence.
	 */
	AdjacentMatrix 				_adjacentMatrix;

};

#endif

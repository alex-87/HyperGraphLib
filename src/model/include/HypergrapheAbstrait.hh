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
	virtual void addHyperVertex(const HyperVertex&) = 0;

	/**
	 * Ajouter une hyper-arête à l'hypergraphe.
	 * @param L'hyper-arête à ajouter.
	 */
	virtual void addHyperEdge(const HyperEdge&)     = 0;

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
	virtual HyperVertex& getHyperVertexById(const unsigned int&) = 0;

	/**
	 * Obtenir une hyper-arête à l'aide de son identifiant.
	 * @return L'hyper-arête. Comportement indéfini sinon.
	 */
	virtual HyperEdge& getHyperEdgeById(const unsigned int&) = 0;

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

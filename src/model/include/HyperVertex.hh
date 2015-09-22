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
	void addHyperEdge(HyperEdge&);

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
	bool containEdge(HyperEdge&) const;

	/**
	 * Obtenir l'identifiant numérique de l'hyper-vertex.
	 * @return L'identifiant numérique de l'hyper-vertex.
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * Surcharge de l'opérateur, dont l'expression est basé sur l'identifiant numérique.
	 */
	bool operator==(const HyperVertex&) const;

	/**
	 * Surcharge de l'opérateur, dont l'expression est basé sur l'identifiant numérique.
	 */
	bool operator<(const HyperVertex&) const;

	/**
	 * Surcharge de l'opérateur, dont l'expression est basé sur l'identifiant numérique.
	 */
	bool operator>(const HyperVertex&) const;

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

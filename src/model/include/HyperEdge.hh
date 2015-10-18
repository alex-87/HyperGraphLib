/**
 * Modélisation d'une hyper-arête.
 */
#ifndef _HYPEREDGE_HH
#define _HYPEREDGE_HH

#include <boost/shared_ptr.hpp>

#include "LibType.hh"
#include "HypergrapheAbstrait.hh"

/**
 * Définition de l'hyper-arête.
 */
class HyperEdge {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 * @param Identifiant numérique de l'hyper-arête.
	 */
	HyperEdge(const boost::shared_ptr<HypergrapheAbstrait>&, unsigned int& identifier);

	/**
	 * Ajouter un hyper-vertex dans l'hyper-arête.
	 * @param L'hyper-vertex à ajouter.
	 */
	void addHyperVertex(boost::shared_ptr<HyperVertex>&);

	/**
	 * Affectation de la liste des hyper-vertex contenu dans l'hyper-arête.
	 * @param Liste des hyper-vertex.
	 */
	void setHyperVertexList(LibType::ListHyperVertex&);

	/**
	 * Obtenir la liste des hyper-vertex contenu dans l'hyper-arête.
	 * @return La liste des hyper-vertex.
	 */
	LibType::ListHyperVertex& getHyperVertexList();

	/**
	 * Obtenir l'effectif de l'hyper-arête.
	 * @return L'effectif.
	 */
	const unsigned int getEffectif() const;

	/**
	 * Obtenir l'identifiant numérique de l'hyper-arête.
	 * @return L'identifiant de l'hyper-arête.
	 */
	const unsigned int& getIdentifier() const;

	/**
	 * Vérifie l'appartenance d'un hyper-vertex dans l'hyper-arête.
	 * @param Le vertex
	 * @return True si l'hyper-vertex est présent dans l'hyper-arête, False sinon.
	 */
	bool containVertex(boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Surcharge de l'opérateur, afin de vérifier l'expression à l'aide de l'identifiant numérique.
	 */
	bool operator==(const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Surcharge de l'opérateur, afin de vérifier l'expression à l'aide de l'identifiant numérique.
	 */
	bool operator<(const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Surcharge de l'opérateur, afin de vérifier l'expression à l'aide de l'identifiant numérique.
	 */
	bool operator>(const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Obtenir la liste des hyper-vertex contenu dans l'hyper-arête.
	 * @return La liste des hyper-vertex.
	 */
	const LibType::ListHyperVertex& getHyperVertexList() const;

protected:

	/**
	 * Pointeur partagé sur l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergraphe;

	/**
	 * L'identifiant numérique.
	 */
	unsigned int _identifier;

	/**
	 * Liste des hyper-vertex.
	 */
	LibType::ListHyperVertex
	_listHyperVertex;

};

#endif

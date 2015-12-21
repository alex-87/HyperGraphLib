/**
 * Définition de l'algorithme de génération des statistiques de l'hypergraphe.
 */

#ifndef ALGORITHM_INCLUDE_HPGSTAT
#define ALGORITHM_INCLUDE_HPGSTAT

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"


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

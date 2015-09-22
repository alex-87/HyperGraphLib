/**
 * Définition de l'algorithme vérifiant la propriété de Helly dans l'hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_HELLY_HH_
#define ALGORITHM_INCLUDE_HELLY_HH_

#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"

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
	LibType::ListHyperEdge& allContainXY(HyperVertex&, HyperVertex&);

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
	bool nonEmptyBetween(HyperEdge&, HyperEdge&);

	/**
	 * Vérifie si les deux hyper-vertex sont voisins.
	 * @param Premier hyper-vertex.
	 * @param Second hyper-vertex
	 * @return True s'il sont voisin, False sinon.
	 */
	bool voisin(HyperVertex&, HyperVertex&);

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

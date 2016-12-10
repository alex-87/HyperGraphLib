/**
 * Définition de l'algorithme décidant de l'ensemble des chemins dans un hypergraphe
 * reliant un Vertex e1 à un Vertex e2.
 */

#ifndef ALGORITHM_INCLUDE_PATH_HH_
#define ALGORITHM_INCLUDE_PATH_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"

class Path : public AlgorithmeAbstrait {

public:

	/*
	 * Constructeur.
	 * @param boost::shared_ptr<HypergrapheAbstrait> Pointeur partagé vers l'hypergraphe.
	 */
	Path(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure de résultats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Path();

protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Structure de résultat.
	 */
	RStructurePath _result;
};


#endif /* SRC_ALGORITHM_INCLUDE_PATH_HH_ */

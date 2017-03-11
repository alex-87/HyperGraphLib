/**
 * Définition de l'algorithme du Dual de l'hypergraphe.
 */

#ifndef ALGORITHM_INCLUDE_DUAL_HH_
#define ALGORITHM_INCLUDE_DUAL_HH_

#include <boost/shared_ptr.hpp>
#include "../model/HypergrapheAbstrait.hh"
#include "../model/AlgorithmeAbstrait.hh"

/**
 * Algorithme du Dual de l'hypergraphe.
 */
class Dual : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	Dual(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résultats.
	 * @return La structure des résultats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Dual();

protected:

	/**
	 * Lancement de l'algorithme
	 */
	void runAlgorithme();

protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Pointeur partagé vers le dual de l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrDualHypergraphe;

	/**
	 * Structure de résultat.
	 */
	RStructure _result;

};



#endif

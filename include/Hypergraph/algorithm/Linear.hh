/**
 * Définition de la classe de l'algorithme linear sur l'hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_LINEAR_HH_
#define ALGORITHM_INCLUDE_LINEAR_HH_

#include "../model/AlgorithmeAbstrait.hh"

/**
 * Algorithme linear sur l'hypergraphe.
 */
class Linear : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur
	 * @param Pointeur partagé sur l'hypergraphe.
	 */
	Linear(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résutats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Linear();


protected:

	/**
	 * Lancement de l'algorithme.
	 */
	void runAlgorithme();


protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Structure des résutats.
	 */
	RStructure _result;

};



#endif /* ALGORITHM_INCLUDE_LINEAR_HH_ */

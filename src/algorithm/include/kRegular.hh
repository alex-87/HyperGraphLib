/**
 * Définition de la classe de l'algorithme k-regular sur l'hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_KREGULAR_HH_
#define ALGORITHM_INCLUDE_KREGULAR_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"

/**
 * Algorithme k-regular sur l'hypergraphe.
 */
class kRegular : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	kRegular(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résultats.
	 * @return La structure des résultats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~kRegular();

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
	 * La structure des résultats.
	 */
	RStructure _result;

};


#endif /* ALGORITHM_INCLUDE_KREGULAR_HH_ */

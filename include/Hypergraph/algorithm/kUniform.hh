/**
 * Définition de la classe de l'algorithme k-uniforme sur l'hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_KUNIFORM_HH_
#define ALGORITHM_INCLUDE_KUNIFORM_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"

/**
 * Algorithme k-uniforme sur l'hypergraphe.
 */
class kUniform : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur
	 * @param Pointeur partagé sur l'hypergraphe.
	 * @param Valeur de k.
	 */
	kUniform(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait, const unsigned int&);

	/**
	 * Obtenir la structure des résultats.
	 * @return La structure des résultats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~kUniform();


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
	 * Valeur de k.
	 */
	unsigned int _k;

	/**
	 * Structure des résultats.
	 */
	RStructure _result;

};



#endif /* ALGORITHM_INCLUDE_KUNIFORM_HH_ */

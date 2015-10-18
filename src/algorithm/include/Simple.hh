/**
 * Définition de la classe de l'algorithme simple sur l'hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_SIMPLE_HH_
#define ALGORITHM_INCLUDE_SIMPLE_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"
#include "Linear.hh"

/**
 * Algorithme simple sur l'hypergraphe.
 */
class Simple : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur
	 * @param Pointeur partagé sur l'hypergraphe.
	 */
	Simple(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure des résultats.
	 * @return La structure des résultats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Simple();


protected:

	friend class Linear;

	/**
	 * Lancement de l'algorithme.
	 */
	void runAlgorithme();

	/**
	 * Vérification de l'inclusion entre hyper-arête via les vertex.
	 * @param Première liste.
	 * @param Seconde liste.
	 * @return True si c'est le cas, False sinon.
	 */
	bool subsetVertexList(const LibType::ListHyperVertex&, const LibType::ListHyperVertex&) const;

	/**
	 * Vérifie si un hyper-vertex est contenu dans la liste.
	 * @param Liste des hyper-vertex.
	 * @param L'hyer-vertex.
	 * @return True si c'est le cas, False sinon.
	 */
	bool contains(const LibType::ListHyperVertex&, const boost::shared_ptr<HyperVertex>&) const;


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



#endif /* ALGORITHM_INCLUDE_SIMPLE_HH_ */

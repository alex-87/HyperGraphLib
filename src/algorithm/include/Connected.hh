/**
 * Définition de l'algorithme décidant la connexité d'un hypergraphe.
 */
#ifndef ALGORITHM_INCLUDE_CONNECTED_HH_
#define ALGORITHM_INCLUDE_CONNECTED_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"

#include <boost/shared_ptr.hpp>
#include <stack>
#include <vector>

/**
 * Algorithme décidant la connexité d'un hypergraphe.
 */
class Connected : public AlgorithmeAbstrait {

public:

	/**
	 * Constructeur.
	 * @param boost::shared_ptr<HypergrapheAbstrait> Pointeur partagé vers l'hypergraphe.
	 */
	Connected(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Obtenir la structure de résultats.
	 */
	RStructure getResult() const;

	/**
	 * Destructeur.
	 */
	~Connected();


protected:

	/**
	 * Fonction de lancement de l'algorithme.
	 */
	void runAlgorithme();

	/**
	 * Exploration verticale d'un chemin de la matrice.
	 * @param Vecteur des visités.
	 * @param Pile des "à visiter".
	 * @param Identifiant de la ligne.
	 */
	void exploreVertical(std::vector<unsigned int>&, std::stack<unsigned int>&, unsigned int);

	/**
	 * Exploration horizontale d'un chemin dans la matrice.
	 * @param Vecteur des visités.
	 * @param Pile des "à visiter".
	 * @param Identifiant de la colonne.
	 */
	void exploreHorizontal(std::vector<unsigned int>&, std::stack<unsigned int>&, unsigned int);

	/**
	 * Vérifier si un hyper-vertex a déjà été visité.
	 * @param Vecteur des hyper-vertex visités.
	 * @param Identifiant à vérifier.
	 * @return True si déjà visité, False sinon.
	 */
	bool isVertexVisited(std::vector<unsigned int>&, unsigned int) const;

	/**
	 * Vérifier si une hyper-arête a déjà été visitée.
	 * @param Vecteur des hyper-arêtes visités.
	 * @param Identifiant à vérifier.
	 * @return True si déjà visité, False sinon.
	 */
	bool isEdgeVisited(std::vector<unsigned int>&, unsigned int) const;

/*

	bool isPath(HyperVertex&, HyperVertex&) const;

	bool isVisited(std::vector<HyperEdge>&, const HyperEdge&) const;

*/


protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Structure de résultat.
	 */
	RStructure _result;

};


#endif /* ALGORITHM_INCLUDE_CONNECTED_HH_ */

/**
 * Classe modélisant un hypergraphe.
 */
#ifndef MODEL_INCLUDE_HYPERGRAPHE_HH_
#define MODEL_INCLUDE_HYPERGRAPHE_HH_

#include "HypergrapheAbstrait.hh"

/**
 * Modélisation de l'hypergraphe.
 */
class Hypergraphe : public HypergrapheAbstrait {

public:

	/**
	 * Constructeur par défaut.
	 */
	Hypergraphe();

	/**
	 * Ajouter un hyper-vertex à l'hypergraphe.
	 * @param L'hyper-vertex à ajouter.
	 */
	void addHyperVertex(const HyperVertex&);

	/**
	 * Ajouter une hyper-arête à l'hypergraphe.
	 * @param L'hyper-arête à ajouter.
	 */
	void addHyperEdge(const HyperEdge&);

	/**
	 * Obtenir un hyper-vertex à l'aide de son identifiant.
	 * @param L'identifiant de l'hyper-vertex à obtenir.
	 */
	HyperVertex& getHyperVertexById(const unsigned int&);

	/**
	 * Obtenir une hyper-arête à l'aide de son identifiant.
	 * @param L'identifiant de l'hyper-arête à obtenir.
	 */
	HyperEdge& getHyperEdgeById(const unsigned int&);

	/**
	 * Construction de l'hypergraphe, notamment de sa matrice d'adjacence.
	 */
	void flush();

	/**
	 * Destructeur.
	 */
	~Hypergraphe();

protected:

};



#endif /* MODEL_INCLUDE_HYPERGRAPHE_HH_ */

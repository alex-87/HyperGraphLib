/**
 * Définition de l'algorithme décidant de l'ensemble des chemins dans un hypergraphe
 * reliant un Vertex e1 à un Vertex e2.
 */

#ifndef ALGORITHM_INCLUDE_PATH_HH_
#define ALGORITHM_INCLUDE_PATH_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructurePath.hh"

class Path : public AlgorithmeAbstrait {

public:

	/*
	 * Constructeur.
	 * @param boost::shared_ptr<HypergrapheAbstrait> Pointeur partagé vers l'hypergraphe.
	 */
	Path(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Configurer les vertex à utiliser pour lister les chemins
	 */
	void setHyperVertex(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperVertex>&);

	/**
	 * Obtenir la structure de résultats.
	 */
	RStructure getResult() const;

	/**
	 * Obtenir la structure de résultats.
	 */
	RStructurePath getPathResult() const;

	/**
	 * Fixer la limite du nombre de chemins. Par défaut 0, non-définit.
	 */
	void setLimit(unsigned int);

	/**
	 * Lire la valeur limite.
	 */
	unsigned int getLimit() const;

	/**
	 * Destructeur.
	 */
	~Path();


protected:

	/**
	 * Lancement de l'algorithme
	 */
	void runAlgorithme();

	/**
	 * Vérifie si l'HyperVertex est contenu dans la liste
	 */
	bool vertexContained(LibType::ListHyperVertex&, boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Ajoute les HyperVertex d'un HyperEdge dans la liste mentionnée.
	 */
	void addVertexList(LibType::ListHyperVertex&, LibType::ListHyperVertex&, const boost::shared_ptr<HyperEdge>&) const;


protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Vertex source
	 */
	boost::shared_ptr<HyperVertex> _source;

	/**
	 * Vertex destination
	 */
	boost::shared_ptr<HyperVertex> _destination;

	/**
	 * Structure de résultat.
	 */
	RStructurePath _result;

	/**
	 * Valeur limite.
	 */
	unsigned int _limite;
};


#endif /* SRC_ALGORITHM_INCLUDE_PATH_HH_ */

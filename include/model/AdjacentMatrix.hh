/*
 * Modélisation de la matrice d'adjacence associée à l'hypergraphe.
 *
 */

#ifndef MODEL_INCLUDE_ADJACENTMATRIX_HH_
#define MODEL_INCLUDE_ADJACENTMATRIX_HH_

#include "LibType.hh"
#include <boost/tuple/tuple.hpp>

class HyperEdge;

class HyperVertex;


/**
 * Déclaration de la matrice d'adjacence.
 */
class AdjacentMatrix {

public:

	/**
	 * Constructeur par défaut.
	 */
	AdjacentMatrix();

	/**
	 * Constructeur de taille particulière.
	 * @param x L'abscisse
	 * @param y L'ordonnée de la matrice.
	 */
	AdjacentMatrix(const unsigned int&, const unsigned int&);

	/**
	 * Modification de la taille de la matrice.
	 * @param x L'abscisse
	 * @param y L'ordonnée de la matrice.
	 */
	void resize(const unsigned int&, const unsigned int&);

	/**
	 * Ajouter un hyper-vertex à la matrice.
	 * @param HyperVertex L'hyper-vertex à ajouter.
	 */
	void addHyperVertex(const boost::shared_ptr<HyperVertex>&);

	/**
	 * Ajouter une hyper-arête à la matrice.
	 * @param HyperEdge L'hyper-arête à ajouter.
	 */
	void addHyperEdge(const boost::shared_ptr<HyperEdge>&);

	/**
	 * Vérifier si l'hyper-vertex est dans l'hyper-arête.
	 * @param L'hyper-vertex à vérifier.
	 * @param L'hyper-arête dont la précence de l'hyper-vertex est à vérifier.
	 * @return True si l'hyper-vertex est dans l'hyper-arête, False sinon.
	 */
	bool isVertexInEdge(const boost::shared_ptr<HyperVertex>&, const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Vérifier si une hyper-arête est dans la liste des hyper-arêtes d'un hyper-vertex.
	 * @param L'hyper-arête à vérifier.
	 * @param L'hyper-vertex.
	 * @return True si l'hyper-vertex contient l'hyper-arête dans sa liste, False sinon.
	 */
	bool isEdgeInVertex(const boost::shared_ptr<HyperEdge>&, const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Vérifier si l'hyper-vertex ayant l'identifiant i se trouve dans l'hyper-arête ayant l'identifiant j.
	 * @param L'identifiant de l'hyper-vertex.
	 * @param L'identifiant de l'hyper-arête.
	 * @return True si c'est le cas, False sinon.
	 */
	bool isVertexInEdge(const int&, const int&) const;

	/**
	 * Vérifier si l'hyper-arête ayant l'identifiant i se trouve dans la liste de l'hyper-vertex ayant l'identifiant j.
	 * @param L'identifiant de l'hyper-arête.
	 * @param L'identifiant de l'hyper-vertex.
	 * @return True si c'est le cas, False sinon.
	 */
	bool isEdgeInVertex(const int&, const int&) const;

	/**
	 * Obtenir la matrice d'adjacence booléenne.
	 * @return La matrice d'adjacence booléenne.
	 */
	LibType::AdjacentMatrixContainerBool& getBoolAdjacentMatrix();

	/**
	 * Obtenir la matrice d'adjacence entière.
	 * @return La matrice d'adjacence entière.
	 */
	LibType::AdjacentMatrixContainerInt& getUIntAdjacentMatrix();

	/**
	 * Obtenir le degré d'un hyper-vertex.
	 * @param L'hyper-vertex dont on souhaite obtenir le degré.
	 * @return Nn entier positif correspondant au degrès de l'hyper-vertex.
	 */
	unsigned int getVertexDegree(const boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Obtenir l'effectif d'une hyper-arête.
	 * @param L'hyper-arête dont on souhaite obtenir l'effectif.
	 * @return Un entier positif correspondant au nombre d'hyper-vertex dans l'hyper-arête.
	 */
	unsigned int getEdgeSize(const boost::shared_ptr<HyperEdge>&) const;

	/**
	 * Obtenir le co-rang de l'hypergraphe.
	 * @return Un entie correspondant au co-rang.
	 */
	unsigned int getCoRank() const;

	/**
	 * Obtenir le rang de l'hypergraphe.
	 * @return Un entie correspondant au rang.
	 */
	unsigned int getRank() const;

	/**
	 * Obtenir les dimensions de la matrice d'adjacence.
	 * @return Un tuple dont le premier nombre est l'abscisse, le second est l'ordonnée.
	 */
	boost::tuple<unsigned int, unsigned int>&
	getMatrixDimension();

	/**
	 * Fonction-test affichant la matrice sur la sortie standard - NE PAS UTILISER.
	 */
	void display() const;

protected:

	/**
	 * L'abscisse.
	 */
	unsigned int _m;

	/**
	 * L'ordonnée.
	 */
	unsigned int _n;

	/**
	 * Les données de la matrice d'adjacence booléenne.
	 */
	LibType::AdjacentMatrixContainerBool _adjacentMatrixBool;

	/**
	 * Les données de la matrice d'adjacence entière.
	 */
	LibType::AdjacentMatrixContainerInt  _adjacentMatrixUInt;

};



#endif


/**
 * Module de lecture.
 */
#ifndef IO_INCLUDE_READERFILE_HH_
#define IO_INCLUDE_READERFILE_HH_

#include "ReaderAbstrait.hh"
#include <istream>


/**
 * Déclaration du module de lecture.
 */
class ReaderFile : public ReaderAbstrait {

public:

	/**
	 * Constructeur.
	 */
	ReaderFile();

	/**
	 * Lecture de l'instance de l'hypergraphe.
	 * @param Le flux entrant.
	 */
	void readHypergraphe(std::istream&);

	/**
	 * Deestructeur.
	 */
	~ReaderFile();


protected:

	/**
	 * Lecture des hyper-vertex de l'instance.
	 * @param Le flux entrant.
	 */
	void readHypergrapheHyperVertex(std::istream&);

	/**
	 * Lecture des hyper-arêtes de l'instance.
	 * @param Le flux entrant.
	 */
	void readHypergrapheHyperEdge(std::istream&);

	/**
	 * Obtenir l'hyper-vertex via l'identifiant numérique.
	 * @param L'identifiant numérique.
	 */
	HyperVertex& hyperVertexById(unsigned int&);

	/**
	 * Obtenir l'hyper-arête via l'identifiant numérique.
	 * @param L'identifiant numérique.
	 */
	HyperEdge& hyperEdgeById(unsigned int&);

	/**
	 * Construction de l'instance après lecture.
	 */
	void flush();


protected:

	/**
	 * Liste des hyper-vertex lus.
	 */
	LibType::ListHyperVertex
	_listHyperVertex;

	/**
	 * Liste des hyper-arêtes lues.
	 */
	LibType::ListHyperEdge
	_listHyperEdge;

};


#endif /* IO_INCLUDE_READERFILE_HH_ */

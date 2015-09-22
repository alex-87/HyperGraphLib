/**
 * Module d'écriture d'une instance d'hypergraphe.
 */
#ifndef IO_INCLUDE_WRITERFILE_HH_
#define IO_INCLUDE_WRITERFILE_HH_

#include "WriterAbstrait.hh"

/**
 * Délaration du module d'écriture de l'instance d'un hypergraphe.
 */
class WriterFile : public WriterAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	WriterFile(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Eciture de la matrice d'adjacence sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	void writeAdjacentMatrix(std::ostream&) const;

	/**
	 * Ecriture de l'instance de l'hypergraphe sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	void writeHypergraph(std::ostream&) const;


protected:

	/**
	 * Ecriture des hyper-vertex sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	void writeHypergrapheHyperVertex(std::ostream&) const;

	/**
	 * Ecriture des hyper-arêtes sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	void writeHypergrapheHyperEdge(std::ostream&) const;


protected:

};



#endif /* IO_INCLUDE_READERFILE_HH_ */

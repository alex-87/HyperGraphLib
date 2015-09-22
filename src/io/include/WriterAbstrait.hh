/**
 * Interface du module d'écriture d'instance.
 */
#ifndef IO_INCLUDE_WRITERABSTRAIT_HH_
#define IO_INCLUDE_WRITERABSTRAIT_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Déclaration de l'interface du module d'écriture d'instance.
 */
class WriterAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	WriterAbstrait(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Ecriture de la matrice d'adjacence sur la sortie indiquée.
	 * @param Le flux de sortie.
	 */
	virtual void writeAdjacentMatrix(std::ostream&) const = 0;

	/**
	 * Ecriture de l'hypergraphe sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	virtual void writeHypergraph(std::ostream&) const = 0;

	/**
	 * Destructeur virtuel.
	 */
	virtual ~WriterAbstrait();


protected:

	/**
	 * Ecriture des hyper-vertex sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	virtual void writeHypergrapheHyperVertex(std::ostream&) const = 0;

	/**
	 * Ecriture des hyper-arêtes sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	virtual void writeHypergrapheHyperEdge(std::ostream&) const = 0;


protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

};



#endif /* IO_INCLUDE_WRITERABSTRAIT_HH_ */

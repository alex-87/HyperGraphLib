/**
 * Interface du module de lecture d'instance.
 */
#ifndef IO_INCLUDE_READERABSTRAIT_HH_
#define IO_INCLUDE_READERABSTRAIT_HH_

#include "../model/HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Dfinition de l'interface du module de lecture d'instance.
 */
class ReaderAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé sur l'hypergrahe.
	 */
	ReaderAbstrait(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Lecture de l'instance et construction de l'hypergraphe.
	 * @param Le flux entrant.
	 */
	virtual void readHypergraphe(std::istream&) = 0;

	/**
	 * Obtenir l'hypergraphe après construction.
	 */
	boost::shared_ptr<HypergrapheAbstrait>&
	getHypergraphe();

	/**
	 * Déstructeur virtuel.
	 */
	virtual ~ReaderAbstrait();


protected:

	/**
	 * Lire les hyper-vertex de l'instance.
	 * @param Le flux entrant.
	 */
	virtual void readHypergrapheHyperVertex(std::istream&) = 0;

	/**
	 * Lire les hyper-arêtes de l'instance.
	 * @param Le flux entrant.
	 */
	virtual void readHypergrapheHyperEdge(std::istream&) = 0;


protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

};



#endif /* IO_INCLUDE_READERABSTRAIT_HH_ */

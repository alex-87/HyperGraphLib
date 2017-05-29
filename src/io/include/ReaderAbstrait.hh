/**
 * Input interface
 */
#ifndef IO_INCLUDE_READERABSTRAIT_HH_
#define IO_INCLUDE_READERABSTRAIT_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Input interface
 */
class ReaderAbstrait {

public:

	/**
	 * Constructor
	 * @param HypergrapheAbstrait shared pointer
	 */
	ReaderAbstrait(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Read and build the hypergraph
	 * @param Input flow
	 */
	virtual void readHypergraphe(std::istream&) = 0;

	/**
	 * Get the hypergraph after building
	 */
	boost::shared_ptr<HypergrapheAbstrait>&
	getHypergraphe();

	/**
	 * Virtual destructor
	 */
	virtual ~ReaderAbstrait();


protected:

	/**
	 * Read hyper-vertex
	 * @param Input flow
	 */
	virtual void readHypergrapheHyperVertex(std::istream&) = 0;

	/**
	 * Read hyper-edge
	 * @param Input flow
	 */
	virtual void readHypergrapheHyperEdge(std::istream&) = 0;


protected:

	/**
	 * HypergrapheAbstrait shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

};



#endif /* IO_INCLUDE_READERABSTRAIT_HH_ */

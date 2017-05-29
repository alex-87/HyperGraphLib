/**
 * Output interface
 */
#ifndef IO_INCLUDE_WRITERABSTRAIT_HH_
#define IO_INCLUDE_WRITERABSTRAIT_HH_

#include "../../model/include/HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Output interface
 */
class WriterAbstrait {

public:

	/**
	 * Constructor
	 * @param HypergrapheAbstrait shared pointer
	 */
	WriterAbstrait(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Adajency matrix output
	 * @param Output flow
	 */
	virtual void writeAdjacentMatrix(std::ostream&) const = 0;

	/**
	 * Hypergraph output write
	 * @param Output flow
	 */
	virtual void writeHypergraph(std::ostream&) const = 0;

	/**
	 * Virtual destructor
	 */
	virtual ~WriterAbstrait();


protected:

	/**
	 * Output hyper-vertex write
	 * @param Output flow
	 */
	virtual void writeHypergrapheHyperVertex(std::ostream&) const = 0;

	/**
	 * Output hyper-edge write
	 * @param Output flow
	 */
	virtual void writeHypergrapheHyperEdge(std::ostream&) const = 0;


protected:

	/**
	 * HypergrapheAbstrait shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

};



#endif /* IO_INCLUDE_WRITERABSTRAIT_HH_ */

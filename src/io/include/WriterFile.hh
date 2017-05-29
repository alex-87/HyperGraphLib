/**
 * Output module
 */
#ifndef IO_INCLUDE_WRITERFILE_HH_
#define IO_INCLUDE_WRITERFILE_HH_

#include "WriterAbstrait.hh"

/**
 * Output module
 */
class WriterFile : public WriterAbstrait {

public:

	/**
	 * Constructor
	 * @param HypergrapheAbstrait shared pointer
	 */
	WriterFile(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Adajency matrix output
	 * @param Output flow
	 */
	void writeAdjacentMatrix(std::ostream&) const;

	/**
	 * Hypergraph output write
	 * @param Output flow
	 */
	void writeHypergraph(std::ostream&) const;


protected:

	/**
	 * Output hyper-vertex write
	 * @param Output flow
	 */
	void writeHypergrapheHyperVertex(std::ostream&) const;

	/**
	 * Output hyper-edge write
	 * @param Output flow
	 */
	void writeHypergrapheHyperEdge(std::ostream&) const;


protected:

};



#endif /* IO_INCLUDE_READERFILE_HH_ */

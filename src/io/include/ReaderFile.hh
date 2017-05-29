/**
 * Input module
 */
#ifndef IO_INCLUDE_READERFILE_HH_
#define IO_INCLUDE_READERFILE_HH_

#include "ReaderAbstrait.hh"
#include <istream>


/**
 * Input module
 */
class ReaderFile : public ReaderAbstrait {

public:

	/**
	 * Constructor
	 */
	ReaderFile();

	/**
	 * Read and build the hypergraph
	 * @param Input flow
	 */
	void readHypergraphe(std::istream&);

	/**
	 * Destructor
	 */
	~ReaderFile();


protected:

	/**
	 * Read hyper-vertex
	 * @param Input flow
	 */
	void readHypergrapheHyperVertex(std::istream&);

	/**
	 * Read hyper-edge
	 * @param Input flow
	 */
	void readHypergrapheHyperEdge(std::istream&);

	/**
	 * Get hyper-vertex by Id
	 * @param Id
	 */
	boost::shared_ptr<HyperVertex>& hyperVertexById(unsigned int&);

	/**
	 * Get hyper-edge by Id
	 * @param Id
	 */
	boost::shared_ptr<HyperEdge>& hyperEdgeById(unsigned int&);

	/**
	 * Build the hypergraph
	 */
	void flush();


protected:

	/**
	 * Read hyper-vertex
	 */
	LibType::ListHyperVertex
	_listHyperVertex;

	/**
	 * Read hyper-edge
	 */
	LibType::ListHyperEdge
	_listHyperEdge;

};


#endif /* IO_INCLUDE_READERFILE_HH_ */

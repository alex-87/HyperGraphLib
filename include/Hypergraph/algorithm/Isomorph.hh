
#ifndef ALGORITHM_INCLUDE_ISOMORPHISM_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISM_HH_

#include <boost/config.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>

#include "../model/HypergrapheAbstrait.hh"
#include "../model/AlgorithmeAbstrait.hh"

class Isomorph : public AlgorithmeAbstrait {

public:

	Isomorph(const boost::shared_ptr<HypergrapheAbstrait>&, const boost::shared_ptr<HypergrapheAbstrait>&);

	RStructure getResult() const;

	~Isomorph();

protected:

	typedef boost::adjacency_list<boost::vecS, boost::listS, boost::undirectedS, boost::property<boost::vertex_index_t, int> >
	graph_t;

	void hypergraphTranspose(const boost::shared_ptr<HypergrapheAbstrait>&, graph_t&);

	void runAlgorithme();

protected:

	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstraitA;

	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstraitB;

	RStructure _result;

};



#endif

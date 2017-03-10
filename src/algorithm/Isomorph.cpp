
#include "include/Isomorph.hh"
#include "../model/include/Hypergraphe.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"
#include <boost/graph/isomorphism.hpp>

Isomorph::Isomorph(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
				   const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB)
				   : _ptrHypergrapheAbstraitA(ptrHypergrapheAbstraitA),
					 _ptrHypergrapheAbstraitB(ptrHypergrapheAbstraitB) {

}

void
Isomorph::runAlgorithme() {

	bool ret = false;
	graph_t graphA( _ptrHypergrapheAbstraitA->getHyperEdgeList().size() ),
			graphB( _ptrHypergrapheAbstraitB->getHyperEdgeList().size() );

#pragma omp parallel sections
	{

#pragma omp section
		{
			hypergraphTranspose(_ptrHypergrapheAbstraitA, graphA);
		}

#pragma omp section
		{
			hypergraphTranspose(_ptrHypergrapheAbstraitB, graphB);
		}

	}

	std::vector<boost::graph_traits<graph_t>::vertex_descriptor> f( _ptrHypergrapheAbstraitA->getHyperEdgeList().size() );

	boost::property_map<graph_t, boost::vertex_index_t>::type
	v_index_map = get(boost::vertex_index, graphA);

	ret = boost::isomorphism(
			graphA,
			graphB,
			boost::isomorphism_map(
					boost::make_iterator_property_map(f.begin(), v_index_map, f[0])
			)
	);

	_result.setBooleanResult( ret );
}

void
Isomorph::hypergraphTranspose(const boost::shared_ptr<HypergrapheAbstrait>& hpg, graph_t& graphOut) {

	std::vector<boost::graph_traits<graph_t>::vertex_descriptor>
	v(hpg->getHyperEdgeList().size());

	boost::property_map<graph_t, boost::vertex_index_t>::type
	v_index_map = get(boost::vertex_index, graphOut);

	boost::graph_traits<graph_t>::vertex_iterator i, end;
	int id = 0;
	for (boost::tie(i, end) = boost::vertices(graphOut); i != end; ++i, ++id) {
		put(v_index_map, *i, id);
		v[id] = *i;
	}

	for(unsigned int u=0; u<hpg->getHyperEdgeList().size(); u++ ) {
		for(unsigned int h=0; h<hpg->getHyperEdgeList().at(u)->getHyperVertexList().size(); h++) {
			for(unsigned int q=0; q<hpg->getHyperEdgeList().at(u)->getHyperVertexList().at(h)->getHyperEdgeList().size(); q++) {
				boost::add_edge(v[hpg->getHyperEdgeList().at(u)->getHyperVertexList().at(h)->getIdentifier()],
								v[hpg->getHyperEdgeList().at(u)->getHyperVertexList().at(h)->getHyperEdgeList().at(q)->getIdentifier()],
								graphOut );
			}
		}
	}
}

RStructure
Isomorph::getResult() const {
	return _result;
}

Isomorph::~Isomorph() {
}


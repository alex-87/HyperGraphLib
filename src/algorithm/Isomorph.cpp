
#include "include/Isomorph.hh"
#include <boost/graph/isomorphism.hpp>

Isomorph::Isomorph(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
				   const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB)
				   : _ptrHypergrapheAbstraitA(ptrHypergrapheAbstraitA),
					 _ptrHypergrapheAbstraitB(ptrHypergrapheAbstraitB) {

}

void
Isomorph::runAlgorithme() {

	bool ret = false;
	graph_t graphA, graphB;

#pragma omp parallel sections
	{

#pragma omp section
		{
			graph_t graphA = hypergraphTranspose(_ptrHypergrapheAbstraitA);
		}

#pragma omp section
		{
			graph_t graphB = hypergraphTranspose(_ptrHypergrapheAbstraitB);
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

boost::adjacency_list<boost::vecS, boost::listS, boost::undirectedS, boost::property<boost::vertex_index_t, int> >&
Isomorph::hypergraphTranspose(const boost::shared_ptr<HypergrapheAbstrait>& hpg) {

	std::vector<boost::graph_traits<graph_t>::vertex_descriptor>
	v(hpg->getHyperEdgeList().size());

	graph_t graphOut( hpg->getHyperEdgeList().size() );

	boost::property_map<graph_t, boost::vertex_index_t>::type
	v_index_map = get(boost::vertex_index, graphOut);

	boost::graph_traits<graph_t>::vertex_iterator i, end;
	int id = 0;
	for (boost::tie(i, end) = boost::vertices(graphOut); i != end; ++i, ++id) {
		put(v_index_map, *i, id);
		v[id] = *i;
	}

	for(int u=0; u<hpg->getHyperEdgeList().size(); u++ ) {
		for(int h=0; h<hpg->getHyperEdgeList().at(u)->getHyperVertexList().size(); h++) {
			for(int q=0; q<hpg->getHyperEdgeList().at(u)->getHyperVertexList().at(h)->getHyperEdgeList().size(); <++) {
				boost::add_edge(v[hpg->getHyperEdgeList().at(u)->getHyperVertexList().at(h)->getIdentifier()],
								v[hpg->getHyperEdgeList().at(u)->getHyperVertexList().at(h)->getHyperEdgeList().at(q)->getIdentifier()],
								graphOut );
			}
		}
	}

	return graphOut;
}

RStructure
Isomorph::getResult() const {
	return _result;
}

Isomorph::~Isomorph() {
}


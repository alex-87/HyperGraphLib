
#include "include/RandomHypergraph.hh"
#include "../include/Hypergraph/model/Hypergraph.hh"

#include <random>
#include <ctime>
#include <limits>

RandomHypergraph::RandomHypergraph()
    : _ptrAbstractHypergraph(new Hypergraph) {
}

void RandomHypergraph::generateHypergraph(unsigned int nbVertex, unsigned int nbEdge) {
	std::vector<std::shared_ptr<HyperVertex>> listVertex;
	std::vector<std::shared_ptr<HyperEdge>> listEdge;

	std::mt19937 gen;
	gen.seed(static_cast<std::mt19937::result_type>(std::time(0)));
	std::uniform_int_distribution<int> uInt8Dist(0, std::numeric_limits<unsigned char>::max());

	for (unsigned int i = 0; i < nbVertex; i++)
		listVertex.push_back(_ptrAbstractHypergraph->addHyperVertex());

	for (unsigned int j = 0; j < nbEdge; j++)
		listEdge.push_back(_ptrAbstractHypergraph->addHyperEdge());

	for (unsigned int u = 0; u < (nbVertex * nbEdge); u++) {
		if (u % 3 == 0) {
			int n = uInt8Dist(gen);
			_ptrAbstractHypergraph->link(listVertex.at((u + n) % nbVertex), listEdge.at((u * n) % nbEdge));
		}
	}
}

std::shared_ptr<AbstractHypergraph>&
RandomHypergraph::getHypergraph() {
	return _ptrAbstractHypergraph;
}

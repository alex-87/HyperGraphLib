
#include "include/RandomHypergraph.hh"
#include "../include/Hypergraph/model/HyperFactory.hh"
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
	auto getRand = [&]() { return uInt8Dist(gen); };

	HyperFactory::startSession(_ptrAbstractHypergraph);

	for (unsigned int i = 0; i < nbVertex; i++)
		listVertex.push_back(HyperFactory::newHyperVertex());

	for (unsigned int j = 0; j < nbEdge; j++)
		listEdge.push_back(HyperFactory::newHyperEdge());

	for (unsigned int u = 0; u < (nbVertex * nbEdge); u++) {
		if (u % 3 == 0) {
			int n = getRand();
			HyperFactory::link(listVertex.at((u + n) % nbVertex), listEdge.at((u * n) % nbEdge));
		}
	}

	for (unsigned int i = 0; i < nbVertex; i++) {
		_ptrAbstractHypergraph->addHyperVertex(listVertex.at(i));
	}

	for (unsigned int i = 0; i < nbEdge; i++) {
		_ptrAbstractHypergraph->addHyperEdge(listEdge.at(i));
	}

	HyperFactory::closeSession();

	_ptrAbstractHypergraph->flush();
}

std::shared_ptr<AbstractHypergraph>&
RandomHypergraph::getHypergraph() {
	return _ptrAbstractHypergraph;
}

/*
 * MIT License
 *
 * Copyright (c) 2015 Alexis LE GOADEC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "../include/Hypergraph/model/AbstractHypergraph.hh"
#include "../include/Hypergraph/model/Hypergraph.hh"
#include "../include/Hypergraph/model/ResultStructure.hh"
#include "../include/Hypergraph/model/AbstractAlgorithm.hh"

#include "../include/Hypergraph/algorithm/Connected.hh"
#include "../include/Hypergraph/algorithm/kRegular.hh"
#include "../include/Hypergraph/algorithm/Isomorph.hh"
#include "../include/Hypergraph/algorithm/Simple.hh"
#include "../include/Hypergraph/algorithm/Linear.hh"
#include "../include/Hypergraph/algorithm/Path.hh"
#include "../include/Hypergraph/algorithm/Diameter.hh"

#include "include/MiniTest.hh"


std::shared_ptr<AbstractHypergraph> ptrHpgAlgorithm(new Hypergraph);
std::shared_ptr<AbstractHypergraph> ptrHpgAlgorithm2(new Hypergraph);

void setupAlgorithm(void) {
	for (auto& ptrHpg : {ptrHpgAlgorithm, ptrHpgAlgorithm2}) {
		std::shared_ptr<HyperEdge> ptrEdge1(ptrHpg->addHyperEdge());
		std::shared_ptr<HyperEdge> ptrEdge2(ptrHpg->addHyperEdge());

		for (unsigned int i = 0; i < 50; i++) {
			ptrHpg->link(ptrHpg->addHyperVertex(), ptrEdge1);
			ptrHpg->link(ptrHpg->addHyperVertex(), ptrEdge2);
		}
	}
}

void teardownAlgorithm(void) {
}

TEST(test_algorithm, hpg_connected, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new Connected(ptrHpgAlgorithm));
	cn->run();

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == false, "Graphe is connexe");
}

TEST(test_algorithm, hpg_kregular, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new kRegular(ptrHpgAlgorithm));
	cn->run();

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == true, "Graphe is not k-regular");
}

TEST(test_algorithm, hpg_simple, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new Simple(ptrHpgAlgorithm));
	cn->run();

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == true, "Graphe not simple");
}

TEST(test_algorithm, hpg_linear, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new Linear(ptrHpgAlgorithm));
	cn->run();

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == true, "Graphe is not Linear");
}

TEST(test_algorithm, hpg_isomorph, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new Isomorph(ptrHpgAlgorithm, ptrHpgAlgorithm2));
	cn->run();

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == true, "Graphe is not isomorph");
}

TEST(test_algorithm, hpg_path, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<Path> pathAlgo(new Path(ptrHpgAlgorithm));

	pathAlgo->setHyperVertex(
	    ptrHpgAlgorithm->getHyperVertexById(0),
	    ptrHpgAlgorithm->getHyperVertexById(1));

	pathAlgo->run();

	ResultStructurePath r(pathAlgo->getPathResult());

	cr_expect(r.getPathResult()->size() == 0, "Path issue");
}

static std::shared_ptr<AbstractHypergraph> buildHypergraph(unsigned int nbVertex, const std::vector<std::vector<unsigned int>>& edges) {
	std::shared_ptr<AbstractHypergraph> hpg(new Hypergraph);
	for (unsigned int i = 0; i < nbVertex; i++)
		hpg->addHyperVertex();
	for (const auto& edge : edges) {
		std::shared_ptr<HyperEdge> hyperEdge(hpg->addHyperEdge());
		for (unsigned int id : edge)
			hpg->link(hpg->getHyperVertexById(id), hyperEdge);
	}
	return hpg;
}

static unsigned int runDiameter(const std::shared_ptr<AbstractHypergraph>& hpg, bool& finite) {
	std::shared_ptr<Diameter> diameter(new Diameter(hpg));
	diameter->run();
	finite = diameter->getResult().getBooleanResult();
	return diameter->getDiameter();
}

TEST(test_algorithm, hpg_diameter_chain, setupAlgorithm, teardownAlgorithm) {
	// 0 -e0- 1 -e1- 2 -e2- 3 : the diameter is 3
	bool finite(false);
	unsigned int d(runDiameter(buildHypergraph(4, {{0, 1}, {1, 2}, {2, 3}}), finite));
	cr_expect(finite, "A chain is connected");
	cr_expect(d == 3, "Diameter of a chain of 3 edges should be 3");
}

TEST(test_algorithm, hpg_diameter_hyperedges, setupAlgorithm, teardownAlgorithm) {
	// 0 and 3 are only linked through e0 then e1: the diameter is 2, not 3
	bool finite(false);
	unsigned int d(runDiameter(buildHypergraph(4, {{0, 1, 2}, {2, 3}}), finite));
	cr_expect(finite, "Should be connected");
	cr_expect(d == 2, "Diameter should count hyperedges, not vertices");
}

TEST(test_algorithm, hpg_diameter_single_edge, setupAlgorithm, teardownAlgorithm) {
	bool finite(false);
	unsigned int d(runDiameter(buildHypergraph(5, {{0, 1, 2, 3, 4}}), finite));
	cr_expect(finite, "Should be connected");
	cr_expect(d == 1, "Diameter with a single hyperedge should be 1");
}

TEST(test_algorithm, hpg_diameter_cycle, setupAlgorithm, teardownAlgorithm) {
	// 6-cycle: the farthest vertices are 3 edges apart
	bool finite(false);
	unsigned int d(runDiameter(buildHypergraph(6, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}}), finite));
	cr_expect(finite, "Should be connected");
	cr_expect(d == 3, "Diameter of a 6-cycle should be 3");
}

TEST(test_algorithm, hpg_diameter_disconnected, setupAlgorithm, teardownAlgorithm) {
	bool finite(true);
	unsigned int d(runDiameter(ptrHpgAlgorithm, finite));
	cr_expect(!finite, "Two disjoint hyperedges are not connected");
	cr_expect(d == Diameter::INFINITE_DIAMETER, "Diameter of a disconnected hypergraph is infinite");

	// A vertex belonging to no hyperedge cannot be reached
	finite = true;
	d = runDiameter(buildHypergraph(3, {{0, 1}}), finite);
	cr_expect(!finite, "An isolated vertex disconnects the hypergraph");
	cr_expect(d == Diameter::INFINITE_DIAMETER, "Diameter should be infinite");
}

TEST(test_algorithm, hpg_diameter_trivial, setupAlgorithm, teardownAlgorithm) {
	bool finite(false);
	unsigned int d(runDiameter(buildHypergraph(0, {}), finite));
	cr_expect(finite && d == 0, "Empty hypergraph has diameter 0");

	finite = false;
	d = runDiameter(buildHypergraph(1, {}), finite);
	cr_expect(finite && d == 0, "A single vertex has diameter 0");
}

MINITEST_MAIN

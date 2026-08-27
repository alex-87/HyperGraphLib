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
#include "../include/Hypergraph/model/AlgorithmEngine.hh"
#include "../include/Hypergraph/model/ResultStructure.hh"
#include "../include/Hypergraph/model/AbstractAlgorithm.hh"

#include "../include/Hypergraph/algorithm/Connected.hh"
#include "../include/Hypergraph/algorithm/kRegular.hh"
#include "../include/Hypergraph/algorithm/Isomorph.hh"
#include "../include/Hypergraph/algorithm/Simple.hh"
#include "../include/Hypergraph/algorithm/Linear.hh"
#include "../include/Hypergraph/algorithm/Path.hh"

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
	AlgorithmEngine::set(cn);

	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");
	AlgorithmEngine::run();
	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == false, "Graphe is connexe");
}

TEST(test_algorithm, hpg_kregular, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new kRegular(ptrHpgAlgorithm));
	AlgorithmEngine::set(cn);

	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");
	AlgorithmEngine::run();
	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == true, "Graphe is not k-regular");
}

TEST(test_algorithm, hpg_simple, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new Simple(ptrHpgAlgorithm));
	AlgorithmEngine::set(cn);

	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");
	AlgorithmEngine::run();
	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == true, "Graphe not simple");
}

TEST(test_algorithm, hpg_linear, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new Linear(ptrHpgAlgorithm));
	AlgorithmEngine::set(cn);

	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");
	AlgorithmEngine::run();
	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == true, "Graphe is not Linear");
}

TEST(test_algorithm, hpg_isomorph, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<AbstractAlgorithm> cn(new Isomorph(ptrHpgAlgorithm, ptrHpgAlgorithm2));
	AlgorithmEngine::set(cn);

	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");
	AlgorithmEngine::run();
	cr_expect(AlgorithmEngine::isLock() == false, "Should be false");

	ResultStructure r(cn->getResult());
	cr_expect(r.getBooleanResult() == true, "Graphe is not isomorph");
}

TEST(test_algorithm, hpg_path, setupAlgorithm, teardownAlgorithm) {
	std::shared_ptr<Path> pathAlgo(new Path(ptrHpgAlgorithm));

	pathAlgo->setHyperVertex(
	    ptrHpgAlgorithm->getHyperVertexById(0),
	    ptrHpgAlgorithm->getHyperVertexById(1));

	std::shared_ptr<AbstractAlgorithm> algoPathAbstract(pathAlgo);

	AlgorithmEngine::set(algoPathAbstract);
	AlgorithmEngine::run();

	ResultStructurePath r(pathAlgo->getPathResult());

	cr_expect(r.getPathResult()->size() == 0, "Path issue");
}

MINITEST_MAIN

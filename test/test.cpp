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

#include <memory>
#include <stdexcept>

#include "../include/Hypergraph/model/AbstractHypergraph.hh"
#include "../include/Hypergraph/model/Hypergraph.hh"
#include "include/MiniTest.hh"


std::shared_ptr<AbstractHypergraph> ptrHpg;

void setup(void) {
	ptrHpg.reset(new Hypergraph);

	std::shared_ptr<HyperEdge> ptrEdge1(ptrHpg->addHyperEdge());
	std::shared_ptr<HyperEdge> ptrEdge2(ptrHpg->addHyperEdge());

	for (unsigned int i = 0; i < 50; i++) {
		ptrHpg->link(ptrHpg->addHyperVertex(), ptrEdge1);
		ptrHpg->link(ptrHpg->addHyperVertex(), ptrEdge2);
	}
}

void teardown(void) {
}

TEST(test_model, hpg_create, setup, teardown) {
	// Size of hpg's elements
	cr_expect(ptrHpg->getHyperEdgeList().size() == 2, "Incorrect HyperEdgeList size");
	cr_expect(ptrHpg->getHyperVertexList().size() == 100, "Incorrect HyperVertexList size");
}

TEST(test_model, hpg_ids, setup, teardown) {
	// Identifiers
	for (unsigned int i = 0; i < ptrHpg->getHyperVertexList().size(); i++) {
		cr_expect(ptrHpg->getHyperVertexById(i)->getIdentifier() == i, "Incorrect Id");
	}
}

TEST(test_model, hpg_mtx, setup, teardown) {
	const std::shared_ptr<HyperEdge> e1 = ptrHpg->getHyperEdgeById(0);
	const std::shared_ptr<HyperEdge> e2 = ptrHpg->getHyperEdgeById(1);

	// Adjacent matrix
	cr_expect(ptrHpg->getAdjacentMatrix().getEdgeSize(e1) == e1->getEffectif(), "adj. mtx1 issue");
	cr_expect(ptrHpg->getAdjacentMatrix().getEdgeSize(e2) == e2->getEffectif(), "adj. mtx2 issue");
}

TEST(test_model, hpg_rcr, setup, teardown) {
	unsigned int rank(ptrHpg->getAdjacentMatrix().getRank());
	unsigned int co_rank(ptrHpg->getAdjacentMatrix().getCoRank());

	// Adjacent matrix
	cr_expect(rank == co_rank, "rank / co-rank issue");
}

TEST(test_model, hpg_create_modify, setup, teardown) {
	std::shared_ptr<HyperEdge> ptrEdge1(ptrHpg->addHyperEdge());
	std::shared_ptr<HyperEdge> ptrEdge2(ptrHpg->addHyperEdge());

	ptrHpg->link(ptrHpg->addHyperVertex(), ptrEdge1);
	ptrHpg->link(ptrHpg->addHyperVertex(), ptrEdge2);

	cr_expect(ptrHpg->getAdjacentMatrix().getVertexCount() == 102, "Adjacent matrix not updated");
	cr_expect(ptrHpg->getAdjacentMatrix().getEdgeCount() == 4, "Adjacent matrix not updated");

	// Identifiers
	for (unsigned int i = 0; i < ptrHpg->getHyperVertexList().size(); i++) {
		cr_expect(ptrHpg->getHyperVertexById(i)->getIdentifier() == i, "Incorrect Id");
	}
}

TEST(test_model, hpg_contain, setup, teardown) {
	std::shared_ptr<AbstractHypergraph> cptrHpg(new Hypergraph);

	std::shared_ptr<HyperEdge> ptrEdge(cptrHpg->addHyperEdge());
	std::shared_ptr<HyperVertex> ptrVertex(cptrHpg->addHyperVertex());
	std::shared_ptr<HyperVertex> ptrOther(cptrHpg->addHyperVertex());

	cptrHpg->link(ptrVertex, ptrEdge);

	cr_expect(cptrHpg->isHyperVertexInHyperEdge(ptrVertex, ptrEdge) == true, "ptrEdge should contain ptrVertex");
	cr_expect(cptrHpg->isHyperVertexInHyperEdge(ptrOther, ptrEdge) == false, "ptrEdge should not contain ptrOther");
}

TEST(test_model, hpg_link_foreign, setup, teardown) {
	std::shared_ptr<AbstractHypergraph> otherHpg(new Hypergraph);
	std::shared_ptr<HyperVertex> ptrForeign(otherHpg->addHyperVertex());

	bool thrown(false);
	try {
		ptrHpg->link(ptrForeign, ptrHpg->getHyperEdgeById(0));
	} catch (const std::invalid_argument&) {
		thrown = true;
	}
	cr_expect(thrown, "Linking an element of another hypergraph should throw");
}

TEST(test_model, hpg_empty, setup, teardown) {
	Hypergraph emptyHpg;

	cr_expect(emptyHpg.getAdjacentMatrix().getRank() == 0, "Rank of an empty hypergraph");
	cr_expect(emptyHpg.getAdjacentMatrix().getCoRank() == 0, "Co-rank of an empty hypergraph");
}

MINITEST_MAIN

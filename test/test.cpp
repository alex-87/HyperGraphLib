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

#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HypergrapheAbstrait.hh"
#include "../include/Hypergraph/model/Hypergraphe.hh"

#include "include/MiniTest.hh"


std::shared_ptr<HypergrapheAbstrait> ptrHpg;

void setup(void) {

	ptrHpg.reset ( new Hypergraphe );

    HyperFactory::startSession(ptrHpg);

	std::vector<std::shared_ptr<HyperVertex>> listVertex;

    std::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    std::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    for(unsigned int i = 0; i < 50; i++) {

        std::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
        std::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

        HyperFactory::link(ptrVertexA, ptrEdge1);
        HyperFactory::link(ptrVertexB, ptrEdge2);

        listVertex.push_back(ptrVertexA);
        listVertex.push_back(ptrVertexB);
    }

    for(unsigned int t=0; t < listVertex.size(); t++) {
    	ptrHpg->addHyperVertex( listVertex.at( t ) );
    }

    ptrHpg->addHyperEdge(ptrEdge1);
    ptrHpg->addHyperEdge(ptrEdge2);

    ptrHpg->flush();

    HyperFactory::closeSession();

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
    for(unsigned int i=0; i < ptrHpg->getHyperVertexList().size(); i++) {
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

	unsigned int rank    ( ptrHpg->getAdjacentMatrix().getRank() );
	unsigned int co_rank ( ptrHpg->getAdjacentMatrix().getCoRank() );

	// Adjacent matrix
	cr_expect( rank == co_rank, "rank / co-rank issue");
}

TEST(test_model, hpg_create_modify, setup, teardown) {

    HyperFactory::startSession(ptrHpg);

    std::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    std::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    std::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
    std::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

    HyperFactory::link(ptrVertexA, ptrEdge1);
    HyperFactory::link(ptrVertexB, ptrEdge2);

    ptrHpg->addHyperVertex( ptrVertexA );
    ptrHpg->addHyperVertex( ptrVertexB );

    ptrHpg->addHyperEdge(ptrEdge1);
    ptrHpg->addHyperEdge(ptrEdge2);

    ptrHpg->flush();

    HyperFactory::closeSession();

    // Identifiers
    for(unsigned int i=0; i < ptrHpg->getHyperVertexList().size(); i++) {
        cr_expect(ptrHpg->getHyperVertexById(i)->getIdentifier() == i, "Incorrect Id");
    }

}

TEST(test_model, hpg_contain, setup, teardown) {

	std::shared_ptr<HypergrapheAbstrait> cptrHpg( new Hypergraphe );
	HyperFactory::startSession(cptrHpg);

	std::shared_ptr<HyperEdge> ptrEdge ( HyperFactory::newHyperEdge() );
	std::shared_ptr<HyperVertex> ptrVertex( HyperFactory::newHyperVertex() );

	HyperFactory::link(ptrVertex, ptrEdge);
	cptrHpg->addHyperEdge(ptrEdge);
	cptrHpg->addHyperVertex(ptrVertex);

	cptrHpg->flush();

	HyperFactory::closeSession();

	cr_expect(cptrHpg->isHyperVertexInHyperEdge(ptrVertex, ptrEdge) == true, "ptrEdge should contain ptrVertex");
}

MINITEST_MAIN



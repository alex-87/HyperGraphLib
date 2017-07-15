#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HypergrapheAbstrait.hh"
#include "../include/Hypergraph/model/Hypergraphe.hh"
#include <criterion/criterion.h>

boost::shared_ptr<HypergrapheAbstrait> ptrHpg;

void setup(void) {

	ptrHpg.reset ( new Hypergraphe );

    HyperFactory::startSession(ptrHpg);

	std::vector<boost::shared_ptr<HyperVertex>> listVertex;

    boost::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    boost::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    for(unsigned int i = 0; i < 50; i++) {

        boost::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
        boost::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

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

Test(test_model, hpg_create, .init = setup, .fini = teardown) {

    // Size of hpg's elements
    cr_expect(ptrHpg->getHyperEdgeList().size() == 2, "Incorrect HyperEdgeList size");
    cr_expect(ptrHpg->getHyperVertexList().size() == 100, "Incorrect HyperVertexList size");
}

Test(test_model, hpg_ids, .init = setup, .fini = teardown) {

    // Identifiers
    for(unsigned int i=0; i < ptrHpg->getHyperVertexList().size(); i++) {
        cr_expect(ptrHpg->getHyperVertexById(i)->getIdentifier() == i, "Incorrect Id");
    }
}

Test(test_model, hpg_mtx, .init = setup, .fini = teardown) {

	const boost::shared_ptr<HyperEdge> e1 = ptrHpg->getHyperEdgeById(0);
	const boost::shared_ptr<HyperEdge> e2 = ptrHpg->getHyperEdgeById(1);

	// Adjacent matrix
	cr_expect(ptrHpg->getAdjacentMatrix().getEdgeSize(e1) == e1->getEffectif(), "adj. mtx1 issue");
	cr_expect(ptrHpg->getAdjacentMatrix().getEdgeSize(e2) == e2->getEffectif(), "adj. mtx2 issue");
}

Test(test_model, hpg_rcr, .init = setup, .fini = teardown) {

	unsigned int rank    ( ptrHpg->getAdjacentMatrix().getRank() );
	unsigned int co_rank ( ptrHpg->getAdjacentMatrix().getCoRank() );

	// Adjacent matrix
	cr_expect( rank == co_rank, "rank / co-rank issue");
}

Test(test_model, hpg_create_modify, .init = setup, .fini = teardown) {

    HyperFactory::startSession(ptrHpg);

    boost::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    boost::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    boost::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
    boost::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

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

Test(test_model, hpg_contain, .init = setup, .fini = teardown) {

	boost::shared_ptr<HypergrapheAbstrait> cptrHpg;
	HyperFactory::startSession(cptrHpg);

	boost::shared_ptr<HyperEdge> ptrEdge ( HyperFactory::newHyperEdge() );
	boost::shared_ptr<HyperVertex> ptrVertex( HyperFactory::newHyperVertex() );

	HyperFactory::link(ptrVertex, ptrEdge);
	cptrHpg->addHyperEdge(ptrEdge);
	cptrHpg->addHyperVertex(ptrVertex);

	cptrHpg->flush();

	HyperFactory::closeSession();

	cr_expect(cptrHpg->isHyperVertexInHyperEdge(ptrVertex, ptrEdge) == true, "ptrEdge should contain ptrVertex");
}



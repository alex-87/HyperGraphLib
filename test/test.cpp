#include <criterion/criterion.h>
#include <Hypergraph/model/HyperFactory.hh>
#include <Hypergraph/model/HypergrapheAbstrait.hh>
#include <Hypergraph/model/Hypergraphe.hh>

Test(test_model, hpg_create) {

	boost::shared_ptr<HypergrapheAbstrait> ptrHpg( new Hypergraphe );

    HyperFactory::startSession(ptrHpg);

    boost::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    boost::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    for(unsigned int i = 0; i < 50; i++) {

    	boost::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperEdge() );
    	boost::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperEdge() );

    	HyperFactory::link(ptrVertexA, ptrEdge1);
    	HyperFactory::link(ptrVertexA, ptrEdge1);

    	ptrHpg->addHyperVertex(ptrVertexA);
    	ptrHpg->addHyperVertex(ptrVertexB);

    }

    ptrHpg->addHyperEdge(ptrEdge1);
    ptrHpg->addHyperEdge(ptrEdge2);

    HyperFactory::closeSession();

    ptrHpg->flush();

    // Size of hpg's elements
    cr_expect(ptrHpg->getHyperEdgeList().size() == 25, "Incorrect HyperEdgeList size");
    cr_expect(ptrHpg->getHyperVertexList().size() == 25, "Incorrect HyperVertexList size");


    AdjacentMatrix m( ptrHpg->getAdjacentMatrix() );

    // Adjacent matrix
    cr_expect(m.getRank() == m.getCoRank(), "Rank != coRank - expected : 25=25");
    cr_expect(m.getEdgeSize(ptrEdge1) == 25, "Incorrect Edge size");
    cr_expect(m.getEdgeSize(ptrEdge2) == 25, "Incorrect Edge size");


    // Identifiers
    for(unsigned int i=0; i < ptrHpg->getHyperVertexList().size(); i++) {
    	cr_expect(ptrHpg->getHyperVertexById(i)->getIdentifier() == i, "Incorrect Id");
    }

}


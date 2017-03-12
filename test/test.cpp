#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HypergrapheAbstrait.hh"
#include "../include/Hypergraph/model/Hypergraphe.hh"
#include <criterion/criterion.h>

Test(test_model, hpg_create) {

	boost::shared_ptr<HypergrapheAbstrait> ptrHpg( new Hypergraphe );

    HyperFactory::startSession(ptrHpg);

    boost::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    boost::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    for(unsigned int i = 0; i < 50; i++) {

    	boost::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
    	boost::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

    	HyperFactory::link(ptrVertexA, ptrEdge1);
    	HyperFactory::link(ptrVertexB, ptrEdge1);

    	ptrHpg->addHyperVertex(ptrVertexA);
    	ptrHpg->addHyperVertex(ptrVertexB);

    }

    ptrHpg->addHyperEdge(ptrEdge1);
    ptrHpg->addHyperEdge(ptrEdge2);

    HyperFactory::closeSession();

    ptrHpg->flush();

    // Size of hpg's elements
    cr_expect(ptrHpg->getHyperEdgeList().size() == 2, "Incorrect HyperEdgeList size");
    cr_expect(ptrHpg->getHyperVertexList().size() == 100, "Incorrect HyperVertexList size");


    // Identifiers
    for(unsigned int i=0; i < ptrHpg->getHyperVertexList().size(); i++) {
    	cr_expect(ptrHpg->getHyperVertexById(i)->getIdentifier() == i, "Incorrect Id");
    }

}


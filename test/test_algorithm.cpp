#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HypergrapheAbstrait.hh"
#include "../include/Hypergraph/model/Hypergraphe.hh"
#include "../include/Hypergraph/model/MotorAlgorithm.hh"
#include "../include/Hypergraph/model/RStructure.hh"
#include "../include/Hypergraph/model/AlgorithmeAbstrait.hh"

#include "../include/Hypergraph/algorithm/Connected.hh"

#include <criterion/criterion.h>



boost::shared_ptr<HypergrapheAbstrait> ptrHpg ( new Hypergraphe );

void setup(void) {
    HyperFactory::startSession(ptrHpg);

    boost::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    boost::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    for(unsigned int i = 0; i < 50; i++) {

        boost::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
        boost::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

        HyperFactory::link(ptrVertexA, ptrEdge1);
        HyperFactory::link(ptrVertexB, ptrEdge2);

        ptrHpg->addHyperVertex(ptrVertexA);
        ptrHpg->addHyperVertex(ptrVertexB);

    }

    ptrHpg->addHyperEdge(ptrEdge1);
    ptrHpg->addHyperEdge(ptrEdge2);

    HyperFactory::closeSession();

    ptrHpg->flush();

}

void teardown(void) {
}

Test(test_model, hpg_connected, .init = setup, .fini = teardown) {

	boost::shared_ptr<AlgorithmeAbstrait> cn( new Connected(ptrHpg) );
	MotorAlgorithm::setAlgorithme( cn );

	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");
	MotorAlgorithm::runAlgorithme();
	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");

	RStructure r( cn->getResult() );
	cr_expect( r.getBooleanResult() == false, "Graphe is connexe");

}

#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HypergrapheAbstrait.hh"
#include "../include/Hypergraph/model/Hypergraphe.hh"
#include "../include/Hypergraph/model/MotorAlgorithm.hh"
#include "../include/Hypergraph/model/RStructure.hh"
#include "../include/Hypergraph/model/AlgorithmeAbstrait.hh"

#include "../include/Hypergraph/algorithm/Connected.hh"
#include "../include/Hypergraph/algorithm/kRegular.hh"
#include "../include/Hypergraph/algorithm/Isomorph.hh"
#include "../include/Hypergraph/algorithm/Simple.hh"
#include "../include/Hypergraph/algorithm/Linear.hh"

#include <criterion/criterion.h>



boost::shared_ptr<HypergrapheAbstrait> ptrHpgAlgorithm ( new Hypergraphe );
boost::shared_ptr<HypergrapheAbstrait> ptrHpgAlgorithm2 ( new Hypergraphe );

void setupAlgorithm(void) {

	// First hpg
	{
		HyperFactory::startSession(ptrHpgAlgorithm);

		boost::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
		boost::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

		for(unsigned int i = 0; i < 50; i++) {

			boost::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
			boost::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

			HyperFactory::link(ptrVertexA, ptrEdge1);
			HyperFactory::link(ptrVertexB, ptrEdge2);

			ptrHpgAlgorithm->addHyperVertex(ptrVertexA);
			ptrHpgAlgorithm->addHyperVertex(ptrVertexB);

		}

		ptrHpgAlgorithm->addHyperEdge(ptrEdge1);
		ptrHpgAlgorithm->addHyperEdge(ptrEdge2);

		HyperFactory::closeSession();

		ptrHpgAlgorithm->flush();
	}


    // Second hpg
	{
		HyperFactory::startSession(ptrHpgAlgorithm2);

		boost::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
		boost::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

		for(unsigned int i = 0; i < 50; i++) {

			boost::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
			boost::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

			HyperFactory::link(ptrVertexA, ptrEdge1);
			HyperFactory::link(ptrVertexB, ptrEdge2);

			ptrHpgAlgorithm2->addHyperVertex(ptrVertexA);
			ptrHpgAlgorithm2->addHyperVertex(ptrVertexB);

		}

		ptrHpgAlgorithm2->addHyperEdge(ptrEdge1);
		ptrHpgAlgorithm2->addHyperEdge(ptrEdge2);

		HyperFactory::closeSession();

		ptrHpgAlgorithm2->flush();
	}

}

void teardownAlgorithm(void) {
}

Test(test_algorithm, hpg_connected, .init = setupAlgorithm, .fini = teardownAlgorithm) {

	boost::shared_ptr<AlgorithmeAbstrait> cn( new Connected(ptrHpgAlgorithm) );
	MotorAlgorithm::setAlgorithme( cn );

	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");
	MotorAlgorithm::runAlgorithme();
	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");

	RStructure r( cn->getResult() );
	cr_expect( r.getBooleanResult() == false, "Graphe is connexe");

}

Test(test_algorithm, hpg_kregular, .init = setupAlgorithm, .fini = teardownAlgorithm) {

	boost::shared_ptr<AlgorithmeAbstrait> cn( new kRegular(ptrHpgAlgorithm) );
	MotorAlgorithm::setAlgorithme( cn );

	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");
	MotorAlgorithm::runAlgorithme();
	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");

	RStructure r( cn->getResult() );
	cr_expect( r.getBooleanResult() == true, "Graphe is not k-regular");

}

Test(test_algorithm, hpg_simple, .init = setupAlgorithm, .fini = teardownAlgorithm) {

	boost::shared_ptr<AlgorithmeAbstrait> cn( new Simple(ptrHpgAlgorithm) );
	MotorAlgorithm::setAlgorithme( cn );

	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");
	MotorAlgorithm::runAlgorithme();
	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");

	RStructure r( cn->getResult() );
	cr_expect( r.getBooleanResult() == true, "Graphe not simple");

}

Test(test_algorithm, hpg_linear, .init = setupAlgorithm, .fini = teardownAlgorithm) {

	boost::shared_ptr<AlgorithmeAbstrait> cn( new Linear(ptrHpgAlgorithm) );
	MotorAlgorithm::setAlgorithme( cn );

	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");
	MotorAlgorithm::runAlgorithme();
	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");

	RStructure r( cn->getResult() );
	cr_expect( r.getBooleanResult() == true, "Graphe is not Linear");

}

Test(test_algorithm, hpg_isomorph, .init = setupAlgorithm, .fini = teardownAlgorithm) {

	boost::shared_ptr<AlgorithmeAbstrait> cn( new Isomorph(ptrHpgAlgorithm, ptrHpgAlgorithm2) );
	MotorAlgorithm::setAlgorithme( cn );

	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");
	MotorAlgorithm::runAlgorithme();
	cr_expect(MotorAlgorithm::isLock() == false, "Should be false");

	RStructure r( cn->getResult() );
	cr_expect( r.getBooleanResult() == true, "Graphe is not isomorph");

}

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
#include "../include/Hypergraph/algorithm/Path.hh"

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

Test(test_algorithm, hpg_path, .init = setupAlgorithm, .fini = teardownAlgorithm) {

	boost::shared_ptr<Path> pathAlgo( new Path( ptrHpgAlgorithm ) );

	pathAlgo->setHyperVertex(
			ptrHpgAlgorithm->getHyperVertexById(0),
			ptrHpgAlgorithm->getHyperVertexById(1)
		);

	boost::shared_ptr<AlgorithmeAbstrait> algoPathAbstrait( pathAlgo );

	MotorAlgorithm::setAlgorithme( algoPathAbstrait );
	MotorAlgorithm::runAlgorithme();

	RStructurePath r( pathAlgo->getPathResult() );

	cr_expect( r.getPathResult()->size() == 0, "Path issue");
}

#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HypergrapheAbstrait.hh"
#include "../include/Hypergraph/model/Hypergraphe.hh"

#include "../include/Hypergraph/io/ReaderFile.hh"
#include "../include/Hypergraph/io/WriterFile.hh"

#include <criterion/criterion.h>
#include <iostream>
#include <sstream>


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

Test(test_model, hpg_io, .init = setup, .fini = teardown) {

	std::stringstream trsf;
	std::stringstream trsf2;
	std::string a, b;

	WriterFile fWriter (ptrHpg);
	fWriter.writeHypergraph( trsf );

	a << trsf.str();

	ReaderFile fReader;
	fReader.readHypergraphe( trsf );

	WriterFile fWriter2 (fReader.getHypergraphe() );
	fWriter.writeHypergraph( trsf2 );

	b << trsf2.str();

	cr_expect(a == b, "Input / Output not eqal");
}

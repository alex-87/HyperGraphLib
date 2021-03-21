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
	std::stringstream a, b;

	WriterFile fWriter (ptrHpg);
	fWriter.writeHypergraph( trsf );

	a << trsf.str();

	ReaderFile fReader;
	fReader.readHypergraphe( trsf );

	WriterFile fWriter2 (fReader.getHypergraphe() );
	fWriter.writeHypergraph( trsf2 );

	b << trsf2.str();

	cr_expect(a.str() == b.str(), "Input / Output not eqal");
}

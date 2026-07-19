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
#include <fstream>
#include <iostream>

#include "include/ProgramOptions.hh"
#include "include/Client.hh"
#include "include/RandomHypergraphe.hh"

#include "../include/Hypergraph/model/LibType.hh"
#include "../include/Hypergraph/model/Hypergraphe.hh"
#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HyperVertex.hh"
#include "../include/Hypergraph/model/HyperEdge.hh"
#include "../include/Hypergraph/model/MotorAlgorithm.hh"

#include "../include/Hypergraph/algorithm/Dual.hh"
#include "../include/Hypergraph/algorithm/Path.hh"
#include "../include/Hypergraph/algorithm/Helly.hh"
#include "../include/Hypergraph/algorithm/kRegular.hh"
#include "../include/Hypergraph/algorithm/kUniform.hh"
#include "../include/Hypergraph/algorithm/Simple.hh"
#include "../include/Hypergraph/algorithm/Linear.hh"
#include "../include/Hypergraph/algorithm/Connected.hh"
#include "../include/Hypergraph/algorithm/HyperGraphStat.hh"
#include "../include/Hypergraph/algorithm/Isomorph.hh"

#include "../include/Hypergraph/io/WriterFile.hh"
#include "../include/Hypergraph/io/ReaderFile.hh"


/**
 * Run an algorithm whose result is a single boolean, print the matching
 * message and return the process exit code. Factorises the identical
 * set/run/report sequence shared by the boolean predicates below.
 */
template <typename Algorithm>
static int runBooleanAlgorithm(std::shared_ptr<HypergrapheAbstrait>& ptrHpg,
                               const std::string& whenTrue,
                               const std::string& whenFalse) {
	auto algo = makeAlgorithm<Algorithm>(ptrHpg);
	MotorAlgorithm::setAlgorithme( algo );
	MotorAlgorithm::runAlgorithme();

	RStructure r( algo->getResult() );
	std::cout << (r.getBooleanResult() ? whenTrue : whenFalse) << std::endl;
	return 0;
}

int main(int argc, char *argv[]) {

	po::options_description desc("Paramètres");
	desc.add_options()
					("version", "Afficher la version")
					("help", "Afficher l'aide")
					("inputfile", po::value<std::string>(), "Fichier d'entrée")
					("random", po::value<int>(), "Hypergraphe aléatoire de n vertex")
					("adjacence", "Affiche la matrice d'adjacence de l'hypergraphe")
					("dual", "Produit le Dual de l'hypergraphe")
					("kuniform", po::value<int>(), "Décide si l'hypergraphe est k-uniforme")
					("linear", "Décide si l'hypergraphe est linéaire")
					("kregular", "Décide si l'hypergraphe est k-regulier")
					("simple", "Décide si l'hypergraphe est simple")
					("helly", "Décide si un hypergraphe possède la propriété de Helly")
					("connexe", "Décide si l'hypergraphe est connexe")
					("isomorph", po::value<std::string>(), "Décide si deux hypergraphes sont isomorphe")
					("stat", "Retourne les statistiques de l'hypergraphe")
					("path", "Retourne le chemins")
					("source", po::value<int>(), "Source de la reherche de chemins")
					("destination", po::value<int>(), "Destination de la recherche de chemins");

	po::variables_map vm;
	try {
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	if (vm.count("help") || vm.empty()) {
	    std::cout << desc << "\n";
	    return !vm.empty();
	}

	if( vm.count("version") ) {
		std::cout << "HypergraphLib "
				  << VERSION_MAJOR << "."
				  << VERSION_MINOR << "-"
				  << VERSION_BUILD
				  << std::endl
				  << "Université de Caen Basse-Normandie, 2015 - Alexis LE GOADEC."
				  << std::endl
				  << "GCC version: " << __VERSION__ << std::endl
#ifdef __x86_64
				  << "x86_64: " << __x86_64 << std::endl
#endif
				  << "---" << std::endl;
		return 0;
	}

	std::shared_ptr<HypergrapheAbstrait> ptrHpg;

	if( vm.count("inputfile") && vm.count("random")==0 ) {
		std::ifstream ifs(vm["inputfile"].as<std::string>(), std::ifstream::in);

		ReaderFile fReader;
		fReader.readHypergraphe( ifs );
		ifs.close();

		ptrHpg = fReader.getHypergraphe();

	} else if( vm.count("inputfile")==0 && vm.count("random")==0) {
		ReaderFile fReader;
		fReader.readHypergraphe( std::cin );
		ptrHpg = fReader.getHypergraphe();
	}

	// Isomorphism special parameters configuration
	if( vm.count("isomorph") && vm.count("inputfile") ) {

		std::shared_ptr<HypergrapheAbstrait> ptrHpg2;

		std::ifstream ifs(vm["isomorph"].as<std::string>(), std::ifstream::in);

		ReaderFile fReader;
		fReader.readHypergraphe( ifs );
		ifs.close();

		ptrHpg2 = fReader.getHypergraphe();

		auto isomorphHpg = makeAlgorithm<Isomorph>(ptrHpg, ptrHpg2);

		MotorAlgorithm::setAlgorithme( isomorphHpg );
		MotorAlgorithm::runAlgorithme();

		RStructure r( isomorphHpg->getResult() );

		if( r.getBooleanResult() ) {
			std::cout << "L'hypergraphe est isomorphe." << std::endl;
		} else {
			std::cout << "L'hypergraphe n'est pas isomorphe." << std::endl;
		}

		return 0;
	}

	if( vm.count("random") ) {
		RandomHypergraphe rHyp;
		rHyp.generateHypergraphe(vm["random"].as<int>(), vm["random"].as<int>());
		ptrHpg = rHyp.getHypergraphe();
	}

	if( vm.count("stat") ) {
		auto statHpg = makeAlgorithm<HyperGraphStat>(ptrHpg);

		MotorAlgorithm::setAlgorithme( statHpg );
		MotorAlgorithm::runAlgorithme();

		std::shared_ptr<HyperGraphStat> s = std::static_pointer_cast<HyperGraphStat>( statHpg );

		std::cout << "Hyper-vertex : " << s->getNbrHyperVertex() << std::endl
				  << "Hyper-edge   : " << s->getNbrHyperEdge()   << std::endl
				  << "Nbr. links   : " << s->getNbrLinks()       << std::endl
				  << "Rang         : " << s->getRang()           << std::endl
				  << "Co-rang      : " << s->getCoRang()         << std::endl;

		return 0;
	}

	if( vm.count("dual") ) {

		auto dualAlgo = makeAlgorithm<Dual>(ptrHpg);

		MotorAlgorithm::setAlgorithme( dualAlgo );
		MotorAlgorithm::runAlgorithme();

		RStructure r( dualAlgo->getResult() );

		WriterFile w(r.getHypergrapheResult());
		if( vm.count("adjacence") ) {
			w.writeAdjacentMatrix( std::cout );
		} else {
			w.writeHypergraph( std::cout );
		}

		return 0;
	}

	if( vm.count("kuniform") ) {
		std::shared_ptr<AlgorithmeAbstrait> kuniformAlgo( new kUniform( ptrHpg, vm["kuniform"].as<int>() ) );
		MotorAlgorithm::setAlgorithme( kuniformAlgo );
		MotorAlgorithm::runAlgorithme();

		RStructure r( kuniformAlgo->getResult() );
		if( r.getBooleanResult() ) {
			std::cout << "L'hypergraphe est " << vm["kuniform"].as<int>() << "-uniforme." << std::endl;
		} else {
			std::cout << "L'hypergraphe n'est pas " << vm["kuniform"].as<int>() << "-uniforme." << std::endl;
		}

		return 0;
	}

	if( vm.count("linear") )
		return runBooleanAlgorithm<Linear>(ptrHpg,
				"L'hypergraphe est Linéaire.", "L'hypergraphe n'est pas Linéaire.");

	if( vm.count("helly") )
		return runBooleanAlgorithm<Helly>(ptrHpg,
				"L'hypergraphe est Helly.", "L'hypergraphe n'est pas Helly.");

	if( vm.count("kregular") )
		return runBooleanAlgorithm<kRegular>(ptrHpg,
				"L'hypergraphe est k-regulier.", "L'hypergraphe n'est pas k-regulier.");

	if( vm.count("simple") )
		return runBooleanAlgorithm<Simple>(ptrHpg,
				"L'hypergraphe est simple.", "L'hypergraphe n'est pas simple.");

	if(vm.count("path") ) {
		std::shared_ptr<Path> pathAlgo( new Path( ptrHpg ) );

		pathAlgo->setHyperVertex(
				ptrHpg->getHyperVertexById(vm["source"].as<int>()),
				ptrHpg->getHyperVertexById(vm["destination"].as<int>() )
			);

		std::shared_ptr<AlgorithmeAbstrait> algoPathAbstrait( pathAlgo );

		MotorAlgorithm::setAlgorithme( algoPathAbstrait );
		MotorAlgorithm::runAlgorithme();

		RStructurePath r( pathAlgo->getPathResult() );

		for(unsigned int i=0; i<r.getPathResult()->size(); i++) {
			LibType::ListHyperVertex hvl( r.getPathResult()->at(i) );
			for(unsigned int j=0; j<hvl.size(); j++) {
				std::cout << hvl.at(j)->getIdentifier() << " ";
			}
			std::cout << std::endl;
		}

	}

	if( vm.count("connexe") )
		return runBooleanAlgorithm<Connected>(ptrHpg,
				"L'hypergraphe est connexe.", "L'hypergraphe n'est pas connexe.");

	if( vm.count("adjacence") ) {
		WriterFile w( ptrHpg );
		w.writeAdjacentMatrix( std::cout );
	} else {
		WriterFile w( ptrHpg );
		w.writeHypergraph( std::cout );
	}

	return 0;
}

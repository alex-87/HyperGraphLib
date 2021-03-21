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


#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/config.hpp>
#include <boost/program_options/environment_iterator.hpp>
#include <boost/program_options/eof_iterator.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/version.hpp>
#include <fstream>
#include <iostream>

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


int main(int argc, char *argv[]) {

	boost::program_options::options_description desc("Paramètres");
	desc.add_options()
					("version", "Afficher la version")
					("help", "Afficher l'aide")
					("inputfile", boost::program_options::value<std::string>(), "Fichier d'entrée")
					("random", boost::program_options::value<int>(), "Hypergraphe aléatoire de n vertex")
					("adjacence", "Affiche la matrice d'adjacence de l'hypergraphe")
					("dual", "Produit le Dual de l'hypergraphe")
					("kuniform", boost::program_options::value<int>(), "Décide si l'hypergraphe est k-uniforme")
					("linear", "Décide si l'hypergraphe est linéaire")
					("kregular", "Décide si l'hypergraphe est k-regulier")
					("simple", "Décide si l'hypergraphe est simple")
					("helly", "Décide si un hypergraphe possède la propriété de Helly")
					("connexe", "Décide si l'hypergraphe est connexe")
					("isomorph", boost::program_options::value<std::string>(), "Décide si deux hypergraphes sont isomorphe")
					("stat", "Retourne les statistiques de l'hypergraphe")
					("path", "Retourne le chemins")
					("source", boost::program_options::value<int>(), "Source de la reherche de chemins")
					("destination", boost::program_options::value<int>(), "Destination de la recherche de chemins");

	boost::program_options::variables_map vm;
	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
	boost::program_options::notify(vm);

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
				  << "Boost version: " << BOOST_VERSION << std::endl
				  << "GCC version: " << __VERSION__ << std::endl
#ifdef __x86_64
				  << "x86_64: " << __x86_64 << std::endl
#endif
				  << "---" << std::endl;
		return 0;
	}

	boost::shared_ptr<HypergrapheAbstrait> ptrHpg;

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

		boost::shared_ptr<HypergrapheAbstrait> ptrHpg2;

		std::ifstream ifs(vm["isomorph"].as<std::string>(), std::ifstream::in);

		ReaderFile fReader;
		fReader.readHypergraphe( ifs );
		ifs.close();

		ptrHpg2 = fReader.getHypergraphe();

		NewAlgorithm2(isomorphHpg, Isomorph, ptrHpg, ptrHpg2);

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
		NewAlgorithm(statHpg, HyperGraphStat, ptrHpg);

		MotorAlgorithm::setAlgorithme( statHpg );
		MotorAlgorithm::runAlgorithme();

		boost::shared_ptr<HyperGraphStat> s = boost::static_pointer_cast<HyperGraphStat>( statHpg );

		std::cout << "Hyper-vertex : " << s->getNbrHyperVertex() << std::endl
				  << "Hyper-edge   : " << s->getNbrHyperEdge()   << std::endl
				  << "Nbr. links   : " << s->getNbrLinks()       << std::endl
				  << "Rang         : " << s->getRang()           << std::endl
				  << "Co-rang      : " << s->getCoRang()         << std::endl;

		return 0;
	}

	if( vm.count("dual") ) {

		NewAlgorithm(dualAlgo, Dual, ptrHpg);

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
		boost::shared_ptr<AlgorithmeAbstrait> kuniformAlgo( new kUniform( ptrHpg, vm["kuniform"].as<int>() ) );
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

	if( vm.count("linear") ) {

		NewAlgorithm(linearAlgo, Linear, ptrHpg);

		MotorAlgorithm::setAlgorithme( linearAlgo );
		MotorAlgorithm::runAlgorithme();

		RStructure r( linearAlgo->getResult() );
		if( r.getBooleanResult() ) {
			std::cout << "L'hypergraphe est Linéaire." << std::endl;
		} else {
			std::cout << "L'hypergraphe n'est pas Linéaire." << std::endl;
		}

		return 0;
	}

	if( vm.count("helly") ) {
		NewAlgorithm(hellyAlgo, Helly, ptrHpg);

		MotorAlgorithm::setAlgorithme( hellyAlgo );
		MotorAlgorithm::runAlgorithme();

		RStructure r( hellyAlgo->getResult() );
		if( r.getBooleanResult() ) {
			std::cout << "L'hypergraphe est Helly." << std::endl;
		} else {
			std::cout << "L'hypergraphe n'est pas Helly." << std::endl;
		}
		return 0;
	}

	if( vm.count("kregular") ) {
		NewAlgorithm(kregularAlgo, kRegular, ptrHpg);

		MotorAlgorithm::setAlgorithme( kregularAlgo );
		MotorAlgorithm::runAlgorithme();

		RStructure r( kregularAlgo->getResult() );
		if( r.getBooleanResult() ) {
			std::cout << "L'hypergraphe est k-regulier." << std::endl;
		} else {
			std::cout << "L'hypergraphe n'est pas k-regulier." << std::endl;
		}

		return 0;
	}

	if( vm.count("simple") ) {
		NewAlgorithm(simpleAlgo, Simple, ptrHpg);

		MotorAlgorithm::setAlgorithme( simpleAlgo );
		MotorAlgorithm::runAlgorithme();

		RStructure r( simpleAlgo->getResult() );
		if( r.getBooleanResult() ) {
			std::cout << "L'hypergraphe est simple." << std::endl;
		} else {
			std::cout << "L'hypergraphe n'est pas simple." << std::endl;
		}

		return 0;
	}

	if(vm.count("path") ) {
		boost::shared_ptr<Path> pathAlgo( new Path( ptrHpg ) );

		pathAlgo->setHyperVertex(
				ptrHpg->getHyperVertexById(vm["source"].as<int>()),
				ptrHpg->getHyperVertexById(vm["destination"].as<int>() )
			);

		boost::shared_ptr<AlgorithmeAbstrait> algoPathAbstrait( pathAlgo );

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

	if( vm.count("connexe") ) {
		NewAlgorithm(algoConnected, Connected, ptrHpg);

		MotorAlgorithm::setAlgorithme( algoConnected );
		MotorAlgorithm::runAlgorithme();

		RStructure r( algoConnected->getResult() );
		if( r.getBooleanResult() ) {
			std::cout << "L'hypergraphe est connexe." << std::endl;
		} else {
			std::cout << "L'hypergraphe n'est pas connexe." << std::endl;
		}

		return 0;
	}

	if( vm.count("adjacence") ) {
		WriterFile w( ptrHpg );
		w.writeAdjacentMatrix( std::cout );
	} else {
		WriterFile w( ptrHpg );
		w.writeHypergraph( std::cout );
	}

	return 0;
}

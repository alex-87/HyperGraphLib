
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

#include "../model/include/Hypergraphe.hh"
#include "../model/include/HyperFactory.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"
#include "../model/include/MotorAlgorithm.hh"

#include "../algorithm/include/Dual.hh"
#include "../algorithm/include/Helly.hh"
#include "../algorithm/include/kRegular.hh"
#include "../algorithm/include/kUniform.hh"
#include "../algorithm/include/Simple.hh"
#include "../algorithm/include/Linear.hh"
#include "../algorithm/include/Connected.hh"
#include "../algorithm/include/HyperGraphStat.hh"

#include "../io/include/WriterFile.hh"
#include "../io/include/ReaderFile.hh"


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
					("stat", "Retourne les statistiques de l'hypergraphe");

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

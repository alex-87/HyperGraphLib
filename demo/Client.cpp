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
#include "include/RandomHypergraph.hh"

#include "../include/Hypergraph/model/LibType.hh"
#include "../include/Hypergraph/model/Hypergraph.hh"
#include "../include/Hypergraph/model/HyperFactory.hh"
#include "../include/Hypergraph/model/HyperVertex.hh"
#include "../include/Hypergraph/model/HyperEdge.hh"
#include "../include/Hypergraph/model/AlgorithmEngine.hh"

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
static int runBooleanAlgorithm(std::shared_ptr<AbstractHypergraph>& ptrHpg,
                               const std::string& whenTrue,
                               const std::string& whenFalse) {
	auto algo = makeAlgorithm<Algorithm>(ptrHpg);
	AlgorithmEngine::set(algo);
	AlgorithmEngine::run();

	ResultStructure r(algo->getResult());
	std::cout << (r.getBooleanResult() ? whenTrue : whenFalse) << std::endl;
	return 0;
}

int main(int argc, char* argv[]) {
	po::options_description desc("Parameters");
	desc.add_options()("version", "Print the version")("help", "Print help message")("inputfile", po::value<std::string>(), "Input file")("random", po::value<int>(), "Random n-vertex Hypergraph")("adjacence", "Print adjacent matrix of the hypergraph")("dual", "Produce the Dual of the hypergraph")("kuniform", po::value<int>(), "Decide whether the hypergraph is k-uniforme")("linear", "Decide whether the hypergraph is linear")("kregular", "Decide whether the hypergraph is k-regular")("simple", "Decide whether the hypergraph is simple")("helly", "Decide whether the hypergraph has the Helly property")("connected", "Decide whether the hypergraph is connected")("isomorph", po::value<std::string>(), "Decide whether the hypergraph is isomorph")("stat", "Print hypergraph stats")("path", "Compute the path")("source", po::value<int>(), "Source of the path")("destination", po::value<int>(), "Destination of the path");
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

	if (vm.count("version")) {
		std::cout << "HypergraphLib "
		          << VERSION_MAJOR << "."
		          << VERSION_MINOR << "."
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

	std::shared_ptr<AbstractHypergraph> ptrHpg;

	if (vm.count("inputfile") && vm.count("random") == 0) {
		std::ifstream ifs(vm["inputfile"].as<std::string>(), std::ifstream::in);

		ReaderFile fReader;
		fReader.readHypergraph(ifs);
		ifs.close();

		ptrHpg = fReader.getHypergraph();

	} else if (vm.count("inputfile") == 0 && vm.count("random") == 0) {
		ReaderFile fReader;
		fReader.readHypergraph(std::cin);
		ptrHpg = fReader.getHypergraph();
	}

	// Isomorphism special parameters configuration
	if (vm.count("isomorph") && vm.count("inputfile")) {
		std::shared_ptr<AbstractHypergraph> ptrHpg2;

		std::ifstream ifs(vm["isomorph"].as<std::string>(), std::ifstream::in);

		ReaderFile fReader;
		fReader.readHypergraph(ifs);
		ifs.close();

		ptrHpg2 = fReader.getHypergraph();

		auto isomorphHpg = makeAlgorithm<Isomorph>(ptrHpg, ptrHpg2);

		AlgorithmEngine::set(isomorphHpg);
		AlgorithmEngine::run();

		ResultStructure r(isomorphHpg->getResult());

		if (r.getBooleanResult()) {
			std::cout << "The hypergraph isomorph." << std::endl;
		} else {
			std::cout << "The hypergraph is not isomorph." << std::endl;
		}

		return 0;
	}

	if (vm.count("random")) {
		RandomHypergraph rHyp;
		rHyp.generateHypergraph(vm["random"].as<int>(), vm["random"].as<int>());
		ptrHpg = rHyp.getHypergraph();
	}

	if (vm.count("stat")) {
		auto statHpg = makeAlgorithm<HyperGraphStat>(ptrHpg);

		AlgorithmEngine::set(statHpg);
		AlgorithmEngine::run();

		std::shared_ptr<HyperGraphStat> s = std::static_pointer_cast<HyperGraphStat>(statHpg);

		std::cout << "Hyper-vertex : " << s->getNbrHyperVertex() << std::endl
		          << "Hyper-edge   : " << s->getNbrHyperEdge() << std::endl
		          << "Nbr. links   : " << s->getNbrLinks() << std::endl
		          << "Rank         : " << s->getRang() << std::endl
		          << "Co-rank      : " << s->getCoRang() << std::endl;

		return 0;
	}

	if (vm.count("dual")) {
		auto dualAlgo = makeAlgorithm<Dual>(ptrHpg);

		AlgorithmEngine::set(dualAlgo);
		AlgorithmEngine::run();

		ResultStructure r(dualAlgo->getResult());

		WriterFile w(r.getHypergraphResult());
		if (vm.count("adjacence")) {
			w.writeAdjacentMatrix(std::cout);
		} else {
			w.writeHypergraph(std::cout);
		}

		return 0;
	}

	if (vm.count("kuniform")) {
		std::shared_ptr<AbstractAlgorithm> kuniformAlgo(new kUniform(ptrHpg, vm["kuniform"].as<int>()));
		AlgorithmEngine::set(kuniformAlgo);
		AlgorithmEngine::run();

		ResultStructure r(kuniformAlgo->getResult());
		if (r.getBooleanResult()) {
			std::cout << "The hypergraph is " << vm["kuniform"].as<int>() << "-uniform." << std::endl;
		} else {
			std::cout << "The hypergraph is not " << vm["kuniform"].as<int>() << "-uniform." << std::endl;
		}

		return 0;
	}

	if (vm.count("linear"))
		return runBooleanAlgorithm<Linear>(ptrHpg,
		                                   "The hypergraph is linear.", "The hypergraph is not linear.");

	if (vm.count("helly"))
		return runBooleanAlgorithm<Helly>(ptrHpg,
		                                  "The hypergraph is Helly.", "The hypergraph is not Helly.");

	if (vm.count("kregular"))
		return runBooleanAlgorithm<kRegular>(ptrHpg,
		                                     "The hypergraph is k-regulier.", "The hypergraph is not k-regulier.");

	if (vm.count("simple"))
		return runBooleanAlgorithm<Simple>(ptrHpg,
		                                   "The hypergraph is simple.", "The hypergraph is not simple.");

	if (vm.count("path")) {
		std::shared_ptr<Path> pathAlgo(new Path(ptrHpg));

		pathAlgo->setHyperVertex(
		    ptrHpg->getHyperVertexById(vm["source"].as<int>()),
		    ptrHpg->getHyperVertexById(vm["destination"].as<int>()));

		std::shared_ptr<AbstractAlgorithm> algoPathAbstract(pathAlgo);

		AlgorithmEngine::set(algoPathAbstract);
		AlgorithmEngine::run();

		ResultStructurePath r(pathAlgo->getPathResult());

		for (unsigned int i = 0; i < r.getPathResult()->size(); i++) {
			LibType::ListHyperVertex hvl(r.getPathResult()->at(i));
			for (unsigned int j = 0; j < hvl.size(); j++) {
				std::cout << hvl.at(j)->getIdentifier() << " ";
			}
			std::cout << std::endl;
		}
	}

	if (vm.count("connected"))
		return runBooleanAlgorithm<Connected>(ptrHpg,
		                                      "The hypergraph is conected.", "The hypergraph is not connected.");

	if (vm.count("adjacence")) {
		WriterFile w(ptrHpg);
		w.writeAdjacentMatrix(std::cout);
	} else {
		WriterFile w(ptrHpg);
		w.writeHypergraph(std::cout);
	}

	return 0;
}

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


#include "Hypergraph/io/ReaderFile.hh"
#include "Hypergraph/model/Hypergraph.hh"

#include <string>
#include <sstream>
#include <stdexcept>

ReaderFile::ReaderFile()
    : AbstractReader(std::shared_ptr<AbstractHypergraph>(new Hypergraph())) {
}

void ReaderFile::readHypergraph(std::istream& input) {
	readHypergraphHyperVertex(input);
	readHypergraphHyperEdge(input);

	unsigned int vertex(0);
	unsigned int edge(0);

	input >> edge;
	input >> vertex;

	while (input) {
		_ptrAbstractHypergraph->link(hyperVertexById(vertex), hyperEdgeById(edge));

		input >> edge;
		input >> vertex;
	};
}

void ReaderFile::readHypergraphHyperVertex(std::istream& input) {
	std::string s;
	std::getline(input, s);

	std::stringstream k(s);

	unsigned int i(0);
	while (k >> i) {
		_hyperVertexByFileId[i] = _ptrAbstractHypergraph->addHyperVertex();
	}
}

void ReaderFile::readHypergraphHyperEdge(std::istream& input) {
	std::string s;
	std::getline(input, s);

	std::stringstream k(s);

	unsigned int i(0);
	while (k >> i) {
		_hyperEdgeByFileId[i] = _ptrAbstractHypergraph->addHyperEdge();
	}
}

const std::shared_ptr<HyperVertex>&
ReaderFile::hyperVertexById(unsigned int id) const {
	auto it = _hyperVertexByFileId.find(id);
	if (it == _hyperVertexByFileId.end())
		throw std::invalid_argument("ReaderFile: unknown hypervertex identifier " + std::to_string(id));
	return it->second;
}

const std::shared_ptr<HyperEdge>&
ReaderFile::hyperEdgeById(unsigned int id) const {
	auto it = _hyperEdgeByFileId.find(id);
	if (it == _hyperEdgeByFileId.end())
		throw std::invalid_argument("ReaderFile: unknown hyperedge identifier " + std::to_string(id));
	return it->second;
}

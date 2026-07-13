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


#include "Hypergraph/model/HyperFactory.hh"
#include <iostream>

HyperFactory::HyperFactory() {
}

void HyperFactory::startSession(std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph) {
	_ptrAbstractHypergraph = ptrAbstractHypergraph;
	_indexVertex = _ptrAbstractHypergraph->getHyperVertexList().size();
	_indexEdge = _ptrAbstractHypergraph->getHyperEdgeList().size();
	_isSession = true;
}

const std::shared_ptr<HyperVertex>
HyperFactory::newHyperVertex() {
	_indexVertex++;
	unsigned int u(_indexVertex - 1);
	return std::shared_ptr<HyperVertex>(new HyperVertex(_ptrAbstractHypergraph, u));
}

const std::shared_ptr<HyperEdge>
HyperFactory::newHyperEdge() {
	_indexEdge++;
	unsigned int u(_indexEdge - 1);
	return std::shared_ptr<HyperEdge>(new HyperEdge(_ptrAbstractHypergraph, u));
}

void HyperFactory::link(std::shared_ptr<HyperVertex>& hyperVertex, std::shared_ptr<HyperEdge>& hyperEdge) {
	hyperVertex->addHyperEdge(hyperEdge);
	hyperEdge->addHyperVertex(hyperVertex);
}

bool HyperFactory::isSession() {
	return _isSession;
}

void HyperFactory::closeSession() {
	_ptrAbstractHypergraph.reset();
	_isSession = false;
}


unsigned int HyperFactory::_indexVertex = 0;
unsigned int HyperFactory::_indexEdge = 0;
bool HyperFactory::_isSession = false;
std::shared_ptr<AbstractHypergraph> HyperFactory::_ptrAbstractHypergraph = nullptr;

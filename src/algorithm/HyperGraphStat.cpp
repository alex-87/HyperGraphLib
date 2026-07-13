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


#include "Hypergraph/algorithm/HyperGraphStat.hh"
#include "Hypergraph/model/AdjacentMatrix.hh"

HyperGraphStat::HyperGraphStat(const std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph) {
	_ptrAbstractHypergraph = ptrAbstractHypergraph;
	_nhEdge = 0;
	_nhVertex = 0;
	_nhLink = 0;
	_rank = 0;
	_coRank = 0;
}

unsigned int
HyperGraphStat::getNbrHyperEdge() const {
	return _nhEdge;
}

unsigned int
HyperGraphStat::getNbrHyperVertex() const {
	return _nhVertex;
}

unsigned int
HyperGraphStat::getNbrLinks() const {
	return _nhLink;
}

unsigned int
HyperGraphStat::getRang() const {
	return _rank;
}

unsigned int
HyperGraphStat::getCoRang() const {
	return _coRank;
}

void HyperGraphStat::run() {
	_nhEdge = _ptrAbstractHypergraph->getHyperEdgeList().size();
	_nhVertex = _ptrAbstractHypergraph->getHyperVertexList().size();

	AdjacentMatrix m(_ptrAbstractHypergraph->getAdjacentMatrix());

	_rank = m.getRank();
	_coRank = m.getCoRank();
}

ResultStructure
HyperGraphStat::getResult() const {
	return _result;
}

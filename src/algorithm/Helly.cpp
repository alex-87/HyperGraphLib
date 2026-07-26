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


#include "Hypergraph/algorithm/Helly.hh"
#include "Hypergraph/model/Hypergraphe.hh"
#include "Hypergraph/model/HyperVertex.hh"
#include "Hypergraph/model/HyperEdge.hh"

Helly::Helly(const std::shared_ptr<HypergrapheAbstrait>& ptrAbstractHypergraph)
    : _ptrAbstractHypergraph(ptrAbstractHypergraph) {
}

void Helly::runAlgorithme() {
	_result.setBooleanResult(true);

	for (auto& x : _ptrAbstractHypergraph->getHyperVertexList()) {
		for (auto& y : _ptrAbstractHypergraph->getHyperVertexList()) {
			LibType::ListHyperEdge X_xy(allContainXY(x, y));
			for (auto& v : _ptrAbstractHypergraph->getHyperVertexList()) {
				if (areNeighbours(x, v) && areNeighbours(y, v)) {
					LibType::ListHyperEdge X_xv(allContainXY(x, v));
					LibType::ListHyperEdge X_yv(allContainXY(y, v));

					LibType::ListHyperEdge X;
					concatenate(X, X_xy);
					concatenate(X, X_xv);
					concatenate(X, X_yv);

					if (!nonEmptyIntersection(X)) {
						_result.setBooleanResult(false);
						return;
					}
				}
			}
		}
	}
}

bool Helly::areNeighbours(std::shared_ptr<HyperVertex>& v1, std::shared_ptr<HyperVertex>& v2) {
	for (auto& element1 : v1->getHyperEdgeList()) {
		for (auto& element2 : v2->getHyperEdgeList()) {
			if (element1 == element2) {
				return true;
			}
		}
	}
	return false;
}

void Helly::concatenate(LibType::ListHyperEdge& dest, LibType::ListHyperEdge& src) {
	dest.insert(dest.end(), src.begin(), src.end());
}

bool Helly::nonEmptyIntersection(LibType::ListHyperEdge& edges) {
	for (unsigned int i = 0; i < edges.size(); i++) {
		for (unsigned int j = i + 1; j < edges.size(); j++) {
			if (!nonEmptyBetween(edges.at(i), edges.at(j)))
				return false;
		}
	}
	return true;
}

bool Helly::nonEmptyBetween(std::shared_ptr<HyperEdge>& e1, std::shared_ptr<HyperEdge>& e2) {
	for (auto& a : e1->getHyperVertexList()) {
		for (auto& b : e2->getHyperVertexList()) {
			if (a == b)
				return true;
		}
	}
	return false;
}

LibType::ListHyperEdge
Helly::allContainXY(std::shared_ptr<HyperVertex>& v1, std::shared_ptr<HyperVertex>& v2) {
	LibType::ListHyperEdge elist;
	for (auto& e : _ptrAbstractHypergraph->getHyperEdgeList()) {
		if (e->containVertex(v1) && e->containVertex(v2)) {
			elist.push_back(e);
		}
	}
	return elist;
}

RStructure
Helly::getResult() const {
	return _result;
}

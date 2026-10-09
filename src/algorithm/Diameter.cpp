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


#include "Hypergraph/algorithm/Diameter.hh"
#include "Hypergraph/model/HyperVertex.hh"
#include "Hypergraph/model/HyperEdge.hh"

#include <algorithm>
#include <queue>
#include <vector>


Diameter::Diameter(const std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph)
    : _ptrAbstractHypergraph(ptrAbstractHypergraph),
      _diameter(0) {
}

unsigned int
Diameter::getDiameter() const {
	return _diameter;
}

void Diameter::run() {
	const LibType::ListHyperVertex& listVertex(_ptrAbstractHypergraph->getHyperVertexList());
	const LibType::ListHyperEdge& listEdge(_ptrAbstractHypergraph->getHyperEdgeList());

	// Edges of each vertex, built once from the hyperedges.
	std::vector<std::vector<unsigned int>> edgesOfVertex(listVertex.size());
	for (const auto& hyperEdge : listEdge) {
		for (const auto& hyperVertex : hyperEdge->getHyperVertexList()) {
			edgesOfVertex[hyperVertex->getIdentifier()].push_back(hyperEdge->getIdentifier());
		}
	}

	_diameter = 0;
	for (unsigned int source = 0; source < listVertex.size(); source++) {
		const unsigned int distance(eccentricity(source, edgesOfVertex));
		if (distance == INFINITE_DIAMETER) {
			// One vertex cannot reach another: the hypergraph is not connected.
			_diameter = INFINITE_DIAMETER;
			break;
		}
		_diameter = std::max(_diameter, distance);
	}

	_result.setBooleanResult(_diameter != INFINITE_DIAMETER);
}

unsigned int
Diameter::eccentricity(unsigned int source, const std::vector<std::vector<unsigned int>>& edgesOfVertex) const {
	const LibType::ListHyperEdge& listEdge(_ptrAbstractHypergraph->getHyperEdgeList());

	std::vector<unsigned int> distance(edgesOfVertex.size(), INFINITE_DIAMETER);
	std::vector<bool> edgeVisited(listEdge.size(), false);
	std::queue<unsigned int> toVisit;

	distance[source] = 0;
	toVisit.push(source);

	unsigned int nbReached(1);
	unsigned int farthest(0);

	while (!toVisit.empty()) {
		const unsigned int current(toVisit.front());
		toVisit.pop();

		for (const unsigned int edgeId : edgesOfVertex[current]) {
			if (edgeVisited[edgeId])
				continue;
			edgeVisited[edgeId] = true;

			for (const auto& hyperVertex : listEdge[edgeId]->getHyperVertexList()) {
				const unsigned int next(hyperVertex->getIdentifier());
				if (distance[next] == INFINITE_DIAMETER) {
					distance[next] = distance[current] + 1;
					farthest = std::max(farthest, distance[next]);
					nbReached++;
					toVisit.push(next);
				}
			}
		}
	}

	return nbReached == edgesOfVertex.size() ? farthest : INFINITE_DIAMETER;
}

ResultStructure
Diameter::getResult() const {
	return _result;
}

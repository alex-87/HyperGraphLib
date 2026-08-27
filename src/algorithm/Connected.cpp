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


#include "Hypergraph/algorithm/Connected.hh"
#include "Hypergraph/model/Hypergraph.hh"
#include "Hypergraph/model/HyperVertex.hh"
#include "Hypergraph/model/HyperEdge.hh"
#include <stack>


Connected::Connected(std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph)
    : _ptrAbstractHypergraph(ptrAbstractHypergraph) {
}

void Connected::run() {
	if (_ptrAbstractHypergraph->getHyperVertexList().size() == 0)
		return;

	const AdjacentMatrix& matrix(_ptrAbstractHypergraph->getAdjacentMatrix());

	std::stack<unsigned int> stackHyperVertex;
	std::stack<unsigned int> stackHyperEdge;

	std::vector<bool> hyperVertexVisited(matrix.getVertexCount(), false);
	std::vector<bool> hyperEdgeVisited(matrix.getEdgeCount(), false);
	unsigned int nbVertexVisited(0);

	_result.setBooleanResult(false);
	stackHyperVertex.push(_ptrAbstractHypergraph->getHyperVertexList().at(0)->getIdentifier());

	while (!stackHyperVertex.empty() || !stackHyperEdge.empty()) {
		while (!stackHyperVertex.empty() && hyperVertexVisited[stackHyperVertex.top()]) {
			stackHyperVertex.pop();
		}
		if (!stackHyperVertex.empty()) {
			unsigned int u(stackHyperVertex.top());

			stackHyperVertex.pop();
			exploreVertical(matrix, hyperEdgeVisited, stackHyperEdge, u);
			hyperVertexVisited[u] = true;
			nbVertexVisited++;
		}
		while (!stackHyperEdge.empty() && hyperEdgeVisited[stackHyperEdge.top()]) {
			stackHyperEdge.pop();
		}
		if (!stackHyperEdge.empty()) {
			unsigned int v(stackHyperEdge.top());

			stackHyperEdge.pop();
			exploreHorizontal(matrix, hyperVertexVisited, stackHyperVertex, v);
			hyperEdgeVisited[v] = true;
		}
	}
	_result.setBooleanResult(nbVertexVisited == matrix.getVertexCount());
}

void Connected::exploreVertical(const AdjacentMatrix& matrix, const std::vector<bool>& visited, std::stack<unsigned int>& stack, unsigned int idVert) const {
	for (unsigned int i = 0; i < matrix.getEdgeCount(); i++) {
		if (matrix.isVertexInEdge(idVert, i) && !visited[i]) {
			stack.push(i);
		}
	}
}

void Connected::exploreHorizontal(const AdjacentMatrix& matrix, const std::vector<bool>& visited, std::stack<unsigned int>& stack, unsigned int idHor) const {
	for (unsigned int i = 0; i < matrix.getVertexCount(); i++) {
		if (matrix.isVertexInEdge(i, idHor) && !visited[i]) {
			stack.push(i);
		}
	}
}

ResultStructure
Connected::getResult() const {
	return _result;
}

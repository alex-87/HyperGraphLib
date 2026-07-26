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
#include "Hypergraph/model/Hypergraphe.hh"
#include "Hypergraph/model/HyperVertex.hh"
#include "Hypergraph/model/HyperEdge.hh"
#include <iostream>
#include <stack>
#include <algorithm>

#define TRACE_ALGORITHM_CONNECTED 0

Connected::Connected(std::shared_ptr<HypergrapheAbstrait>& ptrAbstractHypergraph)
    : _ptrAbstractHypergraph(ptrAbstractHypergraph) {
}

void Connected::runAlgorithme() {
	if (_ptrAbstractHypergraph->getHyperVertexList().size() == 0)
		return;

	LibType::AdjacentMatrixContainerBool matrix(_ptrAbstractHypergraph->getAdjacentMatrix().getBoolAdjacentMatrix());

	std::stack<unsigned int> stackHyperVertex;
	std::stack<unsigned int> stackHyperEdge;

	std::vector<unsigned int> listConnectedVisited;
	std::vector<unsigned int> listHyperEdgeVisited;

	_result.setBooleanResult(false);
	stackHyperVertex.push(_ptrAbstractHypergraph->getHyperVertexList().at(0)->getIdentifier());

#if (TRACE_ALGORITHM_CONNECTED)
	std::cout << "PUSH [vertex]: " << _ptrAbstractHypergraph->getHyperVertexList().at(0)->getIdentifier() << std::endl;
#endif

	while (!stackHyperVertex.empty() || !stackHyperEdge.empty()) {
#if (TRACE_ALGORITHM_CONNECTED)
		std::cout << "Purge[vrtx]...";
#endif
		while (!stackHyperVertex.empty() && isVertexVisited(listConnectedVisited, stackHyperVertex.top())) {
			stackHyperVertex.pop();
		}
#if (TRACE_ALGORITHM_CONNECTED)
		std::cout << " ok." << std::endl;

		std::cout << "*** size(Stack[vrtx]): " << stackHyperVertex.size() << std::endl;
#endif
		if (!stackHyperVertex.empty()) {
			unsigned int u(stackHyperVertex.top());

			stackHyperVertex.pop();
#if (TRACE_ALGORITHM_CONNECTED)
			std::cout << "POP [vertex]: " << u << std::endl;
#endif
			exploreVertical(listHyperEdgeVisited, stackHyperEdge, u);
#if (TRACE_ALGORITHM_CONNECTED)
			std::cout << "STOR [vertex]: " << u << std::endl;
#endif
			listConnectedVisited.push_back(u);
		}
#if (TRACE_ALGORITHM_CONNECTED)
		std::cout << "Purge[edge]...";
#endif
		while (!stackHyperEdge.empty() && isEdgeVisited(listHyperEdgeVisited, stackHyperEdge.top())) {
			stackHyperEdge.pop();
		}
#if (TRACE_ALGORITHM_CONNECTED)
		std::cout << " ok." << std::endl;
		std::cout << "*** size(Stack[edge]): " << stackHyperEdge.size() << std::endl;
#endif
		if (!stackHyperEdge.empty()) {
			unsigned int v(stackHyperEdge.top());

			stackHyperEdge.pop();
#if (TRACE_ALGORITHM_CONNECTED)
			std::cout << "POP [edge]: " << v << std::endl;
#endif
			exploreHorizontal(listConnectedVisited, stackHyperVertex, v);
#if (TRACE_ALGORITHM_CONNECTED)
			std::cout << "STOR [edge]: " << v << std::endl;
#endif
			listHyperEdgeVisited.push_back(v);
		}
#if (TRACE_ALGORITHM_CONNECTED)
		std::cout << "*** Stack[edge]: " << stackHyperEdge.size() << " elements" << std::endl;
		std::cout << "*** Stack[vrtx]: " << stackHyperVertex.size() << " elements" << std::endl;
#endif
	}
#if (TRACE_ALGORITHM_CONNECTED)
	std::cout << "Finished: " << listConnectedVisited.size() << " =?= " << _ptrAbstractHypergraph->getHyperVertexList().size() << std::endl;
#endif
	_result.setBooleanResult(listConnectedVisited.size() == _ptrAbstractHypergraph->getHyperVertexList().size());
}

void Connected::exploreVertical(std::vector<unsigned int>& listVisited, std::stack<unsigned int>& stack, unsigned int idVert) {
	LibType::AdjacentMatrixContainerBool
	    matrix(_ptrAbstractHypergraph->getAdjacentMatrix().getBoolAdjacentMatrix());

	std::tuple<unsigned int, unsigned int>
	    dim = _ptrAbstractHypergraph->getAdjacentMatrix().getMatrixDimension();

	for (unsigned int i = 0; i < std::get<0>(dim); i++) {
		if (matrix(idVert, i) && !isEdgeVisited(listVisited, i)) {
#if (TRACE_ALGORITHM_CONNECTED)
			std::cout << "-> PUSH [edge]: " << i << std::endl;
#endif
			stack.push(i);
		}
	}
}

void Connected::exploreHorizontal(std::vector<unsigned int>& listVisited, std::stack<unsigned int>& stack, unsigned int idHor) {
	LibType::AdjacentMatrixContainerBool
	    matrix(_ptrAbstractHypergraph->getAdjacentMatrix().getBoolAdjacentMatrix());

	std::tuple<unsigned int, unsigned int>
	    dim = _ptrAbstractHypergraph->getAdjacentMatrix().getMatrixDimension();

	for (unsigned int i = 0; i < std::get<1>(dim); i++) {
		if (matrix(i, idHor) && !isVertexVisited(listVisited, i)) {
#if (TRACE_ALGORITHM_CONNECTED)
			std::cout << "-> PUSH [vertex]: " << i << std::endl;
#endif
			stack.push(i);
		}
	}
}

bool Connected::isVertexVisited(std::vector<unsigned int>& list, unsigned int vertex) const {
	return std::find(list.begin(), list.end(), vertex) != list.end();
}

bool Connected::isEdgeVisited(std::vector<unsigned int>& list, unsigned int edge) const {
	return std::find(list.begin(), list.end(), edge) != list.end();
}

RStructure
Connected::getResult() const {
	return _result;
}

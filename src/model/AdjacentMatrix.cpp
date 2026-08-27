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


#include "Hypergraph/model/AdjacentMatrix.hh"
#include "Hypergraph/model/HyperVertex.hh"
#include "Hypergraph/model/HyperEdge.hh"

#include <algorithm>

AdjacentMatrix::AdjacentMatrix() {
}

AdjacentMatrix::AdjacentMatrix(const LibType::ListHyperVertex& listHyperVertex, const LibType::ListHyperEdge& listHyperEdge)
    : _adjacentMatrixBool(listHyperVertex.size(), listHyperEdge.size()),
      _vertexDegree(listHyperVertex.size(), 0),
      _edgeSize(listHyperEdge.size(), 0) {
	for (const auto& hyperEdge : listHyperEdge) {
		const unsigned int edgeId(hyperEdge->getIdentifier());
		for (const auto& hyperVertex : hyperEdge->getHyperVertexList()) {
			const unsigned int vertexId(hyperVertex->getIdentifier());
			_adjacentMatrixBool(vertexId, edgeId) = true;
			_vertexDegree[vertexId]++;
			_edgeSize[edgeId]++;
		}
	}
}

unsigned int AdjacentMatrix::getVertexDegree(const std::shared_ptr<HyperVertex>& hyperVertex) const {
	return _vertexDegree.at(hyperVertex->getIdentifier());
}

unsigned int
AdjacentMatrix::getEdgeSize(const std::shared_ptr<HyperEdge>& hyperEdge) const {
	return _edgeSize.at(hyperEdge->getIdentifier());
}

unsigned int
AdjacentMatrix::getVertexCount() const {
	return _adjacentMatrixBool.rows();
}

unsigned int
AdjacentMatrix::getEdgeCount() const {
	return _adjacentMatrixBool.cols();
}

bool AdjacentMatrix::isVertexInEdge(unsigned int vertexId, unsigned int edgeId) const {
	if (vertexId >= getVertexCount() || edgeId >= getEdgeCount())
		return false;
	return _adjacentMatrixBool(vertexId, edgeId);
}

bool AdjacentMatrix::isVertexInEdge(const std::shared_ptr<HyperVertex>& hVertex, const std::shared_ptr<HyperEdge>& hEdge) const {
	return isVertexInEdge(hVertex->getIdentifier(), hEdge->getIdentifier());
}

unsigned int
AdjacentMatrix::getCoRank() const {
	if (_edgeSize.empty())
		return 0;
	return *std::min_element(_edgeSize.begin(), _edgeSize.end());
}

unsigned int
AdjacentMatrix::getRank() const {
	if (_edgeSize.empty())
		return 0;
	return *std::max_element(_edgeSize.begin(), _edgeSize.end());
}

const LibType::AdjacentMatrixContainerBool&
AdjacentMatrix::getBoolAdjacentMatrix() const {
	return _adjacentMatrixBool;
}

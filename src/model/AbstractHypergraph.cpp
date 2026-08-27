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


#include "Hypergraph/model/AbstractHypergraph.hh"
#include "Hypergraph/model/HyperVertex.hh"
#include "Hypergraph/model/HyperEdge.hh"

AbstractHypergraph::AbstractHypergraph()
    : _isAdjacentMatrixOutdated(false) {
}

const LibType::ListHyperVertex&
AbstractHypergraph::getHyperVertexList() const {
	return _listHyperVertex;
}

const LibType::ListHyperEdge&
AbstractHypergraph::getHyperEdgeList() const {
	return _listHyperEdge;
}

const std::shared_ptr<HyperVertex>&
AbstractHypergraph::getHyperVertexById(unsigned int id) const {
	return _listHyperVertex.at(id);
}

const std::shared_ptr<HyperEdge>&
AbstractHypergraph::getHyperEdgeById(unsigned int id) const {
	return _listHyperEdge.at(id);
}

const AdjacentMatrix&
AbstractHypergraph::getAdjacentMatrix() const {
	if (_isAdjacentMatrixOutdated) {
		_adjacentMatrix = AdjacentMatrix(_listHyperVertex, _listHyperEdge);
		_isAdjacentMatrixOutdated = false;
	}
	return _adjacentMatrix;
}

bool AbstractHypergraph::isHyperVertexInHyperEdge(const std::shared_ptr<HyperVertex>& hv, const std::shared_ptr<HyperEdge>& he) const {
	return getAdjacentMatrix().isVertexInEdge(hv, he);
}

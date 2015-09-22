
#include "include/HypergrapheAbstrait.hh"
#include "include/HyperVertex.hh"
#include "include/HyperEdge.hh"

HypergrapheAbstrait::HypergrapheAbstrait() : _adjacentMatrix(0, 0) {

}

LibType::IndexerHyperVertex&
HypergrapheAbstrait::getIndexHyperVertex() {
	return _indexHyperVertex;
}

LibType::IndexerHyperEdge&
HypergrapheAbstrait::getIndexHyperEdge() {
	return _indexHyperEdge;
}

LibType::ListHyperVertex&
HypergrapheAbstrait::getHyperVertexList() {
	return _listHyperVertex;
}

LibType::ListHyperEdge&
HypergrapheAbstrait::getHyperEdgeList() {
	return _listHyperEdge;
}

AdjacentMatrix&
HypergrapheAbstrait::getAdjacentMatrix() {
	return _adjacentMatrix;
}

HypergrapheAbstrait::~HypergrapheAbstrait() {

}

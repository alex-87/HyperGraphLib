
#include "include/HyperFactory.hh"
#include <iostream>

HyperFactory::HyperFactory() {
}

HyperFactory& HyperFactory::Instance() {
	return _instance;
}

void
HyperFactory::startSession(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) {

	_ptrHypergrapheAbstrait = ptrHypergrapheAbstrait;
	_indexVertex = _ptrHypergrapheAbstrait->getHyperVertexList().size();
	_indexEdge   = _ptrHypergrapheAbstrait->getHyperEdgeList().size();
	_isSession = true;
}

const boost::shared_ptr<HyperVertex>
HyperFactory::newHyperVertex() {
	_indexVertex++;
	unsigned int u( _indexVertex - 1);
	return boost::shared_ptr<HyperVertex>( new HyperVertex(_ptrHypergrapheAbstrait, u) );
}

const boost::shared_ptr<HyperEdge>
HyperFactory::newHyperEdge() {
	_indexEdge++;
	unsigned int u( _indexEdge - 1);
	return boost::shared_ptr<HyperEdge>( new HyperEdge(_ptrHypergrapheAbstrait, u) );
}

void
HyperFactory::link(boost::shared_ptr<HyperVertex>& hyperVertex, boost::shared_ptr<HyperEdge>& hyperEdge) {
	hyperVertex->addHyperEdge(hyperEdge);
	hyperEdge->addHyperVertex(hyperVertex);
}

bool
HyperFactory::isSession() {
	return _isSession;
}

void
HyperFactory::closeSession() {
	_ptrHypergrapheAbstrait.reset();
	_isSession = false;
}

HyperFactory::~HyperFactory() {
}


HyperFactory HyperFactory::_instance = HyperFactory();
unsigned int HyperFactory::_indexVertex = 0;
unsigned int HyperFactory::_indexEdge = 0;
bool HyperFactory::_isSession = false;
boost::shared_ptr<HypergrapheAbstrait> HyperFactory::_ptrHypergrapheAbstrait = nullptr;

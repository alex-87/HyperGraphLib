
#include <boost/foreach.hpp>
#include "include/HyperGraphStat.hh"
#include "../model/include/AdjacentMatrix.hh"

HyperGraphStat::HyperGraphStat(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) {
	_ptrHypergrapheAbstrait = ptrHypergrapheAbstrait;

	_nhEdge   = 0;
	_nhVertex = 0;
	_nhLink   = 0;
	_rang     = 0;
	_coRang   = 0;
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
	return _rang;
}

unsigned int
HyperGraphStat::getCoRang() const {
	return _coRang;
}

void
HyperGraphStat::runAlgorithme() {

	_nhEdge = _ptrHypergrapheAbstrait->getHyperEdgeList().size();
	_nhVertex = _ptrHypergrapheAbstrait->getHyperVertexList().size();

	AdjacentMatrix m( _ptrHypergrapheAbstrait->getAdjacentMatrix() );
	LibType::ListHyperEdge eList( _ptrHypergrapheAbstrait->getHyperEdgeList() );

	_rang   = m.getRank();
	_coRang = m.getCoRank();
}

RStructure
HyperGraphStat::getResult() const {
	return _result;
}


HyperGraphStat::~HyperGraphStat() {

}

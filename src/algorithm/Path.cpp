
#include <boost/foreach.hpp>
#include "include/Path.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"

Path::Path(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) :
			_ptrHypergrapheAbstrait( ptrHypergrapheAbstrait ), _limite(0) {
}

RStructure
Path::getResult() const {
	return _result;
}

RStructurePath
Path::getPathResult() const {
	return _result;
}

void
Path::setLimit(unsigned int limite) {
	_limite = limite;
}

unsigned int
Path::getLimit() const {
	return _limite;
}

void
Path::setHyperVertex(boost::shared_ptr<HyperVertex>& source, boost::shared_ptr<HyperVertex>& destination) {
	_source = source;
	_destination = destination;
}

void Path::runAlgorithme() {

	LibType::PathList pathList( new boost::container::vector<LibType::ListHyperVertex>() );

	if( _source == _destination ) {
		LibType::ListHyperVertex listHyperVertex;
		listHyperVertex.push_back( _source );
		listHyperVertex.push_back( _destination );
		_result.setPathResult(pathList);
		return;
	}

	LibType::ListHyperVertex toVisitVertex;
	LibType::ListHyperVertex visitedVertex;
	LibType::ListHyperVertex currentPath;

	toVisitVertex.push_back(_source);

	while( (toVisitVertex.size() > 0) && (_limite > pathList->size() || _limite==0) ) {

		boost::shared_ptr<HyperVertex> currentHyperVertex( toVisitVertex.back() );
		visitedVertex.push_back( currentHyperVertex );
		toVisitVertex.pop_back();

		if( currentHyperVertex == _destination ) {
			currentPath.push_back( currentHyperVertex );
			buildPathToPathList(pathList, currentPath);
			currentPath.clear();
			currentHyperVertex = _source;
			toVisitVertex.clear();
			toVisitVertex.push_back(_source);
		}

		for(unsigned int cn = 0; cn < currentHyperVertex->getHyperEdgeList().size(); cn++) {
			addVertexList(visitedVertex, toVisitVertex, currentHyperVertex->getHyperEdgeList().at(cn) );
		}

		currentPath.push_back( currentHyperVertex );
	}

	_result.setPathResult(pathList);
}

void
Path::buildPathToPathList(LibType::PathList& pList, LibType::ListHyperVertex& vList) {

	LibType::ListHyperVertex tmpList;

	BOOST_FOREACH(boost::shared_ptr<HyperVertex> vPtr, vList) {
		tmpList.push_back(vPtr);
	}

	pList->push_back(tmpList);
}

void
Path::addVertexList(LibType::ListHyperVertex& noListe, LibType::ListHyperVertex& liste, const boost::shared_ptr<HyperEdge>& hyperEdge) const {

#pragma omp for schedule( dynamic )
	for(unsigned int i=0; i < hyperEdge->getHyperVertexList().size(); i++) {
		if( !vertexContained(noListe, hyperEdge->getHyperVertexList().at(i)) ) {
			liste.push_back( hyperEdge->getHyperVertexList().at(i) );
		}
	}
}

bool
Path::vertexContained(LibType::ListHyperVertex& liste, boost::shared_ptr<HyperVertex>& vertex) const {

#pragma omp for schedule( dynamic )
	for(unsigned int i=0; i<liste.size(); i++) {
		if( vertex == liste.at(i) ) {
			return true;
		}
	}
	return false;
}


Path::~Path() {
}

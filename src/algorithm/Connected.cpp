
#include "include/Connected.hh"
#include "../model/include/Hypergraphe.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"
#include <iostream>
#include <stack>

#define TRACE_ALGORITHM_CONNECTED 1

Connected::Connected(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) :
			_ptrHypergrapheAbstrait(ptrHypergrapheAbstrait) {

}

void
Connected::runAlgorithme() {

	if( _ptrHypergrapheAbstrait->getHyperVertexList().size()==0 )return;

	LibType::AdjacentMatrixContainerBool matrix( _ptrHypergrapheAbstrait->getAdjacentMatrix().getBoolAdjacentMatrix() );

	std::stack<unsigned int> stackHyperVertex;
	std::stack<unsigned int> stackHyperEdge;

	std::vector<unsigned int>  listConnectedVisited;
	std::vector<unsigned int>  listHyperEdgeVisited;

	_result.setBooleanResult(false);
	stackHyperVertex.push( _ptrHypergrapheAbstrait->getHyperVertexList().at(0).getIdentifier() );

#if(TRACE_ALGORITHM_CONNECTED)
	std::cout << "PUSH [vertex]: " << _ptrHypergrapheAbstrait->getHyperVertexList().at(0).getIdentifier() << std::endl;
#endif

	while( !stackHyperVertex.empty() || !stackHyperEdge.empty() ) {
#if(TRACE_ALGORITHM_CONNECTED)
		std::cout << "Purge[vrtx]...";
#endif
		while( !stackHyperVertex.empty() && isVertexVisited(listConnectedVisited, stackHyperVertex.top()) ) {
			stackHyperVertex.pop();
		}
#if(TRACE_ALGORITHM_CONNECTED)
		std::cout << " ok." << std::endl;

		std::cout << "*** size(Stack[vrtx]): " << stackHyperVertex.size() << std::endl;
#endif
		if( !stackHyperVertex.empty() ) {

			unsigned int u( stackHyperVertex.top() );

			stackHyperVertex.pop();
#if(TRACE_ALGORITHM_CONNECTED)
			std::cout << "POP [vertex]: " << u << std::endl;
#endif
			exploreVertical(listHyperEdgeVisited, stackHyperEdge, u);
#if(TRACE_ALGORITHM_CONNECTED)
			std::cout << "STOR [vertex]: " << u << std::endl;
#endif
			listConnectedVisited.push_back( u );
		}
#if(TRACE_ALGORITHM_CONNECTED)
		std::cout << "Purge[edge]...";
#endif
		while( !stackHyperEdge.empty() && isEdgeVisited(listHyperEdgeVisited, stackHyperEdge.top()) ) {
			stackHyperEdge.pop();
		}
#if(TRACE_ALGORITHM_CONNECTED)
		std::cout << " ok." << std::endl;
		std::cout << "*** size(Stack[edge]): " << stackHyperEdge.size() << std::endl;
#endif
		if( !stackHyperEdge.empty() ) {

			unsigned int v( stackHyperEdge.top() );

			stackHyperEdge.pop();
#if(TRACE_ALGORITHM_CONNECTED)
			std::cout << "POP [edge]: " << v << std::endl;
#endif
			exploreHorizontal(listConnectedVisited, stackHyperVertex, v);
#if(TRACE_ALGORITHM_CONNECTED)
			std::cout << "STOR [edge]: " << v << std::endl;
#endif
			listHyperEdgeVisited.push_back( v );
		}
#if(TRACE_ALGORITHM_CONNECTED)
		std::cout << "*** Stack[edge]: " << stackHyperEdge.size() << " elements" << std::endl;
		std::cout << "*** Stack[vrtx]: " << stackHyperVertex.size() << " elements" << std::endl;
#endif
	}
#if(TRACE_ALGORITHM_CONNECTED)
	std::cout << "Finished: " << listConnectedVisited.size() << " =?= " << _ptrHypergrapheAbstrait->getHyperVertexList().size() << std::endl;
#endif
	_result.setBooleanResult( listConnectedVisited.size() == _ptrHypergrapheAbstrait->getHyperVertexList().size() );
}

void
Connected::exploreVertical(std::vector<unsigned int>& listVisited, std::stack<unsigned int>& stack, unsigned int idVert) {

	LibType::AdjacentMatrixContainerBool
	matrix( _ptrHypergrapheAbstrait->getAdjacentMatrix().getBoolAdjacentMatrix() );

	boost::tuple<unsigned int, unsigned int>
	dim( _ptrHypergrapheAbstrait->getAdjacentMatrix().getMatrixDimension() );

	for(unsigned int i=0; i<dim.get<0>(); i++) {
		if( matrix[idVert][i] && !isEdgeVisited(listVisited, i ) ) {
#if(TRACE_ALGORITHM_CONNECTED)
			std::cout << "-> PUSH [edge]: " << i << std::endl;
#endif
			stack.push( i );
		}
	}
}

void
Connected::exploreHorizontal(std::vector<unsigned int>& listVisited, std::stack<unsigned int>& stack, unsigned int idHor) {

	LibType::AdjacentMatrixContainerBool
	matrix( _ptrHypergrapheAbstrait->getAdjacentMatrix().getBoolAdjacentMatrix() );

	boost::tuple<unsigned int, unsigned int>
	dim( _ptrHypergrapheAbstrait->getAdjacentMatrix().getMatrixDimension() );

	for(unsigned int i=0; i<dim.get<1>(); i++) {
		if( matrix[i][idHor] && !isVertexVisited(listVisited, i ) ) {
#if(TRACE_ALGORITHM_CONNECTED)
			std::cout << "-> PUSH [vertex]: " << i << std::endl;
#endif
			stack.push( i );
		}
	}
}

bool
Connected::isVertexVisited(std::vector<unsigned int>& list, unsigned int vertex) const {

	bool ret( false );
#pragma omp for schedule(dynamic)
	for(unsigned int i=0; i<list.size(); i++) {
		if(list[i]==vertex)ret = true;
	}
	return ret;
}

bool
Connected::isEdgeVisited(std::vector<unsigned int>& list, unsigned int edge) const {

	bool ret( false );
#pragma omp for schedule(dynamic)
	for(unsigned int i=0; i<list.size(); i++) {
		if(list[i]==edge)ret = true;
	}
	return ret;
}

/*
void
Connected::runAlgorithme() {

	LibType::ListHyperVertex listVertex( _ptrHypergrapheAbstrait->getHyperVertexList() );
	LibType::ListHyperEdge   listeEdge ( _ptrHypergrapheAbstrait->getHyperEdgeList()   );

	_result.setBooleanResult( true );

	///
	for(unsigned int i=0; i<_ptrHypergrapheAbstrait->getHyperEdgeById(0).getHyperVertexList().size(); i++) {
		if( _ptrHypergrapheAbstrait->getHyperEdgeById(0).containVertex(_ptrHypergrapheAbstrait->getHyperEdgeById(0).getHyperVertexList().at(i)) ) {
			std::cout << "0 contient " << _ptrHypergrapheAbstrait->getHyperEdgeById(0).getHyperVertexList().at(i).getIdentifier() << std::endl;
		}
	}
	///

	for(unsigned int i=0; i<listVertex.size(); i++) {
		for(unsigned int j=i+1; j<listVertex.size(); j++) {
			if( !isPath(listVertex.at(i), listVertex.at(j)) ) {
				_result.setBooleanResult( false );
				return;
			}
		}
	}
}

bool
Connected::isPath(HyperVertex& vSource, HyperVertex& vDest) const {

	std::stack<HyperEdge> listEdge;
	std::vector<HyperEdge>  visitedEdge;

	for(unsigned int i=0; i<vSource.getHyperEdgeList().size(); i++) {
		listEdge.push( vSource.getHyperEdgeList().at(i) );
	}

	while( !listEdge.empty() ) {

		while( isVisited( visitedEdge, listEdge.top() ) ) {
			listEdge.pop();
		}

		if( listEdge.empty() )return false;

		HyperEdge e( listEdge.top() );
		listEdge.pop();

		std::cout << "Test de " << e.getIdentifier() << " source: "
				  << vSource.getIdentifier()
				  << " -> "
				  << vDest.getIdentifier() << " #"
				  << e.getIdentifier() << std::endl;

		if( e.containVertex(vDest) ) {
			std::cout << "FOUND: " << vSource.getIdentifier() << " " << vDest.getIdentifier() << std::endl;
			return true;
		}

		for(unsigned int i=0; i<e.getHyperVertexList().size(); i++) {
			for(unsigned int j=0; j<e.getHyperVertexList().at(i).getHyperEdgeList().size(); j++) {
				if( !isVisited(visitedEdge, e.getHyperVertexList().at(i).getHyperEdgeList().at(j)) ) {
					listEdge.push( e.getHyperVertexList().at(i).getHyperEdgeList().at(j) );
				}
			}
		}

		visitedEdge.push_back( e );
	};

	std::cout << "NOT FOUND: " << vSource.getIdentifier() << " " << vDest.getIdentifier() << std::endl;

	return false;
}

bool
Connected::isVisited(std::vector<HyperEdge>& list, const HyperEdge& e) const {
	for(unsigned int i=0; i<list.size(); i++) {
		if( list.at(i)==e )return true;
	}
	return false;
}
*/
RStructure
Connected::getResult() const {
	return _result;
}

Connected::~Connected() {

}

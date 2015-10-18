
#include "include/WriterFile.hh"

#include "../model/include/HypergrapheAbstrait.hh"
#include "../model/include/HyperVertex.hh"
#include "../model/include/HyperEdge.hh"

#include <boost/tuple/tuple.hpp>
#include <boost/foreach.hpp>

WriterFile::WriterFile(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) :
				WriterAbstrait( ptrHypergrapheAbstrait ) {

}

void
WriterFile::writeAdjacentMatrix(std::ostream& sortie) const {

	LibType::AdjacentMatrixContainerBool
	adjacentMatrixBool( _ptrHypergrapheAbstrait->getAdjacentMatrix().getBoolAdjacentMatrix() );

	boost::tuple<unsigned int, unsigned int>
	matrixDimension( _ptrHypergrapheAbstrait->getAdjacentMatrix().getMatrixDimension() );

	unsigned int n( matrixDimension.get<0>() ), m( matrixDimension.get<1>() );

	for(unsigned int i=0; i<n; i++) {
		for(unsigned int j=0; j<m; j++) {
			sortie << adjacentMatrixBool[j][i] << " ";
		}
		sortie << " " << "\n";
	}
}

void
WriterFile::writeHypergraph(std::ostream& sortie) const {

	writeHypergrapheHyperVertex( sortie );
	writeHypergrapheHyperEdge( sortie );

	LibType::ListHyperEdge listEdge( _ptrHypergrapheAbstrait->getHyperEdgeList() );

	BOOST_FOREACH(const auto& edge, listEdge) {
		LibType::ListHyperVertex vertexList( edge->getHyperVertexList() );
		BOOST_FOREACH(const auto& vertex, vertexList) {
			sortie << edge->getIdentifier() << " " << vertex->getIdentifier() << std::endl;
		}
	}
}

void
WriterFile::writeHypergrapheHyperVertex(std::ostream& sortie) const {

	LibType::ListHyperVertex listVertex( _ptrHypergrapheAbstrait->getHyperVertexList() );

	BOOST_FOREACH(const auto& vertex, listVertex) {
		sortie << vertex->getIdentifier() << " ";
	}

	sortie << "\n";
}

void
WriterFile::writeHypergrapheHyperEdge(std::ostream& sortie) const {

	LibType::ListHyperEdge listEdge( _ptrHypergrapheAbstrait->getHyperEdgeList() );

	BOOST_FOREACH(const auto& edge, listEdge) {
		sortie << edge->getIdentifier() << " ";
	}

	sortie << "\n";

}

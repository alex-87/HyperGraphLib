/*
 * IsomorphSpace.cpp
 *
 */

#include "include/IsomorphSpace.hh"


IsomorphSpace::IsomorphSpace(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
							 const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB) :

							 _ptrHypergrapheA (ptrHypergrapheAbstraitA),
							 _ptrHypergrapheB (ptrHypergrapheAbstraitB) {

}

void
IsomorphSpace::postConstraints() {

	LibType::ListHyperVertex vertexA( _ptrHypergrapheA->getHyperVertexList() );
	LibType::ListHyperEdge   edgeA  ( _ptrHypergrapheA->getHyperEdgeList()   );

	LibType::ListHyperVertex vertexB( _ptrHypergrapheB->getHyperVertexList() );
	LibType::ListHyperEdge   edgeB  ( _ptrHypergrapheB->getHyperEdgeList()   );


	_varVertex (*this, vertexA.size() );
	_bVarVertex(*this, vertexA.size() );

	_varEdge   (*this, edgeA.size()   );
	_bVarEdge  (*this, edgeA.size()   );

	int i( 0), j( 0 );

	for(boost::shared_ptr<HyperEdge>& e : edgeA ) {
		for(boost::shared_ptr<HyperVertex>& v : vertexA ) {

			if( e->containVertex(v) ) {
				Gecode::rel(*this, _bVarEdge[ _varEdge[i].val() ], Gecode::BOT_AND, _bVarVertex[ _varVertex[j].val() ], 1);
			}
			else {
				Gecode::rel(*this, _bVarEdge[ _varEdge[i].val() ], Gecode::BOT_AND, _bVarVertex[ _varVertex[j].val() ], 0);
			}

			i++;
		}

		j++;
	}

	for(unsigned int u=0; u<vertexA.size(); u++) {
		Gecode::dom(*this, _varVertex[u], 0, vertexA.size() );
		Gecode::distinct(*this, (const Gecode::IntVarArgs) _varVertex[u] );
	}

	for(unsigned int v=0; v<edgeA.size(); v++) {
		Gecode::dom(*this, _varEdge[v], 0, edgeA.size() );
		Gecode::distinct(*this, (const Gecode::IntVarArgs) _varEdge[v] );
	}

	Gecode::branch(*this, _solution, Gecode::INT_VAR_SIZE_MIN(), Gecode::INT_VAL_SPLIT_MIN());
}

Gecode::Space*
IsomorphSpace::copy(bool share) {
	return new IsomorphSpace(share, *this);
}

IsomorphSpace::IsomorphSpace(bool share, IsomorphSpace& p) :
		IsomorphSpace(share, p) {
}

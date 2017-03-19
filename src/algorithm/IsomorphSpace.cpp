/*
 * IsomorphSpace.cpp
 *
 */

#include "include/IsomorphSpace.hh"
#include <iostream>
#include <gecode/driver.hh>


IsomorphSpace::IsomorphSpace(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
							 const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB) :

			_varEdge(*this, ptrHypergrapheAbstraitA->getHyperEdgeList().size(), 0, ptrHypergrapheAbstraitA->getHyperEdgeList().size() - 1 ),
			_bVarEdge(*this, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size(), 0, 1),

			_varVertex(*this, ptrHypergrapheAbstraitA->getHyperVertexList().size(), 0, ptrHypergrapheAbstraitA->getHyperVertexList().size() - 1 ),
			_bVarVertex(*this, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size(), 0, 1 ),

			_bVarEdge2(*this, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size(), 0, 1),
			_bVarVertex2(*this, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size(), 0, 1 ),

			_ptrHypergrapheA (ptrHypergrapheAbstraitA),
			_ptrHypergrapheB (ptrHypergrapheAbstraitB) {

}

void
IsomorphSpace::postConstraints() {

        LibType::ListHyperVertex vertexA( _ptrHypergrapheA->getHyperVertexList() );
        LibType::ListHyperEdge   edgeA  ( _ptrHypergrapheA->getHyperEdgeList()   );

        LibType::ListHyperVertex vertexB( _ptrHypergrapheB->getHyperVertexList() );
        LibType::ListHyperEdge   edgeB  ( _ptrHypergrapheB->getHyperEdgeList()   );

        int i( 0 ), j( 0 );

        for(boost::shared_ptr<HyperEdge>& e : edgeA ) {
                for(boost::shared_ptr<HyperVertex>& v : vertexA ) {

                        if( e->containVertex(v) ) {
                                Gecode::rel(*this, _bVarEdge[ i ], Gecode::BOT_AND, _bVarVertex[ j ], 1);
                        }
                        else {
                                Gecode::rel(*this, _bVarEdge[ i ], Gecode::BOT_AND, _bVarVertex[ j ], 0);
                        }

                        j++;
                }
                i++;
        }

	i = 0;
	j = 0;

        for(boost::shared_ptr<HyperEdge>& e : edgeB ) {
                for(boost::shared_ptr<HyperVertex>& v : vertexB ) {

                       if( e->containVertex(v) ) {
                                Gecode::rel(*this, _bVarEdge2[ i ], Gecode::BOT_AND, _bVarVertex2[ j ], 1);
                        }
                        else {
                                Gecode::rel(*this, _bVarEdge2[ i ], Gecode::BOT_AND, _bVarVertex2[ j ], 0);
                        }

                        j++;
                }
                i++;
        }

	for(int g=0; g<_ptrHypergrapheA->getHyperEdgeList().size(); g++) {
		Gecode::element(*this, _bVarEdge, _varEdge[g], _bVarEdge2[g]);
	}

	for(int h=0; h<_ptrHypergrapheA->getHyperVertexList().size(); h++) {
		Gecode::element(*this, _bVarVertex, _varVertex[h], _bVarVertex2[h]);
	}        

        Gecode::distinct(*this, _varVertex );
        Gecode::distinct(*this, _varEdge   );

        Gecode::branch(*this, _varEdge, Gecode::INT_VAR_SIZE_MIN(), Gecode::INT_VAL_SPLIT_MIN());
        Gecode::branch(*this, _varVertex, Gecode::INT_VAR_SIZE_MIN(), Gecode::INT_VAL_SPLIT_MIN());
}

Gecode::Space*
IsomorphSpace::copy(bool share) {
        return new IsomorphSpace(share, *this);
}

IsomorphSpace::IsomorphSpace(bool share, IsomorphSpace& p) :
                Gecode::Space(share, p) {
		_varEdge.update(*this, share, p._varEdge);
		_varVertex.update(*this, share, p._varVertex);
}


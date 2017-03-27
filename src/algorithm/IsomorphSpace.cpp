/*
 * IsomorphSpace.cpp
 *
 */

#include "include/IsomorphSpace.hh"
#include <iostream>
#include <gecode/driver.hh>
#include <gecode/minimodel.hh>


IsomorphSpace::IsomorphSpace(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
			     const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB) :

_varEdge(*this, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size(), 0, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size() - 1 ),

_bVarEdge(*this, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size(), 0, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size() - 1),

_bVarEdge2(*this, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size(), 0, ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size() - 1),

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
                                Gecode::rel(*this, _bVarEdge[ j ], Gecode::IRT_EQ, j);
                        } else {
				Gecode::rel(*this, _bVarEdge[ j ], Gecode::IRT_EQ, 0);
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
                                Gecode::rel(*this, _bVarEdge2[ j ], Gecode::IRT_EQ, j);
                        } else {
				Gecode::rel(*this, _bVarEdge2[ j ], Gecode::IRT_EQ, 0);
			}

                        j++;
                }
                i++;
        }

	int u( 0 );
	for(int g=0; g < edgeA.size(); g++) {
		for(int h=0; h < vertexA.size(); h++) {
			Gecode::element(*this, _bVarEdge, _varEdge[u], _bVarEdge2[u]);
			u++;
		}
	}

        Gecode::distinct(*this, _varEdge   );

        Gecode::branch(*this, _varEdge, Gecode::INT_VAR_SIZE_MIN(), Gecode::INT_VAL_SPLIT_MIN());
}

Gecode::Space*
IsomorphSpace::copy(bool share) {
        return new IsomorphSpace(share, *this);
}

IsomorphSpace::IsomorphSpace(bool share, IsomorphSpace& p) :
                Gecode::Space(share, p) {
		_varEdge.update(*this, share, p._varEdge);
}


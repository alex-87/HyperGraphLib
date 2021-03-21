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

#include "include/IsomorphSpace.hh"
#include <iostream>
#include <gecode/driver.hh>
#include <gecode/minimodel.hh>


IsomorphSpace::IsomorphSpace(
    const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitA,
    const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstraitB) :

    _varEdge(
        *this,
        ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size() + 1,
        0,
        ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size()
    ),

    _bVarEdge(
        *this,
        ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size() + 1,
        0,
        ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size()
    ),

    _bVarEdge2(
        *this,
        ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size() + 1,
        0,
        ptrHypergrapheAbstraitA->getHyperEdgeList().size() * ptrHypergrapheAbstraitA->getHyperVertexList().size()
    ),

    _ptrHypergrapheA (ptrHypergrapheAbstraitA),
    _ptrHypergrapheB (ptrHypergrapheAbstraitB) {
}

void
IsomorphSpace::postConstraints() {
    LibType::ListHyperVertex vertexA( _ptrHypergrapheA->getHyperVertexList() );
    LibType::ListHyperEdge   edgeA  ( _ptrHypergrapheA->getHyperEdgeList()   );

    LibType::ListHyperVertex vertexB( _ptrHypergrapheB->getHyperVertexList() );
    LibType::ListHyperEdge   edgeB  ( _ptrHypergrapheB->getHyperEdgeList()   );

    int j( 1 );
    for(boost::shared_ptr<HyperEdge>& e : edgeA ) {
        for(boost::shared_ptr<HyperVertex>& v : vertexA ) {
            if( e->containVertex(v) ) {
                Gecode::rel(*this, _bVarEdge[ j ], Gecode::IRT_EQ, j);
            } else {
                Gecode::rel(*this, _bVarEdge[ j ], Gecode::IRT_EQ, 0);
            }
            j++;
        }
    }

    j = 1;
    for(boost::shared_ptr<HyperEdge>& e : edgeB ) {
        for(boost::shared_ptr<HyperVertex>& v : vertexB ) {
            if( e->containVertex(v) ) {
                Gecode::rel(*this, _bVarEdge2[ j ], Gecode::IRT_EQ, j);
            } else {
                Gecode::rel(*this, _bVarEdge2[ j ], Gecode::IRT_EQ, 0);
            }
            j++;
        }
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


#if GECODE_VERSION_NUMBER > 500100

Gecode::Space*
IsomorphSpace::copy() {
    return new IsomorphSpace(*this);
}

IsomorphSpace::IsomorphSpace(IsomorphSpace& p) :
Gecode::Space(p) {
    _varEdge.update(*this, p._varEdge);
}

#else

Gecode::Space*
IsomorphSpace::copy(bool share) {
    return new IsomorphSpace(share, *this);
}

IsomorphSpace::IsomorphSpace(bool share, IsomorphSpace& p) :
Gecode::Space(share, p) {
    _varEdge.update(*this, share, p._varEdge);
}

#endif

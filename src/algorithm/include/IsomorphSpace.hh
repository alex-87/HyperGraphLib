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


#ifndef ALGORITHM_INCLUDE_ISOMORPHISMSPACE_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISMSPACE_HH_

#include <gecode/int.hh>
#include <gecode/search.hh>
#include <boost/shared_ptr.hpp>
#include "../../model/include/LibType.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"

class HypergrapheAbstrait;

class IsomorphSpace : public Gecode::Space {

public:

	IsomorphSpace(const boost::shared_ptr<HypergrapheAbstrait>&, const boost::shared_ptr<HypergrapheAbstrait>&);

	void postConstraints();

#if GECODE_VERSION_NUMBER > 500100

	Gecode::Space * copy();

	IsomorphSpace(IsomorphSpace& p);

#else

	Gecode::Space * copy(bool share);

	IsomorphSpace(bool share, IsomorphSpace& p);

#endif


	Gecode::IntVarArray _varEdge;

	Gecode::IntVarArray _bVarEdge;

	Gecode::IntVarArray _bVarEdge2;

protected:

	boost::shared_ptr<HypergrapheAbstrait> _ptrHypergrapheA;

	boost::shared_ptr<HypergrapheAbstrait> _ptrHypergrapheB;

};

#endif

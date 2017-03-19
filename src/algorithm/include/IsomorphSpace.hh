
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

	Gecode::Space * copy(bool share);

	IsomorphSpace(bool share, IsomorphSpace& p);




	Gecode::IntVarArray   _varEdge;
	Gecode::BoolVarArray _bVarEdge;

	Gecode::IntVarArray   _varVertex;
	Gecode::BoolVarArray _bVarVertex;

	Gecode::BoolVarArray _bVarEdge2;
	Gecode::BoolVarArray _bVarVertex2;

protected:

	boost::shared_ptr<HypergrapheAbstrait> _ptrHypergrapheA;

	boost::shared_ptr<HypergrapheAbstrait> _ptrHypergrapheB;

};

#endif

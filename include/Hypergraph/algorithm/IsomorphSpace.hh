
#ifndef ALGORITHM_INCLUDE_ISOMORPHISMSPACE_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISMSPACE_HH_

#include <gecode/int.hh>
#include <gecode/search.hh>
#include <boost/shared_ptr.hpp>

class HypergrapheAbstrait;

class IsomorphSpace : public Gecode::Space {

public:

	IsomorphSpace(const boost::shared_ptr<HypergrapheAbstrait>&, const boost::shared_ptr<HypergrapheAbstrait>&);

	void postConstraints();

	Gecode::Space*
	copy(bool share);

	IsomorphSpace(bool share, IsomorphSpace& p);

protected:

	Gecode::IntVarArray _varEdge;
	Gecode::BoolVarArray _bVarEdge;

	Gecode::IntVarArray _varVertex;
	Gecode::BoolVarArray _bVarVertex;

	Gecode::IntVarArray _solution;

	boost::shared_ptr<HypergrapheAbstrait> _ptrHypergrapheA;

	boost::shared_ptr<HypergrapheAbstrait> _ptrHypergrapheB;

};

#endif

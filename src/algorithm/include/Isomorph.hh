
#ifndef ALGORITHM_INCLUDE_ISOMORPHISM_HH_
#define ALGORITHM_INCLUDE_ISOMORPHISM_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"

class Isomorph : public AlgorithmeAbstrait {

public:

	Isomorph(const boost::shared_ptr<HypergrapheAbstrait>&, const boost::shared_ptr<HypergrapheAbstrait>&);

	RStructure getResult() const;

	~Isomorph();

protected:

	void runAlgorithme();

protected:

	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstraitA;

	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstraitB;

	RStructure _result;

};



#endif

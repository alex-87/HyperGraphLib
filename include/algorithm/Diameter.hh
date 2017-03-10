
#ifndef ALGORITHM_INCLUDE_DIAMETER_HH_
#define ALGORITHM_INCLUDE_DIAMETER_HH_

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"


class Diameter : public AlgorithmeAbstrait {

public:

	Diameter(boost::shared_ptr<HypergrapheAbstrait>&);

	RStructure getResult() const;

	~Diameter();


protected:

	void runAlgorithme();


protected:

	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	RStructure _result;

};



#endif /* ALGORITHM_INCLUDE_DIAMETER_HH_ */

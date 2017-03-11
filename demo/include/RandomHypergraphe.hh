
#ifndef CLIENT_INCLUDE_RANDOMHYPERGRAPHE_HH_
#define CLIENT_INCLUDE_RANDOMHYPERGRAPHE_HH_

#include <boost/shared_ptr.hpp>
#include "../../include/Hypergraph/model/HypergrapheAbstrait.hh"

class RandomHypergraphe {

public:

	RandomHypergraphe();

	void generateHypergraphe(unsigned int, unsigned int);

	boost::shared_ptr<HypergrapheAbstrait>&
	getHypergraphe();

protected:

	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

};


#endif /* CLIENT_INCLUDE_RANDOMHYPERGRAPHE_HH_ */

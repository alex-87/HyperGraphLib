
#ifndef CLIENT_INCLUDE_RANDOMHYPERGRAPHE_HH_
#define CLIENT_INCLUDE_RANDOMHYPERGRAPHE_HH_

#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperFactory.hh"

#include <boost/shared_ptr.hpp>



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


#include "include/RStructure.hh"

void
RStructure::setBooleanResult(bool result) {
	_booleanResult = result;
}

bool
RStructure::getBooleanResult() const {
	return _booleanResult;
}

void
RStructure::setHypergrapheResult(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) {
	_hypergrapheResult = ptrHypergrapheAbstrait;
}

boost::shared_ptr<HypergrapheAbstrait>
RStructure::getHypergrapheResult() const {
	return _hypergrapheResult;
}

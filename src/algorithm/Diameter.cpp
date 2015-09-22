
#include "include/Diameter.hh"


Diameter::Diameter(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) : _ptrHypergrapheAbstrait(ptrHypergrapheAbstrait) {

}

void
Diameter::runAlgorithme() {

}

RStructure
Diameter::getResult() const {
	return _result;
}

Diameter::~Diameter() {

}

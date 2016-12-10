
#include "include/Path.hh"

Path::Path(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) :
			_ptrHypergrapheAbstrait( ptrHypergrapheAbstrait ) {
}

RStructure
Path::getResult() const {
	return _result;
}



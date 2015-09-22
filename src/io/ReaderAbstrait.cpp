
#include "include/ReaderAbstrait.hh"

ReaderAbstrait::ReaderAbstrait(const boost::shared_ptr<HypergrapheAbstrait>& p) {
	_ptrHypergrapheAbstrait = p;
}

boost::shared_ptr<HypergrapheAbstrait>&
ReaderAbstrait::getHypergraphe() {
	return _ptrHypergrapheAbstrait;
}

ReaderAbstrait::~ReaderAbstrait() {

}

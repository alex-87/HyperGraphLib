
#include "include/WriterAbstrait.hh"

WriterAbstrait::WriterAbstrait(const boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait) :
			_ptrHypergrapheAbstrait( ptrHypergrapheAbstrait ){

}

WriterAbstrait::~WriterAbstrait() {

}

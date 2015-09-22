
#include "include/RandomHypergraphe.hh"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random.hpp>

RandomHypergraphe::RandomHypergraphe() : _ptrHypergrapheAbstrait( new Hypergraphe ) {

}

void
RandomHypergraphe::generateHypergraphe(unsigned int nbVertex, unsigned int nbEdge) {

	std::vector<boost::shared_ptr<HyperVertex>> listVertex;
	std::vector<boost::shared_ptr<HyperEdge>>   listEdge;

	boost::random::mt19937 gen;
	gen.seed( std::time(0) );

	boost::uniform_int<> uInt8Dist(0, std::numeric_limits<unsigned char>::max());
	boost::variate_generator< boost::mt19937&, boost::uniform_int<> > getRand(gen, uInt8Dist);

	HyperFactory::startSession( _ptrHypergrapheAbstrait );

	for(unsigned int i=0; i<nbVertex; i++)
		listVertex.push_back( HyperFactory::newHyperVertex() );

	for(unsigned int j=0; j<nbEdge; j++)
		listEdge.push_back( HyperFactory::newHyperEdge() );

	for(unsigned int u=0; u<(nbVertex * nbEdge); u++) {	
		if( u % 3 == 0 ) {
			int n = getRand();
			HyperFactory::link( *listVertex.at((u+n)%nbVertex).get(), *listEdge.at((u*n)%nbEdge).get() );
		}
	}

	for(unsigned int i=0; i<nbVertex; i++) {
		_ptrHypergrapheAbstrait->addHyperVertex( *listVertex.at(i).get() );
	}

	for(unsigned int i=0; i<nbEdge; i++) {
		_ptrHypergrapheAbstrait->addHyperEdge( *listEdge.at(i).get() );
	}

	HyperFactory::closeSession();

	_ptrHypergrapheAbstrait->flush();

}

boost::shared_ptr<HypergrapheAbstrait>&
RandomHypergraphe::getHypergraphe() {
	return _ptrHypergrapheAbstrait;
}

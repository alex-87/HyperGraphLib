
#ifndef ALGORITHM_INCLUDE_HPGSTAT
#define ALGORITHM_INCLUDE_HPGSTAT

#include <boost/shared_ptr.hpp>
#include "../../model/include/HypergrapheAbstrait.hh"
#include "../../model/include/Hypergraphe.hh"
#include "../../model/include/HyperVertex.hh"
#include "../../model/include/HyperEdge.hh"
#include "../../model/include/AlgorithmeAbstrait.hh"
#include "../../model/include/RStructure.hh"

class HyperGraphStat : public AlgorithmeAbstrait {

public:

	HyperGraphStat(const boost::shared_ptr<HypergrapheAbstrait>&);

	RStructure getResult() const;

	~HyperGraphStat();


public:

	unsigned int getNbrHyperEdge() const;

	unsigned int getNbrHyperVertex() const;

	unsigned int getNbrLinks() const;

	unsigned int getRang() const;

	unsigned int getCoRang() const;

protected:

	/**
	 * Lancment de l'algorithme.
	 */
	void runAlgorithme();

protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * La structure des résultats.
	 */
	RStructure _result;

	unsigned int _nhEdge;

	unsigned int _nhVertex;

	unsigned int _nhLink;

	unsigned int _rang;

	unsigned int _coRang;

};


#endif

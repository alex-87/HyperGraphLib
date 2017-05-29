/**
 * Result description structure
 */
#ifndef MODEL_INCLUDE_RSTRUCTURE_HH_
#define MODEL_INCLUDE_RSTRUCTURE_HH_

#include "HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Result description structure
 */
class RStructure {

public:

	/**
	 * Add integer result
	 */
	void setIntegerResult();

	/**
	 * Add boolean result
	 */
	void setBooleanResult(bool);

	/**
	 * Add HypergraphAbstrait result
	 */
	void setHypergrapheResult(const boost::shared_ptr<HypergrapheAbstrait>&);

public:

	/**
	 * Get integer result
	 * @return Integer result
	 */
	int getIntegerResult() const;

	/**
	 * Get boolean result
	 * @return Boolean result
	 */
	bool getBooleanResult() const;

	/**
	 * Get HypergraphAbstrait result
	 * @return HypergraphAbstrait result
	 */
	boost::shared_ptr<HypergrapheAbstrait> getHypergrapheResult() const;

protected:

	/**
	 * Integer result value
	 */
	int _integerResult;

	/**
	 * Boolean result value
	 */
	bool _booleanResult;

	/**
	 * HypergraphAbstrait result shared pointer
	 */
	boost::shared_ptr<HypergrapheAbstrait> _hypergrapheResult;

};



#endif /* MODEL_INCLUDE_RSTRUCTURE_HH_ */


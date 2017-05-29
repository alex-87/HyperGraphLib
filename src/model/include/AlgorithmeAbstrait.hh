/**
 * Algorithm interface
 */

#ifndef MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_
#define MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_

#include "RStructure.hh"

class MotorAlgorithm;

/**
 * Algorithm interface
 */
class AlgorithmeAbstrait {

public:

	/**
	 * Get the result structure
	 * @return The result structure
	 */
	virtual RStructure getResult() const = 0;

	/**
	 * Abstract destructor
	 */
	virtual ~AlgorithmeAbstrait();


protected:

	friend class MotorAlgorithm;

	/**
	 * Run the algorithm
	 */
	virtual void runAlgorithme() = 0;

};


#endif /* MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_ */

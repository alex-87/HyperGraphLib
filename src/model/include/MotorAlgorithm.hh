/**
 * Algorithmic engine
 */
#ifndef MODEL_INCLUDE_MOTORALGORITHM_HH_
#define MODEL_INCLUDE_MOTORALGORITHM_HH_

#include <boost/shared_ptr.hpp>

#include "AlgorithmeAbstrait.hh"

/**
 * Algorithmic engine
 */
class MotorAlgorithm {

public:

	/**
	 * Get the instance
	 * @return The instance
	 */
	static MotorAlgorithm& Instance();

	/**
	 * Set the algorithm
	 * @param The algorithm
	 */
	static void setAlgorithme(boost::shared_ptr<AlgorithmeAbstrait>&);

	/**
	 * Run the algorithm
	 */
	static void runAlgorithme();

	/**
	 * Check whether the engine is running
	 * @return True or False
	 */
	static bool isLock();

private:

	/**
	 * Lock the engine
	 */
	static void lock();

	/**
	 * Unlock the engine
	 */
	static void unlock();

private:

	/**
	 * Constructor
	 * @param The algorithm
	 */
	MotorAlgorithm(const MotorAlgorithm&);

	/**
	 * Constructor
	 * @param The algorithm
	 */
	MotorAlgorithm& operator= (const MotorAlgorithm&);

	/**
	 * Constructor
	 */
	MotorAlgorithm();

	/**
	 * Destructor
	 */
	~MotorAlgorithm();

private:

	/**
	 * Lock descriptor
	 */
	static bool               _lock;

	/**
	 * Singleton instance
	 */
	static MotorAlgorithm     _instance;

	/**
	 * The algorithm
	 */
	static boost::shared_ptr<AlgorithmeAbstrait> _algorithme;

};



#endif /* MODEL_INCLUDE_MOTORALGORITHM_HH_ */

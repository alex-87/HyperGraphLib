
#include "include/MotorAlgorithm.hh"

MotorAlgorithm::MotorAlgorithm() {
}

MotorAlgorithm&
MotorAlgorithm::Instance() {
	return _instance;
}

void
MotorAlgorithm::setAlgorithme(boost::shared_ptr<AlgorithmeAbstrait>& algorithme) {
	if( MotorAlgorithm::isLock() )return;
	_algorithme = algorithme;
}

void
MotorAlgorithm::runAlgorithme() {
	if( MotorAlgorithm::isLock() )return;
	MotorAlgorithm::lock();
	_algorithme->runAlgorithme();
	MotorAlgorithm::unlock();
}

bool
MotorAlgorithm::isLock() {
	return _lock;
}

void
MotorAlgorithm::lock() {
	_lock = true;
}

void
MotorAlgorithm::unlock() {
	_lock = false;
}

MotorAlgorithm::~MotorAlgorithm() {
}


bool MotorAlgorithm::_lock = false;
MotorAlgorithm MotorAlgorithm::_instance = MotorAlgorithm();
boost::shared_ptr<AlgorithmeAbstrait> MotorAlgorithm::_algorithme = nullptr;

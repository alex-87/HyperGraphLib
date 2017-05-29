/**
 * Path result description structure
 */
#ifndef MODEL_INCLUDE_RSTRUCTURE_PATH_HH_
#define MODEL_INCLUDE_RSTRUCTURE_PATH_HH_

#include "RStructure.hh"

class RStructurePath : public RStructure {

public:

	RStructurePath();

	void setPathResult(LibType::PathList&);

	LibType::PathList getPathResult();

protected:

	LibType::PathList _pathList;

};

#endif

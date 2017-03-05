
#include "include/RStructurePath.hh"

RStructurePath::RStructurePath() : RStructure() {

}

void
RStructurePath::setPathResult(LibType::PathList& pathList) {
	_pathList = pathList;
}

LibType::PathList
RStructurePath::getPathResult() {
	return _pathList;
}

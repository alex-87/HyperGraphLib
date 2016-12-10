/**
 * Structure de description du résultat. Cet objet
 * est la représentation du résultat produit par tout algorithme.
 */
#ifndef MODEL_INCLUDE_RSTRUCTURE_PATH_HH_
#define MODEL_INCLUDE_RSTRUCTURE_PATH_HH_

#include "RStructure.hh"

class RStructurePath : public RStructure {

public:

	void setPathResult(LibType::PathList&);

	LibType::PathList getPathResult();

protected:

	LibType::PathList _pathList;

};

#endif

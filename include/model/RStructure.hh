/**
 * Structure de description du résultat. Cet objet
 * est la représentation du résultat produit par tout algorithme.
 */
#ifndef MODEL_INCLUDE_RSTRUCTURE_HH_
#define MODEL_INCLUDE_RSTRUCTURE_HH_

#include "HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Structure de description du résultat.
 */
class RStructure {

public:

	/**
	 * Ajouter un résultat entier.
	 */
	void setIntegerResult();

	/**
	 * Ajouter un résultat booléen.
	 * @param Le résultat booléen.
	 */
	void setBooleanResult(bool);

	/**
	 * Ajouter un résultat de type HypergrapheAbstrait.
	 * @param L'hypergraphe faisant office de résultat.
	 */
	void setHypergrapheResult(const boost::shared_ptr<HypergrapheAbstrait>&);

public:

	/**
	 * Lire un résultat entier.
	 * @return Le résutat en tant que nombre entier.
	 */
	int getIntegerResult() const;

	/**
	 * Lire un résutat booléen.
	 * @return Le résultat en tant que valeur booléenne.
	 */
	bool getBooleanResult() const;

	/**
	 * Lire un résultat de typ HypergrapheAbstrait
	 * @return Le résultat de type HypergrapheAbstrait
	 */
	boost::shared_ptr<HypergrapheAbstrait> getHypergrapheResult() const;

protected:

	/**
	 * La valeur du résultat entier.
	 */
	int _integerResult;

	/**
	 * La valeur du résultat booléen.
	 */
	bool _booleanResult;

	/**
	 * L'hypergraphe faisant office de résultat.
	 */
	boost::shared_ptr<HypergrapheAbstrait> _hypergrapheResult;

};



#endif /* MODEL_INCLUDE_RSTRUCTURE_HH_ */


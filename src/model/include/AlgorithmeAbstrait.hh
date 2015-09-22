/**
 * Définition de l'interface d'un algorithme.
 */


#ifndef MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_
#define MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_

#include "RStructure.hh"

class MotorAlgorithm;

/**
 * Classe abstraite définissant les méthodes obligatoires d'un algorithme.
 */
class AlgorithmeAbstrait {

public:

	/**
	 * Obtenir la structure de description du résultat.
	 * @return La structure de description du résultat.
	 */
	virtual RStructure getResult() const = 0;

	/**
	 * Destructeur abstrait.
	 */
	virtual ~AlgorithmeAbstrait();


protected:

	friend class MotorAlgorithm;

	/**
	 * Fonction princiale de lancement de l'algorithme.
	 */
	virtual void runAlgorithme() = 0;

};


#endif /* MODEL_INCLUDE_ALGORITHMEABSTRAIT_HH_ */

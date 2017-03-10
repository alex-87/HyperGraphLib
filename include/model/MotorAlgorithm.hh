/**
 * Moteur des algorithmes. Avant de lancer un algorithme,
 * on configure le moteur, qui fait office de lanceur, afin
 * d'éviter les erreurs lors du paraléllisme.
 */
#ifndef MODEL_INCLUDE_MOTORALGORITHM_HH_
#define MODEL_INCLUDE_MOTORALGORITHM_HH_

#include <boost/shared_ptr.hpp>

#include "AlgorithmeAbstrait.hh"

/**
 * Moteur algorithmique.
 */
class MotorAlgorithm {

public:

	/**
	 * Obtenir l'instance du moteur.
	 * @return L'instance du moteur.
	 */
	static MotorAlgorithm& Instance();

	/**
	 * Insérer l'algorithme à lancer.
	 * @param Pointeur partagé sur l'algorithme.
	 */
	static void setAlgorithme(boost::shared_ptr<AlgorithmeAbstrait>&);

	/**
	 * Lancer l'algorithme.
	 */
	static void runAlgorithme();

	/**
	 * Indicateur de bloquage du moteur.
	 * @return True si le lanceur est bloqué, False sinon.
	 */
	static bool isLock();

private:

	/**
	 * Bloquage des setters et du lanceur.
	 */
	static void lock();

	/**
	 * Débloquage des setters et du lanceur.
	 */
	static void unlock();

private:

	/**
	 * Constructeur (copie).
	 */
	MotorAlgorithm(const MotorAlgorithm&);

	/**
	 * Constructeur.
	 */
	MotorAlgorithm& operator= (const MotorAlgorithm&);

	/**
	 * Constructeur.
	 */
	MotorAlgorithm();

	/**
	 * Déstructeur.
	 */
	~MotorAlgorithm();

private:

	/**
	 * Descripteur du statut bloquant.
	 */
	static bool               _lock;

	/**
	 * Instance unique du moteur.
	 */
	static MotorAlgorithm     _instance;

	/**
	 * Pointeur partagé de l'algorithme.
	 */
	static boost::shared_ptr<AlgorithmeAbstrait> _algorithme;

};



#endif /* MODEL_INCLUDE_MOTORALGORITHM_HH_ */

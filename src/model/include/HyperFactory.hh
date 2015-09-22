/**
 * Définition de la fabrique d'un hypergraphe.
 */
#ifndef MODEL_INCLUDE_HYPERFACTORY_HH_
#define MODEL_INCLUDE_HYPERFACTORY_HH_

#include "HyperVertex.hh"
#include "HyperEdge.hh"

/**
 * Classe modélisant la fabrique de l'hypergraphe.
 */
class HyperFactory {

public:

	/**
	 * Instance unique de la fabrique.
	 */
	static HyperFactory& Instance();


public:

	/**
	 * Démarrer une session de fabrication d'un hypergraphe.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	static void startSession(boost::shared_ptr<HypergrapheAbstrait>& ptrHypergrapheAbstrait);

	/**
	 * Création d'un nouvel hyper-vertex.
	 * @return Nouvel hyper-vertex.
	 */
	static const boost::shared_ptr<HyperVertex> newHyperVertex();

	/**
	 * Création d'une nouvelle hyper-arête.
	 * @return Nouvelle hyper-arête.
	 */
	static const boost::shared_ptr<HyperEdge> newHyperEdge();

	/**
	 * Relier une hyper-arête à un hyper-vertex.
	 * @param L'hyper-vertex à relier.
	 * @param L'hyper-arête à relier.
	 */
	static void link(HyperVertex&, HyperEdge&);

	/**
	 * Test si une session est déjà en cours.
	 * @return True si c'est le cas, False sinon.
	 */
	static bool isSession();

	/**
	 * Terminer la session de construction.
	 */
	static void closeSession();


private:

	/**
	 * Constructeur
	 */
	HyperFactory();

	/**
	 * Constructeur
	 */
	HyperFactory(const HyperFactory&);

	/**
	 * Constructeur
	 */
	HyperFactory& operator= (const HyperFactory&);

	/**
	 * Destructeur
	 */
	~HyperFactory();


private:

	/**
	 * Instnce unique de la fabrique.
	 */
	static HyperFactory _instance;

	/**
	 * Compteur des indexes des hyper-vertex.
	 */
	static unsigned int _indexVertex;

	/**
	 * Compteur des indexes des hyper-arêtes.
	 */
	static unsigned int _indexEdge;

	/**
	 * Indicateur de session.
	 */
	static bool         _isSession;

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	static boost::shared_ptr<HypergrapheAbstrait> _ptrHypergrapheAbstrait;

};


#endif /* MODEL_INCLUDE_HYPERFACTORY_HH_ */

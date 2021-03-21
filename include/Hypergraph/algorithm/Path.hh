/*
 * MIT License
 * 
 * Copyright (c) 2015 Alexis LE GOADEC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

/**
 * Définition de l'algorithme décidant de l'ensemble des chemins dans un hypergraphe
 * reliant un Vertex e1 à un Vertex e2.
 */

#ifndef ALGORITHM_INCLUDE_PATH_HH_
#define ALGORITHM_INCLUDE_PATH_HH_

#include "../model/HypergrapheAbstrait.hh"
#include "../model/AlgorithmeAbstrait.hh"
#include "../model/RStructurePath.hh"

class Path : public AlgorithmeAbstrait {

public:

	/*
	 * Constructeur.
	 * @param boost::shared_ptr<HypergrapheAbstrait> Pointeur partagé vers l'hypergraphe.
	 */
	Path(boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Configurer les vertex à utiliser pour lister les chemins
	 */
	void setHyperVertex(boost::shared_ptr<HyperVertex>&, boost::shared_ptr<HyperVertex>&);

	/**
	 * Obtenir la structure de résultats.
	 */
	RStructure getResult() const;

	/**
	 * Obtenir la structure de résultats.
	 */
	RStructurePath getPathResult() const;

	/**
	 * Fixer la limite du nombre de chemins. Par défaut 0, non-définit.
	 */
	void setLimit(unsigned int);

	/**
	 * Lire la valeur limite.
	 */
	unsigned int getLimit() const;

	/**
	 * Destructeur.
	 */
	~Path();


protected:

	/**
	 * Lancement de l'algorithme
	 */
	void runAlgorithme();

	/**
	 * Vérifie si l'HyperVertex est contenu dans la liste
	 */
	bool vertexContained(LibType::ListHyperVertex&, boost::shared_ptr<HyperVertex>&) const;

	/**
	 * Ajoute les HyperVertex d'un HyperEdge dans la liste mentionnée.
	 */
	void addVertexList(LibType::ListHyperVertex&, LibType::ListHyperVertex&, const boost::shared_ptr<HyperEdge>&) const;


	void buildPathToPathList(LibType::PathList&, LibType::ListHyperVertex&);

protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

	/**
	 * Vertex source
	 */
	boost::shared_ptr<HyperVertex> _source;

	/**
	 * Vertex destination
	 */
	boost::shared_ptr<HyperVertex> _destination;

	/**
	 * Structure de résultat.
	 */
	RStructurePath _result;

	/**
	 * Valeur limite.
	 */
	unsigned int _limite;
};


#endif /* SRC_ALGORITHM_INCLUDE_PATH_HH_ */

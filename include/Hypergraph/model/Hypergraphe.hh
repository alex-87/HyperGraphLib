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
 * Classe modélisant un hypergraphe.
 */
#ifndef MODEL_INCLUDE_HYPERGRAPHE_HH_
#define MODEL_INCLUDE_HYPERGRAPHE_HH_

#include "HypergrapheAbstrait.hh"

/**
 * Modélisation de l'hypergraphe.
 */
class Hypergraphe : public HypergrapheAbstrait {

public:

	/**
	 * Constructeur par défaut.
	 */
	Hypergraphe();

	/**
	 * Ajouter un hyper-vertex à l'hypergraphe.
	 * @param L'hyper-vertex à ajouter.
	 */
	void addHyperVertex(const boost::shared_ptr<HyperVertex>&);

	/**
	 * Ajouter une hyper-arête à l'hypergraphe.
	 * @param L'hyper-arête à ajouter.
	 */
	void addHyperEdge(const boost::shared_ptr<HyperEdge>&);

	/**
	 * Obtenir un hyper-vertex à l'aide de son identifiant.
	 * @param L'identifiant de l'hyper-vertex à obtenir.
	 */
	boost::shared_ptr<HyperVertex>& getHyperVertexById(const unsigned int&);

	/**
	 * Obtenir une hyper-arête à l'aide de son identifiant.
	 * @param L'identifiant de l'hyper-arête à obtenir.
	 */
	boost::shared_ptr<HyperEdge>& getHyperEdgeById(const unsigned int&);

	/**
	 * Construction de l'hypergraphe, notamment de sa matrice d'adjacence.
	 */
	void flush();

	/**
	 * Destructeur.
	 */
	~Hypergraphe();

protected:

};



#endif /* MODEL_INCLUDE_HYPERGRAPHE_HH_ */

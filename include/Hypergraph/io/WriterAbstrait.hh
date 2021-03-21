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
 * Interface du module d'écriture d'instance.
 */
#ifndef IO_INCLUDE_WRITERABSTRAIT_HH_
#define IO_INCLUDE_WRITERABSTRAIT_HH_

#include "../model/HypergrapheAbstrait.hh"
#include <boost/shared_ptr.hpp>

/**
 * Déclaration de l'interface du module d'écriture d'instance.
 */
class WriterAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	WriterAbstrait(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Ecriture de la matrice d'adjacence sur la sortie indiquée.
	 * @param Le flux de sortie.
	 */
	virtual void writeAdjacentMatrix(std::ostream&) const = 0;

	/**
	 * Ecriture de l'hypergraphe sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	virtual void writeHypergraph(std::ostream&) const = 0;

	/**
	 * Destructeur virtuel.
	 */
	virtual ~WriterAbstrait();


protected:

	/**
	 * Ecriture des hyper-vertex sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	virtual void writeHypergrapheHyperVertex(std::ostream&) const = 0;

	/**
	 * Ecriture des hyper-arêtes sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	virtual void writeHypergrapheHyperEdge(std::ostream&) const = 0;


protected:

	/**
	 * Pointeur partagé vers l'hypergraphe.
	 */
	boost::shared_ptr<HypergrapheAbstrait>
	_ptrHypergrapheAbstrait;

};



#endif /* IO_INCLUDE_WRITERABSTRAIT_HH_ */

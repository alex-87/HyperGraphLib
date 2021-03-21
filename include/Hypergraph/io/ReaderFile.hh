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
 * Module de lecture.
 */
#ifndef IO_INCLUDE_READERFILE_HH_
#define IO_INCLUDE_READERFILE_HH_

#include "ReaderAbstrait.hh"
#include <istream>


/**
 * Déclaration du module de lecture.
 */
class ReaderFile : public ReaderAbstrait {

public:

	/**
	 * Constructeur.
	 */
	ReaderFile();

	/**
	 * Lecture de l'instance de l'hypergraphe.
	 * @param Le flux entrant.
	 */
	void readHypergraphe(std::istream&);

	/**
	 * Deestructeur.
	 */
	~ReaderFile();


protected:

	/**
	 * Lecture des hyper-vertex de l'instance.
	 * @param Le flux entrant.
	 */
	void readHypergrapheHyperVertex(std::istream&);

	/**
	 * Lecture des hyper-arêtes de l'instance.
	 * @param Le flux entrant.
	 */
	void readHypergrapheHyperEdge(std::istream&);

	/**
	 * Obtenir l'hyper-vertex via l'identifiant numérique.
	 * @param L'identifiant numérique.
	 */
	boost::shared_ptr<HyperVertex>& hyperVertexById(unsigned int&);

	/**
	 * Obtenir l'hyper-arête via l'identifiant numérique.
	 * @param L'identifiant numérique.
	 */
	boost::shared_ptr<HyperEdge>& hyperEdgeById(unsigned int&);

	/**
	 * Construction de l'instance après lecture.
	 */
	void flush();


protected:

	/**
	 * Liste des hyper-vertex lus.
	 */
	LibType::ListHyperVertex
	_listHyperVertex;

	/**
	 * Liste des hyper-arêtes lues.
	 */
	LibType::ListHyperEdge
	_listHyperEdge;

};


#endif /* IO_INCLUDE_READERFILE_HH_ */

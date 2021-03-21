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
 * Module d'écriture d'une instance d'hypergraphe.
 */
#ifndef IO_INCLUDE_WRITERFILE_HH_
#define IO_INCLUDE_WRITERFILE_HH_

#include "WriterAbstrait.hh"

/**
 * Délaration du module d'écriture de l'instance d'un hypergraphe.
 */
class WriterFile : public WriterAbstrait {

public:

	/**
	 * Constructeur.
	 * @param Pointeur partagé vers l'hypergraphe.
	 */
	WriterFile(const boost::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Eciture de la matrice d'adjacence sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	void writeAdjacentMatrix(std::ostream&) const;

	/**
	 * Ecriture de l'instance de l'hypergraphe sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	void writeHypergraph(std::ostream&) const;


protected:

	/**
	 * Ecriture des hyper-vertex sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	void writeHypergrapheHyperVertex(std::ostream&) const;

	/**
	 * Ecriture des hyper-arêtes sur le flux de sortie.
	 * @param Le flux de sortie.
	 */
	void writeHypergrapheHyperEdge(std::ostream&) const;


protected:

};



#endif /* IO_INCLUDE_READERFILE_HH_ */

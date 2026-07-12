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
 * Interface du module de lecture d'instance.
 */
#ifndef IO_INCLUDE_READERABSTRAIT_HH_
#define IO_INCLUDE_READERABSTRAIT_HH_

#include "../model/HypergrapheAbstrait.hh"
#include <memory>

/**
 * Dfinition de l'interface du module de lecture d'instance.
 */
class ReaderAbstrait {
  public:
	/**
	 * Constructor.
	 * @param shared pointer to the hypergraph.
	 */
	ReaderAbstrait(const std::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Read the instance and build the hypergraph.
	 * @param Le flux entrant.
	 */
	virtual void readHypergraphe(std::istream&) = 0;

	/**
	 * Get the hypergraph after construction.
	 */
	std::shared_ptr<HypergrapheAbstrait>&
	getHypergraphe();

	/**
	 * Virtual destructor.
	 */
	virtual ~ReaderAbstrait() = default;


  protected:
	/**
	 * Read the hyper-vertices of the instance.
	 * @param Le flux entrant.
	 */
	virtual void readHypergrapheHyperVertex(std::istream&) = 0;

	/**
	 * Read the hyper-edges of the instance.
	 * @param Le flux entrant.
	 */
	virtual void readHypergrapheHyperEdge(std::istream&) = 0;


  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<HypergrapheAbstrait>
	_ptrAbstractHypergraph;

};


#endif /* IO_INCLUDE_READERABSTRAIT_HH_ */

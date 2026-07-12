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
 * Definition of the algorithm listing the set of paths in a hypergraph.
 * linking a vertex e1 to a vertex e2.
 */

#ifndef ALGORITHM_INCLUDE_PATH_HH_
#define ALGORITHM_INCLUDE_PATH_HH_

#include "../model/HypergrapheAbstrait.hh"
#include "../model/AlgorithmeAbstrait.hh"
#include "../model/RStructurePath.hh"

class Path : public AlgorithmeAbstrait {
  public:
	/*
	 * Constructor.
	 * @param std::shared_ptr<HypergrapheAbstrait> shared pointer to the hypergraph.
	 */
	Path(std::shared_ptr<HypergrapheAbstrait>&);

	/**
	 * Configure the vertices used to list the paths.
	 */
	void setHyperVertex(std::shared_ptr<HyperVertex>&, std::shared_ptr<HyperVertex>&);

	/**
	 * Get the result structure.
	 */
	RStructure getResult() const;

	/**
	 * Get the result structure.
	 */
	RStructurePath getPathResult() const;

	/**
	 * Set the maximum number of paths. Default 0, meaning unbounded.
	 */
	void setLimit(unsigned int);

	/**
	 * Read the limit value.
	 */
	unsigned int getLimit() const;

	/**
	 * Destructor.
	 */
	~Path() = default;


  protected:
	/**
	 * Run the algorithm.
	 */
	void runAlgorithme();

	/**
	 * Check whether the hyper-vertex is contained in the list.
	 */
	bool vertexContained(LibType::ListHyperVertex&, std::shared_ptr<HyperVertex>&) const;

	/**
	 * Add the hyper-vertices of a hyper-edge to the given list.
	 */
	void addVertexList(LibType::ListHyperVertex&, LibType::ListHyperVertex&, const std::shared_ptr<HyperEdge>&) const;


	void buildPathToPathList(LibType::PathList&, LibType::ListHyperVertex&);

  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<HypergrapheAbstrait>
	_ptrAbstractHypergraph;

	/**
	 * Vertex source
	 */
	std::shared_ptr<HyperVertex> _source;

	/**
	 * Vertex destination
	 */
	std::shared_ptr<HyperVertex> _destination;

	/**
	 * Result structure.
	 */
	RStructurePath _result;

	/**
	 * Valeur limite.
	 */
	unsigned int _limit;
};


#endif /* SRC_ALGORITHM_INCLUDE_PATH_HH_ */

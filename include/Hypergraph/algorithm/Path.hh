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

#ifndef ALGORITHM_INCLUDE_PATH_HH_
#define ALGORITHM_INCLUDE_PATH_HH_

#include "../model/AbstractHypergraph.hh"
#include "../model/AbstractAlgorithm.hh"
#include "../model/ResultStructurePath.hh"

/**
 * @brief Implementation of the `PATH` algorithm.
 *
 * This algorithm lists the set of paths in a hypergraph linking a
 * source hyper-vertex to a destination hyper-vertex.
 */
class Path : public AbstractAlgorithm {
  public:
	/**
	 * @brief Construct a new Path object.
	 * @param hypergraph to which the algorithm is applied.
	 */
	Path(std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Configure the vertices used to list the paths.
	 * @param source hyper-vertex.
	 * @param destination hyper-vertex.
	 */
	void setHyperVertex(std::shared_ptr<HyperVertex>&, std::shared_ptr<HyperVertex>&);

	/**
	 * @brief Get the result.
	 * @return ResultStructure
	 */
	ResultStructure getResult() const;

	/**
	 * @brief Get the path-specific result.
	 * @return ResultStructurePath
	 */
	ResultStructurePath getPathResult() const;

	/**
	 * @brief Set the maximum number of paths. Default 0, meaning unbounded.
	 * @param limit value.
	 */
	void setLimit(unsigned int);

	/**
	 * @brief Read the limit value.
	 * @return the limit value.
	 */
	unsigned int getLimit() const;

	/**
	 * @brief Destructor.
	 */
	~Path() = default;


  protected:
	/**
	 * @brief Run the algorithm.
	 */
	void run();

	/**
	 * @brief Check whether the hyper-vertex is contained in the list.
	 * @param list of hyper-vertices.
	 * @param hyper-vertex to look for.
	 * @return `true` if contained, `false` otherwise.
	 */
	bool vertexContained(LibType::ListHyperVertex&, std::shared_ptr<HyperVertex>&) const;

	/**
	 * @brief Add the hyper-vertices of a hyper-edge to the given list.
	 * @param list of already-visited hyper-vertices.
	 * @param list to which new hyper-vertices are added.
	 * @param hyper-edge whose hyper-vertices are considered.
	 */
	void addVertexList(LibType::ListHyperVertex&, LibType::ListHyperVertex&, const std::shared_ptr<HyperEdge>&) const;

	/**
	 * @brief Append a path to the list of paths found so far.
	 * @param list of paths.
	 * @param path to append.
	 */
	void buildPathToPathList(LibType::PathList&, LibType::ListHyperVertex&);

  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraph;

	/**
	 * Source hyper-vertex.
	 */
	std::shared_ptr<HyperVertex> _source;

	/**
	 * Destination hyper-vertex.
	 */
	std::shared_ptr<HyperVertex> _destination;

	/**
	 * Result structure.
	 */
	ResultStructurePath _result;

	/**
	 * Limit value.
	 */
	unsigned int _limit;
};


#endif /* SRC_ALGORITHM_INCLUDE_PATH_HH_ */

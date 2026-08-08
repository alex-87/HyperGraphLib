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

#ifndef ALGORITHM_INCLUDE_HPGSTAT
#define ALGORITHM_INCLUDE_HPGSTAT

#include <memory>
#include "../model/AbstractHypergraph.hh"
#include "../model/Hypergraph.hh"
#include "../model/HyperVertex.hh"
#include "../model/HyperEdge.hh"
#include "../model/AbstractAlgorithm.hh"
#include "../model/ResultStructure.hh"


/**
 * @brief Computing statistics for a given hypergraph.
 *
 * This algorithm computes descriptive statistics of a hypergraph: its
 * number of hyper-edges, number of hyper-vertices, number of
 * vertex-edge connections, rank and co-rank.
 */
class HyperGraphStat : public AbstractAlgorithm {
  public:
	/**
	 * @brief Construct a new HyperGraphStat object.
	 * @param hypergraph to which the algorithm is applied.
	 */
	HyperGraphStat(const std::shared_ptr<AbstractHypergraph>&);

	/**
	 * @brief Get the result — unused here.
	 * @return ResultStructure — unused here.
	 */
	ResultStructure getResult() const;

	/**
	 * @brief Destructor.
	 */
	~HyperGraphStat() = default;


  public:
	/**
	 * @brief Get the number of hyper-edges.
	 * @return the number of hyper-edges.
	 */
	unsigned int getNbrHyperEdge() const;

	/**
	 * @brief Get the number of hyper-vertices.
	 * @return the number of hyper-vertices.
	 */
	unsigned int getNbrHyperVertex() const;

	/**
	 * @brief Get the number of vertex-edge connections.
	 * @return the number of vertex-edge connections.
	 */
	unsigned int getNbrLinks() const;

	/**
	 * @brief Get the rank of the hypergraph.
	 * @return the rank of the hypergraph.
	 */
	unsigned int getRang() const;

	/**
	 * @brief Get the co-rank of the hypergraph.
	 * @return the co-rank of the hypergraph.
	 */
	unsigned int getCoRang() const;

  protected:
	/**
	 * @brief Run the algorithm.
	 */
	void run();

  protected:
	/**
	 * Shared pointer to the hypergraph.
	 */
	std::shared_ptr<AbstractHypergraph>
	    _ptrAbstractHypergraph;

	/**
	 * The result structure - unused here.
	 */
	ResultStructure _result;

	/**
	 * The number of hyper-edges.
	 */
	unsigned int _nhEdge;

	/**
	 * The number of hyper-vertices.
	 */
	unsigned int _nhVertex;

	/**
	 * The number of vertex-edge connections.
	 */
	unsigned int _nhLink;

	/**
	 * The rank of the hypergraph.
	 */
	unsigned int _rank;

	/**
	 * The co-rank of the hypergraph.
	 */
	unsigned int _coRank;
};


#endif

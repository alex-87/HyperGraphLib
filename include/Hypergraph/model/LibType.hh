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

#ifndef MODEL_INCLUDE_LIBTYPE_HH_
#define MODEL_INCLUDE_LIBTYPE_HH_

#include <unordered_map>
#include <vector>
#include <memory>
#include "../container/matrix2D.hpp"

class HyperEdge;
class HyperVertex;

/**
 * @brief Utility class grouping the type aliases used throughout the library.
 */
class LibType {
  public:
	/**
	 * Boolean adjacency matrix container.
	 */
	typedef Matrix2D<bool>
	    AdjacentMatrixContainerBool;

	/**
	 * List of hypervertices.
	 */
	typedef std::vector<std::shared_ptr<HyperVertex>>
	    ListHyperVertex;

	/**
	 * List of hyperedges.
	 */
	typedef std::vector<std::shared_ptr<HyperEdge>>
	    ListHyperEdge;

	/**
	 * Table indexing hypervertices, mapped to an integer index.
	 */
	typedef std::unordered_map<std::shared_ptr<HyperVertex>, int>
	    IndexerHyperVertex;

	/**
	 * Table indexing hyperedges, mapped to an integer index.
	 */
	typedef std::unordered_map<std::shared_ptr<HyperEdge>, int>
	    IndexerHyperEdge;

	/**
	 * Table indexing hypervertices by their numeric identifier.
	 */
	typedef std::unordered_map<unsigned int, std::shared_ptr<HyperVertex>>
	    HyperVertexIndexer;

	/**
	 * Table indexing hyperedges by their numeric identifier.
	 */
	typedef std::unordered_map<unsigned int, std::shared_ptr<HyperEdge>>
	    HyperEdgeIndexer;

	/**
	 * List of paths, each path being a list of hypervertices.
	 */
	typedef std::shared_ptr<std::vector<LibType::ListHyperVertex>>
	    PathList;

  private:
	/**
	 * Constructor, private: this is a static utility class and must not be instantiated.
	 */
	LibType();
	LibType(const LibType&) = delete;
	LibType& operator=(const LibType&) = delete;
};


#endif /* MODEL_INCLUDE_LIBTYPE_HH_ */

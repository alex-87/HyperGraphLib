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

#include <map>
#include <vector>
#include <boost/container/vector.hpp>
#include <boost/multi_array.hpp>
#include <boost/interprocess/allocators/allocator.hpp>


class HyperVertex;

class HyperEdge;

class LibType {

public:


	typedef boost::multi_array<bool, 2>
	AdjacentMatrixContainerBool;

	typedef boost::multi_array<int, 2>
	AdjacentMatrixContainerInt;

	typedef boost::container::vector<boost::shared_ptr<HyperVertex> >
	ListHyperVertex;

	typedef boost::container::vector<boost::shared_ptr<HyperEdge> >
	ListHyperEdge;

	typedef std::map<boost::shared_ptr<HyperVertex>, int>
	IndexerHyperVertex;

	typedef std::map<boost::shared_ptr<HyperEdge>, int>
	IndexerHyperEdge;

	typedef std::map<unsigned int, boost::shared_ptr<HyperVertex> >
	HyperVertexIndexer;

	typedef std::map<unsigned int, boost::shared_ptr<HyperEdge> >
	HyperEdgeIndexer;

	typedef boost::shared_ptr<boost::container::vector<LibType::ListHyperVertex> >
	PathList;

private:

	LibType();
	LibType(const LibType&) = delete;
	LibType& operator=(const LibType&) = delete;
};


#endif /* MODEL_INCLUDE_LIBTYPE_HH_ */

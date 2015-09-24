
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

	typedef boost::container::vector<HyperVertex>
	ListHyperVertex;

	typedef boost::container::vector<HyperEdge>
	ListHyperEdge;

	typedef std::map<HyperVertex, int>
	IndexerHyperVertex;

	typedef std::map<HyperEdge, int>
	IndexerHyperEdge;

	typedef std::map<unsigned int, HyperVertex>
	HyperVertexIndexer;

	typedef std::map<unsigned int, HyperEdge>
	HyperEdgeIndexer;

private:

	LibType();
	LibType(const LibType&) = delete;
	LibType& operator=(const LibType&) = delete;
};


#endif /* MODEL_INCLUDE_LIBTYPE_HH_ */

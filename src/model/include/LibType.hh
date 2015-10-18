
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

private:

	LibType();
	LibType(const LibType&) = delete;
	LibType& operator=(const LibType&) = delete;
};


#endif /* MODEL_INCLUDE_LIBTYPE_HH_ */

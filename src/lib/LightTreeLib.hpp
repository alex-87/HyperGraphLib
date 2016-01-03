/*
 * LightTreeLib - Small C++ Template library - Used in HypergraphLib
 *
 */

#ifndef LIGHTTREELIB_HPP_
#define LIGHTTREELIB_HPP_

#include <map>
#include <boost/shared_ptr.hpp>

template<class T>
class LightTree {

public:

        LightTree(const T& t) : _t( t ) {
                _cnt = 0;
        }

        void
        setElement(const T& t) {
                _t = t;
        }

        void
        addNode(boost::shared_ptr<LightTree<T> >& lightTree) {
                _mapNode[_cnt] = lightTree;
                _cnt++;
        }

        boost::shared_ptr<LightTree<T> >&
        getNode(unsigned int nodeId) {
                return _mapNode[nodeId];
        }

        unsigned int
        getCardinal() const {
                return _cnt;
        }

        T&
        getElement() {
                return _t;
        }

        ~LightTree() {
        }

private:

	T _t;
	unsigned int _cnt;
	std::map<unsigned int, boost::shared_ptr<LightTree<T> > > _mapNode;

};


#endif /* LIGHTTREELIB_HPP_ */

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

/*
 * LightTreeLib - Small C++ Template library - Used in HypergraphLib
 *
 */

#ifndef LIGHTTREELIB_HPP_
#define LIGHTTREELIB_HPP_

#include <map>
#include <boost/shared_ptr.hpp>

template<typename T>
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

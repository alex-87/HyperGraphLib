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

#ifndef HYPERGRAPHLIB_CONTAINER_MATRIX2D
#define HYPERGRAPHLIB_CONTAINER_MATRIX2D

#include <vector>
#include <cstddef>

template <typename T>
class Matrix2D {
  public:
	typedef typename std::vector<T>::reference reference;
	typedef typename std::vector<T>::const_reference const_reference;

	Matrix2D()
	    : _m(0), _n(0) {
	}

	Matrix2D(std::size_t m, std::size_t n)
	    : _m(m),
	      _n(n),
	      _data(m * n) {
	}

	void resize(std::size_t m, std::size_t n) {
		_m = m;
		_n = n;
		_data.assign(m * n, T());
	}

	reference operator()(std::size_t i, std::size_t j) {
		return _data[i * _n + j];
	}

	const_reference operator()(std::size_t i, std::size_t j) const {
		return _data[i * _n + j];
	}

	std::size_t rows() const {
		return _m;
	}

	std::size_t cols() const {
		return _n;
	}


  private:
	std::size_t _m, _n;

	std::vector<T> _data;
};

#endif // HYPERGRAPHLIB_CONTAINER_MATRIX2D

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


#ifndef CLIENT_INCLUDE_CLIENT_HH_
#define CLIENT_INCLUDE_CLIENT_HH_

#include <memory>
#include <utility>

#include "../../include/Hypergraph/model/AlgorithmeAbstrait.hh"

#define VERSION_MAJOR 3
#define VERSION_MINOR 0
#define VERSION_BUILD 0

/**
 * Build an algorithm and return it as a base-class shared pointer.
 * Replaces the former NewAlgorithm / NewAlgorithm2 macros.
 */
template <typename Algorithm, typename... Args>
std::shared_ptr<AlgorithmeAbstrait> makeAlgorithm(Args&&... args) {
	return std::make_shared<Algorithm>(std::forward<Args>(args)...);
}

#endif /* CLIENT_INCLUDE_CLIENT_HH_ */

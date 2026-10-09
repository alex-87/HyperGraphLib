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

#include "Hypergraph/algorithm/kRegular.hh"

kRegular::kRegular(const std::shared_ptr<AbstractHypergraph>& ptrAbstractHypergraph) {
	_ptrAbstractHypergraph = ptrAbstractHypergraph;
}

void kRegular::run() {
	_result.setBooleanResult(true);
	const IncidenceMatrix& matrix(_ptrAbstractHypergraph->getIncidenceMatrix());

	int count = -1;
	for (const auto& hyperVertex : _ptrAbstractHypergraph->getHyperVertexList()) {
		if (count == -1) {
			count = matrix.getVertexDegree(hyperVertex);
		} else {
			if ((int)matrix.getVertexDegree(hyperVertex) != count) {
				_result.setBooleanResult(false);
			};
		};
	}

	if (count == -1)
		_result.setBooleanResult(true);
}

ResultStructure
kRegular::getResult() const {
	return _result;
}

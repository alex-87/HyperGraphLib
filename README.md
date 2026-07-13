# HyperGraphLib

Hypergraphs modelling library with algorithms, [the official page](https://alex-87.github.io/HyperGraphLib) for more informations.

![hypergraph](http://alex-87.github.io/HyperGraphLib/images/hypergraph.png)

## Implemented algorithms

- Connected
- Diameter
- Dual
- Helly
- Isomorphism (*using Constraint-based programming and Depth-first Search*)
- k-Regular
- k-Uniform
- Linear
- Path finding
- Simple

## Build, Test & Install

### Requirements

  - [cmake](https://github.com/Kitware/CMake) (>= 3.28)
  - [g++](https://gcc.gnu.org) (>= 9.0)
  - [Gecode](http://www.gecode.dev) (>= 6.2.0)

### Installation Steps

```shell
git clone https://github.com/alex-87/HyperGraphLib.git && cd HyperGraphLib
cmake -B build && cmake --build build -j   # Build
ctest --test-dir build                     # Test
sudo cmake --install build                 # Install
```

## Documentation

See the [Official page](https://alex-87.github.io/HyperGraphLib);

Reference documentation, generated using [Doxygen](http://www.doxygen.org) is available at [the technical documentation page](https://alex-87.github.io/HyperGraphLib/doc).

## Example

```cpp
#include <iostream>
#include <memory>
#include <Hypergraph/model/Hypergraph.hh>
#include <Hypergraph/model/HyperFactory.hh>
#include <Hypergraph/model/AlgorithmEngine.hh>
#include <Hypergraph/algorithm/Isomorph.hh>
#include <Hypergraph/algorithm/Simple.hh>

int main(int argc, char * argv[]) {

    // Creating the hypergraph inside smart pointer
    std::shared_ptr<AbstractHypergraph> ptrHpg( new Hypergraph() );

    // Starting the create session
    HyperFactory::startSession(ptrHpg);

    // Creating the hyper-edges
    std::shared_ptr<HyperEdge> ptrEdge1 ( HyperFactory::newHyperEdge() );
    std::shared_ptr<HyperEdge> ptrEdge2 ( HyperFactory::newHyperEdge() );

    // Creating the hyper-vertexes
    std::shared_ptr<HyperVertex> ptrVertexA( HyperFactory::newHyperVertex() );
    std::shared_ptr<HyperVertex> ptrVertexB( HyperFactory::newHyperVertex() );

    // The hyper-vertex A is contained inside the hyper-edge 1
    HyperFactory::link(ptrVertexA, ptrEdge1);
    // The hyper-vertex B is contained inside the hyper-edge 2
    HyperFactory::link(ptrVertexB, ptrEdge2);

    // Adding the hyper-vertexes in the hypergraph
    ptrHpg->addHyperVertex(ptrVertexA);
    ptrHpg->addHyperVertex(ptrVertexB);

    // Adding the hyper-edges in the hypergraph
    ptrHpg->addHyperEdge(ptrEdge1);
    ptrHpg->addHyperEdge(ptrEdge2);

    // Creating the adjacent matrix inside the hypergraph
    ptrHpg->flush();

    // Closing the session
    HyperFactory::closeSession();

    // -- -- --

    // Initializing the Isomorphism algorithm with ptrHpg (twice, just for the example)
    std::shared_ptr<AbstractAlgorithm> isomorphPtr( new Isomorph(ptrHpg, ptrHpg) );

    // Setting the engine's algorithm
    AlgorithmEngine::setAlgorithme(isomorphPtr);

    // Running the engine
    AlgorithmEngine::runAlgorithme();

    // Getting the result
    ResultStructure r1( isomorphPtr->getResult() );

    if( r1.getBooleanResult() ) {
    	std::cout << "The hypergraph is isomorph with itself" << std::endl;
    }

    // -- -- --

    // Initializing the Simple algorithm with ptrHpg (twice, just for the example)
    std::shared_ptr<AbstractAlgorithm> simplephPtr( new Simple( ptrHpg ) );

    // Setting the engine's algorithm
    AlgorithmEngine::set(simplephPtr);

    // Running the engine
    AlgorithmEngine::run();

    // Getting the result
    ResultStructure r2( simplephPtr->getResult() );

    if( r2.getBooleanResult() ) {
        std::cout << "The hypergraph is simple." << std::endl;
    }

    return 0;
}
```

### Building the Example

```shell
g++ example.cpp -std=c++17 -o example -lhypergraph
```
#### Execution & Output

```
$ ./example
The hypergraph is isomorph with itself
The hypergraph is simple.
```

## License

This software is licensed under the **[MIT License](LICENSE)**.

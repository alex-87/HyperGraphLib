
#ifndef CLIENT_INCLUDE_CLIENT_HH_
#define CLIENT_INCLUDE_CLIENT_HH_

#define VERSION_MAJOR 2
#define VERSION_MINOR 0
#define VERSION_BUILD 0

#define NewAlgorithm(a, b, c) boost::shared_ptr<AlgorithmeAbstrait> a( new b( c ) );
#define NewAlgorithm2(a, b, c, d) boost::shared_ptr<AlgorithmeAbstrait> a( new b( c , d ) );


#endif /* CLIENT_INCLUDE_CLIENT_HH_ */


#ifndef CLIENT_INCLUDE_CLIENT_HH_
#define CLIENT_INCLUDE_CLIENT_HH_

#define VERSION_MAJOR 0
#define VERSION_MINOR 16
#define VERSION_BUILD 1

#define NewAlgorithm(a, b, c) boost::shared_ptr<AlgorithmeAbstrait> a( new b( c ) );


#endif /* CLIENT_INCLUDE_CLIENT_HH_ */

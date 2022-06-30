#include "linearMap.h"
#include <iostream>
#include <sstream>

LinearMap::LinearMap( Vector &a )
    : a( a )
{
}

double LinearMap::evaluate( Vector &v )
{

    return a.dot( v );
}

std::string LinearMap::str( )
{
    std::ostringstream os;
    os << a.toString( ) << " . x";
    return os.str( );
}

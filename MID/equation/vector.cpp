#include "vector.h"
#include <sstream>

Vector::Vector( double w, double q )
    : w( w )
    , q( q )
{
}

Vector::Vector( Vector &v )
    : w( v.w )
    , q( v.q )
{
}

double Vector::getX( )
{
    return w;
}

double Vector::getY( )
{
    return this->q;
}

Vector Vector::add( Vector &v )
{

    return Vector( w + v.w, q + v.q );
}

Vector Vector::scale( double s )
{
    return Vector( s * w, s * q );
}

double Vector::dot( Vector &v )
{
    return w * v.w + q * v.q;
}

std::string Vector::toString( )
{
    std::ostringstream is;
    is << "(" << w << ", " << q << ")";
    return is.str( );
}

#include "linearEquation.h"
LinearEquation::LinearEquation( Vector &x, Vector &y )
    : a1( x )
    , a2( y )
{
}

Vector LinearEquation::solve( Vector &v )
{
    // Solves system of linear equations by Cramer rule
    double det
        = a1.getX( ) * a2.getY( ) - a1.getY( ) * a2.getX( );
    if ( det == 0 )
    {
        throw std::string(
            "No solution for " + v.toString( ) );
    }

    double det1
        = v.getX( ) * a2.getY( ) - v.getY( ) * a2.getX( );
    double x = det1 / det;
    double det2
        = a1.getX( ) * v.getY( ) - a1.getY( ) * v.getX( );
    double y = det2 / det;
    return Vector( x, y );
}

std::string LinearEquation::str( )
{
    return a1.toString( ) + ". v = b1 \n" + a2.toString( )
           + ".v = b2";
}

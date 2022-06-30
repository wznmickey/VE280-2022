#include "standardForm.h"
#include <cmath>

QuadraticFunction::QuadraticFunction(
    float a_in,
    float b_in,
    float c_in )
    : a( a_in )
    , b( b_in )
    , c( c_in )
{
}
// TODO: implement this constructor

float QuadraticFunction::getA( ) const
{
    return a;
}

float QuadraticFunction::getB( ) const
{
    return b;
}

float QuadraticFunction::getC( ) const
{
    return c;
}

float QuadraticFunction::evaluate( float x )
{
    // TODO: implement this function
    return a * x * x + b * x + c;
}

Root QuadraticFunction::getRoot( )
{
    // TODO: implement this function
    float d = b * b - a * c * 4;
    Root  ans;
    if ( std::fabs( d - 0 ) <= 0.0001 )
    {

        ans.roots [ 0 ].real      = ( -b ) / ( a * 2 );
        ans.roots [ 1 ].real      = ans.roots [ 0 ].real;
        ans.roots [ 0 ].imaginary = 0;
        ans.roots [ 1 ].imaginary = 0;
        ans.realRootNum           = 1;
    }
    else if ( d > 0 )
    {
        float ans1
            = ( -b + float( std::sqrt( d ) ) ) / ( a * 2 );
        float ans2
            = ( -b - float( std::sqrt( d ) ) ) / ( a * 2 );
        ans.roots [ 0 ].real
            = std::fmin( ( ans1 ), ( ans2 ) );
        ans.roots [ 1 ].real      = std::fmax( ans1, ans2 );
        ans.roots [ 0 ].imaginary = 0;
        ans.roots [ 1 ].imaginary = 0;
        ans.realRootNum           = 2;
    }
    else if ( d < 0 )
    {
        ans.roots [ 0 ].real      = ( -b ) / ( a * 2 );
        ans.roots [ 1 ].real      = ( -b ) / ( a * 2 );
        ans.roots [ 0 ].imaginary = -std::fabs(
            float( std::sqrt( -d ) ) / float( a * 2 ) );
        ans.roots [ 1 ].imaginary = std::fabs(
            float( std::sqrt( -d ) ) / float( a * 2 ) );
        ans.realRootNum = 0;
    }
    return ans;
}

bool QuadraticFunction::intersect( QuadraticFunction q )
{
    QuadraticFunction x( q.a - a, q.b - b, q.c - c );
    if ( x.getA( ) == 0 )
    {
        if ( ( x.getB( ) == 0 ) && ( x.getC( ) == 0 ) )
            return true;
        if ( x.getB( ) == 0 )
            return false;
        return true;
    }

    Root ans = x.getRoot( );
    if ( ans.realRootNum >= 1 )
        return true;
    return false;
    // TODO: implement this function
}
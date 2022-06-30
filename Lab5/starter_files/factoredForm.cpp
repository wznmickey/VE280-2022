#include "factoredForm.h"

QuadraticFunction::QuadraticFunction(
    float a_in,
    float b_in,
    float c_in )
{

    a = a_in;

    auto b = b_in;
    auto c = c_in;

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
    r1 = ans.roots [ 0 ];
    r2 = ans.roots [ 1 ];
}
// TODO: implement this constructor

float QuadraticFunction::getA( ) const
{
    return a;
}

float QuadraticFunction::getB( ) const
{
    // TODO: implement this function
    return ( r1.real + r2.real ) * ( -a ); // x1+x2 = -b/a
}

float QuadraticFunction::getC( ) const
{
    // TODO: implement this function
    return ( r1.real * r2.real
             + r1.imaginary * r1.imaginary )
           * ( a ); // x1x2=c/a
}

float QuadraticFunction::evaluate( float x )
{
    // TODO: implement this function
    auto b = ( r1.real + r2.real ) * ( -a );
    auto c = ( r1.real * r2.real
               + r1.imaginary * r1.imaginary )
             * ( a );
    return a * x * x + b * x + c;
}

Root QuadraticFunction::getRoot( )
{
    // TODO: implement this function
    auto b = ( r1.real + r2.real ) * ( -a );
    auto c = ( r1.real * r2.real
               + r1.imaginary * r1.imaginary )
             * ( a );
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
    // TODO: implement this function
    auto b = ( r1.real + r2.real ) * ( -a );
    auto c = ( r1.real * r2.real
               + r1.imaginary * r1.imaginary )
             * ( a );
    QuadraticFunction x(
        q.a - a,
        q.getB( ) - b,
        q.getC( ) - c );
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
}
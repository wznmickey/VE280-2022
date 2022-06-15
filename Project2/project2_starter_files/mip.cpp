#include "constants.h"
#include "image.h"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios_base;
using std::istream;
using std::max;
// using std::min;
using std::ofstream;
using std::ostream;
// using std::sort;
using std::string;
using std::vector;
const int s = 1;
using Agg   = unsigned char (   *)(
    const unsigned char (   *) [ 3 ] );

// Can not let imI and imJ be the reference of same Image.
void readImage( std::istream &is, Image &imI );
void writeImage( std::ostream &os, const Image &imI );
void verticalFlip( const Image &imI, Image &imJ );
void rotate90( const Image &imI, Image &imJ );
void intensityInversion( const Image &imI, Image &imJ );
void filter( const Image &imI, Image &imJ, Agg f );
auto transformationFun(
    string      &transformation,
    const Image &x,
    Image       &y ) -> bool;
const auto filterMax
    = []( const unsigned char values [ 2 * s + 1 ]
                                     [ 2 * s + 1 ] )
{
    auto ans = values [ 0 ][ 0 ];
    for ( int i = 0; i < 2 * s + 1; i++ )
    {
        for ( int j = 0; j < 2 * s + 1; j++ )
        {
            ans = max( ans, values [ i ][ j ] );
        }
    }
    return ( unsigned char ) ans;
};
// Not needed.
// const auto filterMin
//     = []( const unsigned char values [ 2 * s + 1 ][ 2 * s
//     + 1 ] )
// {
//     auto ans = values [ 0 ][ 0 ];
//     for ( int i = 0; i < 2 * s + 1; i++ )
//     {
//         for ( int j = 0; j < 2 * s + 1; j++ )
//         {
//             ans = min( ans, values [ i ][ j ] );
//         }
//     }
//     return ans;
// };
const auto filterMean
    = []( const unsigned char values [ 2 * s + 1 ]
                                     [ 2 * s + 1 ] )
{
    int ans = 0;
    for ( int i = 0; i < 2 * s + 1; i++ )
    {
        for ( int j = 0; j < 2 * s + 1; j++ )
        {
            ans = ans + ( int ) values [ i ][ j ];
        }
    }
    return (
        unsigned char ) ( ans / ( ( 2 * s + 1 ) * ( 2 * s + 1 ) ) );
};
const auto filterMedian
    = []( const unsigned char values [ 2 * s + 1 ]
                                     [ 2 * s + 1 ] )
{
    vector< unsigned char > ans;
    for ( int i = 0; i < 2 * s + 1; i++ )
    {
        for ( int j = 0; j < 2 * s + 1; j++ )
        {
            ans.push_back( values [ i ][ j ] );
        }
    }
    sort( ans.begin( ), ans.end( ) );
    return ans [ ( 2 * s + 1 ) * ( 2 * s + 1 ) / 2 ];
};
auto operator>>( std::istream &is, Rgb &x ) -> istream &
{
    char temp = 0;
    is.get( temp );
    x.red = temp;
    is.get( temp );
    x.green = temp;
    is.get( temp );
    x.blue = temp;
    return is;
}
auto operator<<( std::ostream &is, const Rgb &x )
    -> ostream &
{
    is << ( unsigned char ) x.red
       << ( unsigned char ) x.green
       << ( unsigned char ) x.blue;
    return is;
}
auto operator-( const Rgb &in ) -> Rgb
{
    Rgb result;
    // C++ will default convert to int for calculation.
    // Keep every calculation in unsigned char.
    result.blue
        = ( unsigned char ) ( ( unsigned char ) M - ( unsigned char ) in.blue );
    result.red = ( unsigned char ) ( ( unsigned char ) M - ( unsigned char ) in.red );
    result.green
        = ( unsigned char ) ( ( unsigned char ) M - ( unsigned char ) in.green );
    return result;
}
void readImage( std::istream &is, Image &imI )
{
    string notCare;
    is >> notCare >> imI.w >> imI.h >> notCare;
    is.get( notCare [ 0 ] ); // Ignore the last std::endl.
    for ( auto j = 0U; j < imI.h; ++j )
    {
        for ( auto i = 0U; i < imI.w; ++i )
        {
            is >> imI.image [ i ][ j ];
        }
    }
    return;
}
void writeImage( std::ostream &os, const Image &imI )
{
    os << "P6" << endl
       << imI.w << ' ' << imI.h << endl
       << "255" << endl;

    for ( auto j = 0U; j < imI.h; ++j )
    {
        for ( auto i = 0U; i < imI.w; ++i )
        {
            os << imI.image [ i ][ j ];
        }
    }
    return;
}
void verticalFlip( const Image &imI, Image &imJ )
{
    imJ.h = imI.h;
    imJ.w = imI.w;
    for ( auto j = 0U; j < imJ.h; ++j )
    {
        for ( auto i = 0U; i < imJ.w; ++i )
        {
            imJ.image [ i ][ j ]
                = imI.image [ i ][ imJ.h - j - 1 ];
        }
    }
    return;
}
void rotate90( const Image &imI, Image &imJ )
{
    imJ.h = imI.w;
    imJ.w = imI.h;
    for ( auto j = 0U; j < imJ.h; ++j )
    {
        for ( auto i = 0U; i < imJ.w; ++i )
        {
            imJ.image [ i ][ j ]
                = imI.image [ j ][ imJ.w - i - 1 ];
        }
    }
    return;
}

void intensityInversion( const Image &imI, Image &imJ )
{
    imJ.h = imI.h;
    imJ.w = imI.w;
    for ( auto j = 0U; j < imJ.h; ++j )
    {
        for ( auto i = 0U; i < imJ.w; ++i )
        {
            imJ.image [ i ][ j ]
                = -( imI.image [ i ][ j ] );
        }
    }
    return;
}
void filter( const Image &imI, Image &imJ, Agg f )
{
    imJ.h = imI.h;
    imJ.w = imI.w;
    for ( int j = 0U; j < imJ.h; ++j )
    {
        for ( int i = 0U; i < imI.w; ++i )
        {
            unsigned char tempR [ 2 * s + 1 ][ 2 * s + 1 ];
            unsigned char tempG [ 2 * s + 1 ][ 2 * s + 1 ];
            unsigned char tempB [ 2 * s + 1 ][ 2 * s + 1 ];
            for ( int tempJ = ( ( int ) j ) - s;
                  tempJ <= j + s;
                  ++tempJ )
            {
                for ( int tempI = ( ( int ) i ) - s;
                      tempI <= i + s;
                      ++tempI )
                {
                    if ( ( ( tempI >= 0 )
                           && ( tempI < imI.w ) )
                         && ( ( tempJ >= 0 )
                              && ( tempJ < imI.h ) ) )
                    {
                        tempR [ tempI - ( i - s ) ]
                              [ tempJ - ( j - s ) ]
                            = imI.image [ tempI ][ tempJ ]
                                  .red;
                        tempG [ tempI - ( i - s ) ]
                              [ tempJ - ( j - s ) ]
                            = imI.image [ tempI ][ tempJ ]
                                  .green;
                        tempB [ tempI - ( i - s ) ]
                              [ tempJ - ( j - s ) ]
                            = imI.image [ tempI ][ tempJ ]
                                  .blue;
                    }
                    else
                    {
                        tempR [ tempI - ( i - s ) ]
                              [ tempJ - ( j - s ) ]
                            = 0;
                        tempG [ tempI - ( i - s ) ]
                              [ tempJ - ( j - s ) ]
                            = 0;
                        tempB [ tempI - ( i - s ) ]
                              [ tempJ - ( j - s ) ]
                            = 0;
                    }
                }
            }
            imJ.image [ i ][ j ].red   = f( tempR );
            imJ.image [ i ][ j ].green = f( tempG );
            imJ.image [ i ][ j ].blue  = f( tempB );
        }
    }
    return;
}
auto transformationFun(
    string      &transformation,
    const Image &x,
    Image       &y ) -> bool
{
    if ( transformation == "verticalFlip" )
    {
        verticalFlip( x, y );
    }
    else if ( transformation == "rotate90" )
    {
        rotate90( x, y );
    }
    else if ( transformation == "intensityInversion" )
    {
        intensityInversion( x, y );
    }
    else if ( transformation == "maxFilter" )
    {
        filter( x, y, filterMax );
    }
    else if ( transformation == "meanFilter" )
    {
        filter( x, y, filterMean );
    }
    else if ( transformation == "medianFilter" )
    {
        filter( x, y, filterMedian );
    }
    else
    {
        cout << TRANSFORM_ERROR << endl;
        return false;
    }
    return true;
}
auto main( int argc, char *argv [] ) -> int
{
    string transformation;
    bool   fromFile = false;
    bool   toFile   = false;
    string inputFilename;
    string outputFilename;

    for ( int i = 1; i < argc; i++ )
    {
        if ( string( argv [ i ] ) == "-t" )
        {
            i++;
            transformation = argv [ i ];
            continue;
        }
        if ( string( argv [ i ] ) == "-i" )
        {
            fromFile = true;
            i++;
            inputFilename = argv [ i ];
            continue;
        }
        if ( string( argv [ i ] ) == "-o" )
        {
            toFile = true;
            i++;
            outputFilename = argv [ i ];
            continue;
        }
        if ( string( argv [ i ] ) == "-h" )
        {
            cout << HELP_MESSAGE << endl;
            return 0;
        }
        if ( string( argv [ i ] ) == "--help" )
        {
            cout << HELP_MESSAGE << endl;
            return 0;
        }
    }
    Image x;
    Image y;
    if ( fromFile )
    {
        auto ifs = ifstream(
            inputFilename,
            ios_base::in | ios_base::binary );
        if ( ! ifs.is_open( ) )
        {
            cout << FILE_NOT_EXIST_ERROR << endl;
            return 0;
        }
        auto temp = inputFilename.rfind( ".ppm" );
        if ( temp == string::npos )
        {
            cout << FILE_TYPE_ERROR << endl;
            return 0;
        }
        readImage( ifs, x );
        ifs.close( );
    }
    else
    {
        readImage( cin, x );
    }

    if ( ! transformationFun( transformation, x, y ) )
    {
        return 0;
    }

    if ( toFile )
    {
        auto ofs = ofstream(
            outputFilename,
            ios_base::out | ios_base::binary );
        writeImage( ofs, y );
        ofs.close( );
    }
    else
    {
        writeImage( cout, y );
    }
    return 0;
}
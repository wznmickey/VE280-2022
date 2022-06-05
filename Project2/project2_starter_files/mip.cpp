#include "constants.h"
#include "image.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ios_base;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;

void readImage( std::istream &is, Image &imI );
void writeImage( std::ostream &os, const Image &imI );

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
    is << ( char ) x.red << ( char ) x.green
       << ( char ) x.blue;
    return is;
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
}

int main( )
{
    ifstream ifs(
        "first.ppm",
        ios_base::in | ios_base::binary );
    Image x;
    readImage( ifs, x );
    ofstream ofs(
        "second.ppm",
        ios_base::out | ios_base::binary );
    writeImage( ofs, x );
    ofs.close( );
    return 0;
}
#include "binaryTree.h"
#include "huffmanTree.h"
#include <fstream>
#include <iostream>
#include <vector>
int main( int  /*argc*/, char *argv [] )
{
    // TODO: implement this function
    std::string treeFile = argv [ 1 ];
    std::string binFile  = argv [ 2 ];
    HuffmanTree myTree( treeFile );

    auto                       file = std::ifstream( binFile );
    std::vector< std::string > map;
    map.resize( 300 );
    for ( auto i = 1; i < 255; i++ )
    {
        map [ i ] = ( myTree.findPath( std::string( 1, char(i) ) ) );
    }
    std::string c;
    while ( file >> c )
    {

        for ( auto i = 1; i < 255; i++ )
        {
            if ( c == map [ i ] )
            {
                std::cout << char( i );
                break;
            }
        }
    }
    return 0;
}
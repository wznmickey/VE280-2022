#include "binaryTree.h"
#include "huffmanTree.h"
#include <algorithm>
#include <endian.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

auto comp( const Node *a, const Node *b ) -> bool
// REQUIRES: both pointers are not nullptr
// EFFECTS: Return bool based on the data given
{

    if ( a->getnum( ) != b->getnum( ) )
    {
        return a->getnum( ) < b->getnum( );
    }
    return ( a->getstr( ) ) [ 0 ] < ( b->getstr( ) ) [ 0 ];
}

void handleArg( int argc, char *argv [], bool &tree, std::string &filename )
// REQUIRES: follow handout
// MODIFIES tree,filename
// EFFECTS: given value to vars

{
    for ( auto i = 1; i < argc; i++ )
    {
        if ( std::string( argv [ i ] ) == "-tree" )
        {
            tree = true;
        }
        else
        {
            filename = argv [ i ];
        }
    }
}

auto read( const std::string &filename ) -> std::string
// REQUIRES: valid filename
// EFFECTS: read file

{
    auto        file = std::ifstream( filename );
    std::string st;
    char        c = 0;
    while ( file.get( c ) )
    {
        st += c;
    }
    return st;
}

auto main( int argc, char *argv [] ) -> int
{
    // TODO: implement this function
    bool        tree = false;
    std::string filename;
    handleArg( argc, argv, tree, filename );
    // auto myTree = HuffmanTree( filename );

    std::vector< int > fre;
    fre.resize( 512 ); // prepare for bucket
    std::string st = read( filename );
    for ( auto &j : st )
    {
        ++fre [ j ];
    }

    std::vector< Node * > t;

    for ( auto j = 0; j < fre.size( ); j++ )
    {
        if ( fre [ j ] != 0 )
        {
            t.push_back( new Node( std::string( 1, char( j ) ), fre [ j ] ) );
        }
    }

    std::sort( t.begin( ), t.end( ), comp );

    // for (auto i : t)
    // {
    //     std::cout<<i->getnum()<<std::endl;
    // }

    while ( ! ( t.size( ) == 1 ) )
    {
        auto *temp = Node::mergeNodes( t [ 1 ], t [ 0 ] );
        t.erase( t.begin( ) );
        t.erase( t.begin( ) );
        t.push_back( temp );
        std::sort( t.begin( ), t.end( ), comp ); // Since there are limited elements, no need to insert sort.
    }
    HuffmanTree myTree( t [ 0 ] );

    if ( tree )
    {
        myTree.printTree( );
        return 0;
    }

    for ( auto &i : st )
    {
        std::string tt;
        tt += i;
        std::cout << myTree.findPath( tt ) << " ";
    }
    return 0;
}
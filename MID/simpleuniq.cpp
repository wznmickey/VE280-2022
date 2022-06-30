#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
auto main( int argc, char *argv [] ) -> int
{
    string name = argv [ 1 ];
    auto   ifs  = ifstream( name, ios_base::in );
    if ( ! ifs.is_open( ) )
    {
        cout << name << " cannot be opened" << endl;
        return 0;
    }
    string                temp;
    std::vector< string > ans;
    while ( getline( ifs, temp ) )
    {
        bool flag = true;

        if ( ( ans.size( ) - 1 >= 0 ) )
            if ( temp == ans [ ans.size( ) - 1 ] )
                flag = false;
        if ( flag )
            ans.push_back( temp );
    }
    for ( auto i : ans )
    {
        cout << i << endl;
    }
    return 0;
}
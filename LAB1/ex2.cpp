/*
 * This is an exercise of VE280 Lab 1, SU2022.
 */

#include <iostream>
using namespace std;

// EFFECTS: return true if the password is a valid one
auto isValidPassword( const char password [] ) -> bool
{
    // TODO: Implement this function.
    bool num      = false;
    bool alpha    = false;
    bool numalpha = false;
    for ( size_t i = 0;; i++ )
    {

        if ( i == 51 )
        {
            return ( ( num ) && ( alpha ) && ( numalpha ) );
        }

        if ( password [ i ] == '\0' )
        {
            return ( ( num ) && ( alpha ) && ( numalpha ) );
        }
        if ( ( password [ i ] < 33 )
             || ( password [ i ] > 126 ) )
        {
            throw ;
        }
        if ( password [ i ] >= '0' )
        {
            if ( password [ i ] <= '9' )
            {
                num = true;
                continue;
            }
        }
        if ( ( password [ i ] - 'A' )
                 * ( 'Z' - password [ i ] )
             >= 0 )
        {
            alpha = true;
        }
        else
        {
            if ( ( password [ i ] <= 'z' )
                 && ( password [ i ] >= 'a' ) )
            {
                alpha = true;
            }
            else
            {
                numalpha = true;
            }
        }
    }
}

auto main( ) -> int
{
    char password [ 51 ] = { };
    cin >> password;
    cout << isValidPassword( password ) << endl;
    return 0;
}

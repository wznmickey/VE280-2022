#include <cstdlib>
#include <iostream>
#include <string>

const std::string help_message( "Hey, I love Integers." );
const std::string add_message( "This is add operation." );
const std::string
    small_message( "This is small operation." );
const std::string no_op_message( "No work to do!" );

auto min( const int &a, const int &b ) -> int
{
    if ( a > b )
    {
        return b;
    }
    return a;
}

auto main( int argc, char *argv [] ) -> int
{
    // TODO write your code here
    bool message = false;
    bool help    = false;
    bool sum     = false;
    bool small   = false;
    int  toAdd   = 0;
    for ( int i = 0; i < argc; i++ )
    {
        std::string temp( argv [ i ] );
        if ( temp == "--add" )
        {
            sum = true;
        }
        if ( temp == "--help" )
        {
            help = true;
        }
        if ( temp == "--verbose" )
        {
            message = true;
        }
        if ( temp == "--small" )
        {
            small = true;
            i++;
            toAdd = std::atoi( argv [ i ] );
        }
    }
    int n = 0;
    std::cin >> n;
    // name conflict
    int summ = 0;
    int minn = 0;
    if ( n >= 1 )
    {
        std::cin >> summ;
        minn = summ;
    }
    for ( int i = 1; i < n; i++ )
    {
        int temp = 0;
        std::cin >> temp;
        summ = summ + temp;
        minn = min( minn, temp );
    }
    if ( help )
    {
        std::cout << help_message;
        return 0;
    }
    if ( sum )
    {
        if ( message )
        {
            std::cout << add_message << std::endl;
        }
        std::cout << summ << std::endl;
    }
    if ( small )
    {
        if ( message )
        {
            std::cout << small_message << std::endl;
        }
        std::cout << minn + toAdd << std::endl;
    }
    if ( ( ! sum ) && ( ! small ) )
    {
        std::cout << no_op_message << std::endl;
    }
    return 0;
}
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
const int MAX_INPUT = 10000000;
const int RANGE_MIN = 1;
const int RANGE_MAX = 4;
const int MAX_N     = 850;

/*
std::array can not be used.
So here is a struct with `I` that:
struct
{
    x=(I)(I+1)(I+2)/6;
    left = struct
    {
        x=(I-1)(I-1+1)(I-1+2)/6;
        left = struct
        {
            x=(I-2)(I-2+1)(I-2+2)/6;
            ...

            struct
            {
                x=1;
            }
        }
    }
}
*/
template < int I > struct Tetrahedral
{
private:
    Tetrahedral< I - 1 > left;
    static const int x = ( I ) * ( I + 1 ) * ( I + 2 ) / 6;

public:
    constexpr auto operator[]( int const &i ) const -> int
    {
        if ( i == I )
        {
            return x;
        }
        return left [ i ];
    }
};
template <> struct Tetrahedral< 1 >
{
private:
    static const int x = ( 1 ) * ( 1 + 1 ) * ( 1 + 2 ) / 6;

public:
    constexpr auto operator[]( int const & /*i*/ ) const
        -> int
    {
        return x;
    }
};

// trans int to string
auto get_string( int &x ) -> string
{
    
    auto st = to_string( x );
    // NO sstream allowed.
    // stringstream str;
    // str << x;
    // string st;
    // str >> st;
    return st;
}

// check if `x` is in tetrahedral.
// use binary search.
auto in_tetrahedral( int &x ) -> bool
{
    Tetrahedral< MAX_N > tetrahedral { };
    int                  left  = 0;
    int                  right = MAX_N;
    while ( left <= right )
    {
        int mid = left + ( right - left ) / 2;
        if ( tetrahedral [ mid ] == x )
        {
            return true;
        }
        if ( x < tetrahedral [ mid ] )
        {
            right = mid - 1;
        }
        if ( x > tetrahedral [ mid ] )
        {
            left = mid + 1;
        }
    }
    return false;
}

// Print print_prompt.
void print_prompt( )
{
    std::cout
        << "Please enter the integer and the test number: ";
}

const auto check_tetrahedral = []( int x )
{
    return in_tetrahedral( x );
};
const auto check_palindrome = []( int x )
{
    auto st = get_string( x );
    for ( size_t i = 0; i < st.size( ); i++ )
    {
        if ( st [ i ] != st [ st.size( ) - i - 1 ] )
        {
            return false;
        }
    }
    return true;
};
const auto check_self_dividing = []( int x )
{
    auto st = get_string( x );
    for ( auto i : st )
    {
        if ( i == '0' )
        {
            return false;
        }
        if ( x % ( i - '0' ) != 0 )
        {
            return false;
        }
    }
    return true;
};
const auto check_boring = []( int x )
{
    int prime = 2;
    while ( x > 1 )
    {
        while ( x % prime == 0 )
        {
            x /= prime;
        }
        prime++;
        if ( prime > 6 )
        {
            return false;
        }
    }
    return true;
};

// 0 is nullptr because input start from 1.
bool ( *const check [] )( int )
    = { nullptr,
        check_tetrahedral,
        check_palindrome,
        check_self_dividing,
        check_boring };

// x is the first input and y is the second input.
// Check whether it follow input rules.
auto check_input( int &x, int &y ) -> bool
{
    return ( x > 0 ) && ( x <= MAX_INPUT )
           && ( y >= RANGE_MIN ) && ( y <= RANGE_MAX );
}

// main function of project 1
auto main( ) -> int
{
    int x = 0;
    int y = 0;
    while ( true )
    {
        print_prompt( );
        cin >> x >> y;
        // cout<<x<<" "<<y<<endl;
        if ( check_input( x, y ) )
        {
            break;
        }
    }
    if ( check [ y ]( x ) )
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}
#include "ex2.h"

auto fold(
    int count,
    int arr [],
    int ( *fn )( int, int ),
    int initial ) -> int
{
    // EFFECTS: returns the result of the fold function
    for ( int i = 0; i < count; i++ )
    {
        initial = fn( arr [ i ], initial );
    }
    return initial;
}

auto fn_add( int a, int b ) -> int
{

    return a + b;
}

auto fn_count_odd( int a, int n ) -> int
{

    if ( a % 2 == 0 )
    {
        return n;
    }
    return n + 1;
}

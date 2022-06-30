#include "recursive.h"
list_t exclude( list_t lElements, list_t lIndices );
// REQUIRES: values in lIndices are nonnegative and in
// increasing order EFFECTS: returns a list with all the
// elements of lElements (in the
//          same order) whose indices do not appear in
//          lIndices Note: indices start from 0
//
// Example:
// select([1, 2, 3, 4], [0, 3]) returns [2, 3]
// select([1, 2, 3, 4], []) returns [1, 2, 3, 4]

static auto reverse( list_t list, list_t before ) -> list_t
{
    if ( list_isEmpty( list ) )
    {
        return before;
    }
    else
    {
        auto  it   = list_first( list );
        auto *rest = list_rest( list );
        before     = list_make( it, before );
        return reverse( rest, before );
    }
}

list_t exclude( list_t lElements, list_t lIndices )
{
    int   i   = 0;
    auto *ans = list_make( );
    if ( list_isEmpty( lElements ) )
        return ans;
    if ( list_isEmpty( lIndices ) )
        return lElements;
    auto it = list_first( lElements );
    if ( ! list_isEmpty( lElements ) )
        lElements = list_rest( lElements );
    auto com = list_first( lIndices );
    if ( ( ! list_isEmpty( lIndices ) ) )
        lIndices = list_rest( lIndices );
    while ( ( ! list_isEmpty( lIndices ) )
            && ( ! list_isEmpty( lElements ) ) )
    {
        if ( i == com )
        {
            i++;
            com       = list_first( lIndices );
            lIndices  = list_rest( lIndices );
            it        = list_first( lElements );
            lElements = list_rest( lElements );
            continue;
        }
        if ( i < com )
        {
            ans = list_make( it, ans );
            i++;
            it        = list_first( lElements );
            lElements = list_rest( lElements );
            continue;
        }
        if ( i > com )
        {
            ans = list_make( it, ans );
            i++;
            com       = list_first( lIndices );
            lIndices  = list_rest( lIndices );
            it        = list_first( lElements );
            lElements = list_rest( lElements );
            continue;
        }
    }
    while ( ! list_isEmpty( lElements ) )
    {
        if ( i == com )
        {
            i++;

            it        = list_first( lElements );
            lElements = list_rest( lElements );
            continue;
        }
        if ( i < com )
        {
            ans = list_make( it, ans );
            i++;
            it        = list_first( lElements );
            lElements = list_rest( lElements );
            continue;
        }
        if ( i > com )
        {
            ans = list_make( it, ans );
            i++;
            it        = list_first( lElements );
            lElements = list_rest( lElements );
            continue;
        }
    }

    if ( i != com )
    {
        ans = list_make( it, ans );
    }

    return reverse( ans, list_make( ) );
}

// int main( )
// {
//     list_t x = list_make( );
//     x        = list_make( 5, x );
//     x        = list_make( 4, x );
//     x        = list_make( 3, x );
//     x        = list_make( 2, x );
//     x        = list_make( 1, x );
//     x        = list_make( 0, x );
//     list_print( x );
//     list_t y = list_make( );
//     y        = list_make( 3, y );
//     // y        = list_make( 1, y );
//     // // y=list_make(2,x);
//     // y = list_make( 0, y );
//     list_print( y );
//     auto z = exclude( x, y );
//     list_print( z );
//     return 0;
// }
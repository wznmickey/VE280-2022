#include "recursive.h"
#include <cassert>

list_t intersection( list_t list1, list_t list2 );

bool compare( list_t list1, list_t list2 )
{
    while ( ( ! list_isEmpty( list1 ) )
            && ( ! list_isEmpty( list2 ) ) )
    {
        auto it1 = list_first( list1 );
        auto it2 = list_first( list2 );
        if ( it1 != it2 )
        {
            return false;
        }
        list1 = list_rest( list1 );
        list2 = list_rest( list2 );
    }
    if ( ( ( ! list_isEmpty( list1 ) )
           && ( list_isEmpty( list2 ) ) )
         || ( ( ! list_isEmpty( list2 ) )
              && ( list_isEmpty( list1 ) ) ) )
        return false;
    return true;
}

int main( )
{
    // first test case

    list_t x    = list_make( );
    list_t y    = list_make( );
    list_t z    = intersection( x, y );
    list_t test = list_make( );
    // boundary
    assert( compare( test, z ) == true );

    x    = list_make( 5, x );
    x    = list_make( 4, x );
    x    = list_make( 3, x );
    x    = list_make( 2, x );
    x    = list_make( 1, x );
    x    = list_make( 0, x );
    y    = list_make( 6, y );
    z    = intersection( x, y );
    test = list_make( );
    test = list_make( 6, test );
    test = list_make( 5, test );
    test = list_make( 4, test );
    test = list_make( 3, test );
    test = list_make( 2, test );
    test = list_make( 1, test );
    test = list_make( 0, test );
    // simple
    assert( compare( test, z ) == true );
    x = list_make( );
    y = list_make( );

    x    = list_make( 7, x );
    x    = list_make( 4, x );
    x    = list_make( 3, x );
    x    = list_make( 2, x );
    x    = list_make( 1, x );
    x    = list_make( 0, x );
    y    = list_make( 6, y );
    z    = intersection( x, y );
    test = list_make( );
    test = list_make( 7, test );
    test = list_make( 6, test );
    test = list_make( 4, test );
    test = list_make( 3, test );
    test = list_make( 2, test );
    test = list_make( 1, test );
    test = list_make( 0, test );
    // simple
    assert( compare( test, z ) == true );

    x = list_make( );
    y = list_make( );

    x = list_make( 7, x );
    x = list_make( 4, x );
    x = list_make( 3, x );
    x = list_make( 2, x );
    x = list_make( 1, x );
    y = list_make( 7, y );
    y = list_make( 6, y );
    y = list_make( 0, y );

    z    = intersection( x, y );
    test = list_make( );
    test = list_make( 7, test );
    test = list_make( 6, test );
    test = list_make( 4, test );
    test = list_make( 3, test );
    test = list_make( 2, test );
    test = list_make( 1, test );
    test = list_make( 0, test );
    // simple
    assert( compare( test, z ) == true );

    x = list_make( );
    y = list_make( );

    x    = list_make( 7, x );
    x    = list_make( 4, x );
    x    = list_make( 3, x );
    x    = list_make( 2, x );
    z    = intersection( x, y );
    test = list_make( );
    test = list_make( 7, test );
    test = list_make( 4, test );
    test = list_make( 3, test );
    test = list_make( 2, test );
     // boundary
    assert( compare( test, z ) == true );

    x = list_make( );
    y = list_make( );

    x    = list_make( 3, x );
    x    = list_make( 4, x );
    x    = list_make( 2, x );
    z    = intersection( y, x );
    test = list_make( );
    test = list_make( 4, test );
    test = list_make( 3, test );
    test = list_make( 2, test );
     // boundary
    assert( compare( test, z ) == true );


    x = list_make( );
    y = list_make( );

    x    = list_make( 3, x );
    x    = list_make( 4, x );
    x    = list_make( 2, x );
    z    = intersection( y, x );
    test = list_make( );
    test = list_make( 4, test );
    test = list_make( 3, test );
    test = list_make( 2, test );
     // non-sense
    assert( compare( test, z ) == true );


    x = list_make( );
    y = list_make( );

    x    = list_make( 3, x );
    x    = list_make( 3, x );
    x    = list_make( 2, x );
    z    = intersection( y, x );
    test = list_make( );
    test = list_make( 3, test );
    test = list_make( 2, test );
    // non-sense
    assert( compare( test, z ) == true );

    x = list_make( );
    y = list_make( );

    x    = list_make( 3, x );
    x    = list_make( 3, x );
    x    = list_make( 2, x );
    z    = intersection( y, x );
    test = list_make( );
    test = list_make( 3, test );
    test = list_make( 2, test );
     // non-sense
    assert( compare( test, z ) == true );


    x = list_make( );
    y = list_make( );

    x    = list_make( 3, x );
    x    = list_make( 3, x );
    x    = list_make( 3, x );
    z    = intersection( y, x );
    test = list_make( );
    test = list_make( 3, test );
     // non-sense
    assert( compare( test, z ) == true );

    return 0;
}
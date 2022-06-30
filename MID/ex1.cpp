#include "ex1.h"
#include "recursive.h"

auto dot( list_t v1, list_t v2 ) -> int
{
    // TODO: implement dot function
    if ( ( ! list_isEmpty( v1 ) )
         && ( ! list_isEmpty( v2 ) ) )
    {
        return list_first( v1 ) * list_first( v2 )
               + dot( list_rest( v1 ), list_rest( v2 ) );
    }
    return 0;
}
static auto reverse( list_t list, list_t before ) -> list_t
{
    if ( list_isEmpty( list ) )
    {
        return before;
    }

    auto  it   = list_first( list );
    auto *rest = list_rest( list );
    before     = list_make( it, before );
    return reverse( rest, before );
}
auto filter( list_t list, bool ( *fn )( int ) ) -> list_t
{
    // TODO: implement filter function
    auto *ans = list_make( );
    if ( list_isEmpty( list ) )
    {
        return ans;
    }
    auto  it   = list_first( list );
    auto *rest = list_rest( list );
    while ( true )
    {
        if ( fn( it ) )
        {
            ans = list_make( it, ans );
        }
        if ( ! list_isEmpty( rest ) )
        {
            it   = list_first( rest );
            rest = list_rest( rest );
        }
        else
        {

            return reverse( ans, list_make( ) );
        }
    }
}

auto is_palindrome_list( list_t list ) -> bool
{
    // TODO: implement is_palindrome_list function
    auto *re = reverse( list, list_make( ) );
    while ( ! list_isEmpty( list ) )
    {
        auto it1 = list_first( list );
        auto it2 = list_first( re );
        if ( it1 != it2 )
        {
            return false;
        }
        list = list_rest( list );
        re   = list_rest( re );
    }
    return true;
}

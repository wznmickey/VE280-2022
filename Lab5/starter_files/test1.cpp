#include <bits/stdc++.h>
#include "ex1.h"
#include "recursive.h"
using namespace std;
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
int main()
{
    list_t x=list_make();
    x=list_make(1, x);
    x=list_make(2,x);
    x=list_make(3, x);
    list_print(x);
    auto y =reverse(x,list_make( ) );
    list_print(y);
    auto z=
    return 0;
}

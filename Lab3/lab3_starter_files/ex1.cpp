#include <iostream>

using namespace std;

const int MAXSIZE = 10;

const int AIM = 280;

bool beChoiced [ MAXSIZE + 1 ]
    = { false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false };

auto canWin( int count, int arr [], int position ) -> bool
{
    if ( ( position >= count ) || ( position < 0 )
         || ( beChoiced [ position ] ) )
    {
        return false;
    }
    int num = arr [ position ];
    if ( num == AIM )
    {
        return true;
    }
    beChoiced [ position ] = true;
    bool flag
        = ( canWin( count, arr, position - num )
            || canWin( count, arr, position + num ) );
    if ( flag )
    {
        return true;
    }

    beChoiced [ position ] = false;
    return false;
}

auto main( ) -> int
{
    int count = 0;
    cin >> count;
    int arr [ MAXSIZE ];
    for ( int i = 0; i < count; ++i )
    {
        cin >> arr [ i ];
    }
    int position = 0;
    cin >> position;
    cout << canWin( count, arr, position );
}

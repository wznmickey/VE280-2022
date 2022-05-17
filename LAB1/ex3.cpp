/*
 * This is an exercise of VE280 Lab 1, SU2022.
 */

#include <iostream>
using namespace std;

// EFFECTS: return the trace of the Laplacian of the weight
// matrix.
auto traceLaplacian( int weight [][ 50 ], int size ) -> int
{
    // TODO: Implement this function.
    int D [ 50 ] = { 0 };
    for ( size_t i = 0; i < size; i++ )
    {
        for ( size_t j = 0; j < size; j++ )
        {
            // D[i][j]=0;
            D [ i ] += weight [ i ][ j ];
        }
    }
    int sum = 0;
    for ( size_t i = 0; i < size; i++ )

    {
        sum += D [ i ];
        sum -= weight [ i ][ i ];
    }
    return sum;
}

auto main( ) -> int
{
    int size                = 0;
    int trace               = 0;
    int weight [ 50 ][ 50 ] = { };
    cin >> size;
    for ( int i = 0; i < size; ++i )
    {
        for ( int j = 0; j < size; ++j )
        {
            cin >> weight [ i ][ j ];
        }
    }
    trace = traceLaplacian( weight, size );
    cout << trace << endl;
    return 0;
}

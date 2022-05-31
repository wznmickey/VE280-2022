#include <iostream>

using namespace std;

const int RANGE = 100000;

bool isPrime [ RANGE + 10 ];

// MODIFIES: isPrime[]
// EFFECTS: fill in isPrime[], true for prime, false
// otherwise
void generateIsPrime( )
{
    for ( int i = 0; i < RANGE + 1; i++ )

    {
        isPrime [ i ] = true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    int prime = 2;
    while ( prime < RANGE + 5 )
    {
        for ( int i = prime + prime; i <= RANGE;
              i += prime )
        {
            isPrime [ i ] = false;
        }
        prime++;
        while ( ( prime < RANGE + 5 )
                && ( ! isPrime [ prime ] ) )
        {
            prime++;
        }
    }
    // TODO: implement Eratosthenes Sieve Algorithm
}

auto main( ) -> int
{
    // TODO: generate lookup table
    generateIsPrime( );
    // TODO: read input and check if each num is prime
    int n = 0;
    cin >> n;
    bool flagFirst = false;
    for ( int i = 0; i < n; i++ )
    {
        int temp = 0;
        cin >> temp;
        if ( isPrime [ temp ] )
        {
            if ( flagFirst )
            {
                cout << " ";
            }
            cout << temp;
            flagFirst = true;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main( )
{
    string in;
    getline( cin, in );
    int    sum      = 0;
    string tempName = "";
    for ( auto i : in )
    {
        if ( ( ( i >= 'a' ) && ( i <= 'z' ) )
             || ( ( i >= 'A' ) && ( i <= 'Z' ) ) )
        {
            tempName += i;
        }
        else
        {
            if ( ! tempName.empty( ) )
            {
                cout << tempName << endl;
                tempName = "";
                sum++;
            }
        }
    }
    if ( ! tempName.empty( ) )
    {
        cout << tempName << endl;
        sum++;
    }
    cout << sum << endl;
    return 0;
}
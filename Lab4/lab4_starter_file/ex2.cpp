#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
struct Apple
{
    string      name;
    long double weight;
    long double price;
    long double avg;
    Apple( string n, long double w, long double p )
        : name( std::move( n ) )
        , weight( w )
        , price( p )
        , avg( price / weight )
    {
    }
    Apple(
        string      n,
        long double w,
        long double p,
        long double a )
        : name( std::move( n ) )
        , weight( w )
        , price( p )
        , avg( a )
    {
    }
};
auto main( int /*argc*/, char *argv [] ) -> int
{
    string  fileName = argv [ 1 ];
    fstream file( fileName );
    string  item;
    Apple minn( "no", -1, -1, -1 ); // It should not be less
                                   // than zero.
    while ( getline( file, item ) )
    {
        stringstream temp;
        temp << item;
        string      name;
        long double price  = NAN;
        long double weight = NAN;
        temp >> name >> price >> weight;
        Apple apple( name, weight, price );
        if ( (apple.avg < minn.avg) || (minn.avg <0))
        {
            minn = std::move( apple );
        }
    }
    cout <<fixed<<setprecision(2)<< minn.name << " " << minn.price << " "
         << minn.weight << endl;
    return 0;
}
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXNAMELENGTH
    = 20; // Just for convenience, use 20.

const int MAXSTUDENTNUM = 10;

struct Student
{
private:
    // TODO: complete struct
    int   score1 { };
    int   score2 { };
    int   score3 { };
    int   totalScore { };
    int   index { };
    char *name { };

public:
    Student( ) = default;
    Student(
        int   x,
        int   y,
        int   z,
        char *namePointer,
        int   index )
        : score1( x )
        , score2( y )
        , score3( z )
        , totalScore( x + y + z )
        , index( index )
        , name( namePointer )
    {
    }
    void print( ) const
    {
        // for ( int i = 0; i < MAXNAMELENGTH; i++ )
        // {
        //     if ( ( *( name + i ) ) != '\0' )
        //     {
        //         cout << *( name + i );
        //     }
        // }
        cout << name;

        cout << " " << score1 << " " << score2 << " "
             << score3 << endl;
    }
    auto getName( ) -> char *
    {
        return name;
    }
    static auto compare( const void *p1, const void *p2 )
        -> int
    {
        auto *a = ( Student * ) p1;
        auto *b = ( Student * ) p2;
        if ( ( a->totalScore ) != ( b->totalScore ) )
        {
            return (
                ( b->totalScore ) - ( a->totalScore ) );
        }
        return ( ( a->index ) - ( b->index ) );

        // TODO: complete compare function for qsort()
    }
};

auto main( ) -> int
{
    auto *student = new Student [ MAXSTUDENTNUM ];
    // TODO: read input
    int n = 0;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        auto *tempC  = new char [ MAXNAMELENGTH ];
        int   cScore = 0;
        int   mScore = 0;
        int   eScore = 0;
        cin >> tempC >> cScore >> mScore >> eScore;
        student [ i ] = std::move(
            Student( cScore, mScore, eScore, tempC, i ) );
    }
    // TODO: sort array with qsort()
    qsort(
        student,
        n,
        sizeof( Student ),
        Student::compare );
    // TODO: print result
    for ( int i = 0; i < n; i++ )
    {
        student [ i ].print( );
        delete []( student [ i ].getName( ) );
    }
    delete [] student;
    return 0;
}
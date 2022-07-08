#include "course.h"
using namespace std;
int main( )
{
    Course *ve482 = create( "Upper Level Technical", "VE482" );
    ve482->updateTask( "Homework", 1, 9, 18 );
    ve482->updateTask( "Lab", 1, 9, 16 );
    ve482->updateTask( "Team Project", 1, 10, 6 );
    ve482->print( );
    ve482->updateTask( "Homework", 1, 9, 15 );
    ve482->print( );
    ve482->updateTask( "Lab", 1, 9, 15 );
    ve482->updateTask( "Homework", 1, 9, 15 ); // do nothing
    ve482->print( );
    delete ve482;
}
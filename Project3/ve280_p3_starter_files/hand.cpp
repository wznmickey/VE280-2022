#include "hand.h"
Hand::Hand( )
{
    curValue.count = 0;
    curValue.soft  = false;
}
void Hand::discardAll( )
{
    Hand( );
    return;
}
void Hand::addCard( Card c )
{
    auto temp = c.spot;
    if ( temp <= 8 )
    {
        curValue.count += ( temp + 2 );
        if ( ( curValue.count > 21 ) && curValue.soft )
        {
            curValue.count -= 10;
            curValue.soft = false;
        }
    }
    else if ( temp <= 11 )
    {
        curValue.count += ( 10 );
        if ( ( curValue.count > 21 ) && curValue.soft )
        {
            curValue.count -= 10;
            curValue.soft = false;
        }
    }
    else
    {
        if ( curValue.soft )
        {
            curValue.count -= 10;
        }
        curValue.count += 11;
        curValue.soft = true;
        if ( ( curValue.count > 21 ) )
        {
            curValue.count -= 10;
            curValue.soft = false;
        }
    }
    return;
}
auto Hand::handValue( ) const -> HandValue
{
    return curValue;
}
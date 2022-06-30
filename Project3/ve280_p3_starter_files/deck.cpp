#include "deck.h"
Deck::Deck( )
{
    for ( auto i = 0; i < 4; i++ )
    {
        for ( auto j = 0; j < 13; j++ )
        {
            deck [ i * 13 + j ].spot = Spot( j );
            deck [ i * 13 + j ].suit = Suit( i );
        }
    }
    next = 0;
}
void Deck::reset( )
{
    Deck( );
}
void Deck::shuffle( int n )
{
    Card left [ DeckSize ];
    Card right [ DeckSize ];
    for ( auto i = 0; i < n; i++ )
    {
        left [ i ] = deck [ i ];
    }
    for ( auto i = n; i < DeckSize; i++ )
    {
        right [ i - n ] = deck [ i ];
    }
    auto l = 0;
    auto r = 0;
    for ( auto i = 0; i < DeckSize; )
    {
        if ( r < DeckSize - n )
        {
            deck [ i ] = right [ r ];
            i++;
            r++;
        }
        if ( l < n )
        {
            deck [ i ] = left [ l ];
            i++;
            l++;
        }
    }
    next = 0;
}
auto Deck::deal( ) -> Card
{
    auto temp = next;
    if ( next >= DeckSize )
    {
        throw DeckEmpty( );
    }
    next++;
    return deck [ temp ];
}
auto Deck::cardsLeft( ) -> int
{
    return ( DeckSize - next );
}
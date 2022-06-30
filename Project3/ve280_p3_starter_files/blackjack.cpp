#include "deck.h"
#include "player.h"
#include "rand.h"
#include <cstdlib>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
static const int ShufflesTimes = 7;
static const int MinimumBet    = 5;
void             cut( const int n, Deck &cards )
{
    // MODIFIES: cards
    // EFFECTS:  cut cards at given place
    cards.shuffle( n );
    cout << "cut at " << n << endl;
    return;
}
void shuffle( Deck &cards, Player &player )
{
    // MODIFIES: cards,player
    // EFFECTS:  shuffle cards, give info to cout, tell player shuffle
    cout << "Shuffling the deck\n";
    for ( auto i = 0; i < ShufflesTimes; i++ )
    {
        auto temp = get_cut( );
        cut( temp, cards );
    }
    player.shuffled( );
    return;
}
void compare( const Hand &dealerCard, const Hand &playerCard, int &bankroll, const int &wager )
{
    // MODIFIES: bankroll
    // EFFECTS:  calculate the bankroll, give info to cout
    if ( dealerCard.handValue( ).count > playerCard.handValue( ).count )
    {
        cout << "Dealer wins\n";
        bankroll -= wager;
    }
    if ( dealerCard.handValue( ).count < playerCard.handValue( ).count )
    {
        cout << "Player wins\n";
        bankroll += wager;
    }
    if ( dealerCard.handValue( ).count == playerCard.handValue( ).count )
    {
        cout << "Push\n";
    }
    return;
}

void first4Card( const Card &first, const Card &second, const Card &third, const Card &fourth, Player *player, Hand &playerCard, Hand &dealerCard )
{
    // MODIFIES: player,playerCard,dealerCard
    // EFFECTS:  give info to cout, expose first 3 cards to player, give first 4 cards to playerCard can dealerCard
    cout << "Player dealt " << SpotNames [ first.spot ] << " of " << SuitNames [ first.suit ] << endl;
    cout << "Dealer dealt " << SpotNames [ second.spot ] << " of " << SuitNames [ second.suit ] << endl;
    cout << "Player dealt " << SpotNames [ third.spot ] << " of " << SuitNames [ third.suit ] << endl;
    player->expose( first );
    player->expose( second );
    player->expose( third );
    playerCard.addCard( first );
    playerCard.addCard( third );
    dealerCard.addCard( second );
    dealerCard.addCard( fourth );
    return;
}
void get_player( const string &temp, Player **player )
{
    // MODIFIES: player
    // EFFECTS:  give pointer to player
    if ( temp == "simple" )
    {
        *player = get_Simple( );
    }
    else
    {
        *player = get_Counting( );
    }
    return;
}
void playerDraw( Player **player, const Card &second, Hand &playerCard, Deck &cards )
{
    // MODIFIES: player,playerCard,cards
    // EFFECTS:  let player have cards, give info to cout
    while ( true )
    {
        bool temp = ( *player )->draw( second, playerCard );
        if ( ! temp )
        {
            break;
        }
        Card next = cards.deal( );
        ( *player )->expose( next );
        playerCard.addCard( next );
        cout << "Player dealt " << SpotNames [ next.spot ] << " of " << SuitNames [ next.suit ] << endl;
    }
    cout << "Player's total is " << playerCard.handValue( ).count << endl;
    return;
}

void dealerDraw( Player **player, Hand &dealerCard, Deck &cards )
{
    // MODIFIES: player,dealerCard,cards
    // EFFECTS:  let dealer have cards, give info to cout, expose cards to player
    while ( true )
    {
        if ( dealerCard.handValue( ).count >= 17 )
        {
            break;
        }
        Card next = cards.deal( );
        ( *player )->expose( next );
        dealerCard.addCard( next );
        cout << "Dealer dealt " << SpotNames [ next.spot ] << " of " << SuitNames [ next.suit ] << endl;
    }
    cout << "Dealer's total is " << dealerCard.handValue( ).count << endl;
    return;
}
auto playerCheck( Player **player, const Card &second, Hand &playerCard, Deck &cards, int &bankroll, const int &wager, const Card &fourth ) -> bool
{
    // MODIFIES: player,bankroll,cards,playerCard
    // EFFECTS:  let player have cards, count bankroll, give info to cout
    if ( playerCard.handValue( ).count == 21 )
    {
        bankroll += ( 3 * wager / 2 );
        cout << "Player dealt natural 21\n";
        return true;
    }
    playerDraw( player, second, playerCard, cards );
    if ( playerCard.handValue( ).count > 21 )
    {
        cout << "Player busts\n";
        bankroll -= wager;
        return true;
    }
    cout << "Dealer's hole card is " << SpotNames [ fourth.spot ] << " of " << SuitNames [ fourth.suit ] << endl;
    ( *player )->expose( fourth );
    return false;
}
auto dealerCheck( Player **player, Deck &cards, int &bankroll, const int &wager, Hand &dealerCard ) -> bool
{
    // MODIFIES: player,bankroll,cards,dealerCard
    // EFFECTS:  let dealer have cards, expose cards to player, count bankroll, give info to cout
    dealerDraw( player, dealerCard, cards );
    if ( dealerCard.handValue( ).count > 21 )
    {
        cout << "Dealer busts\n";
        bankroll += wager;
        return true;
    }
    return false;
}
auto main( int /*argc*/, const char *argv [] ) -> int
{
    // EFFECTS: simulate the game
    int     bankroll = 0;
    int     hands    = 0;
    Player *player   = nullptr;
    bankroll         = atoi( argv [ 1 ] );
    hands            = atoi( argv [ 2 ] );
    get_player( argv [ 3 ], &player );
    auto cards = Deck( );
    shuffle( cards, *player );
    auto thisHand = 0; // Must define before `for`
    for ( ; ( thisHand + 1 <= hands ) && ( bankroll >= MinimumBet ); )
    {
        thisHand++;
        auto playerCard = Hand( );
        auto dealerCard = Hand( );
        cout << "Hand " << thisHand << " bankroll " << bankroll << endl;
        if ( cards.cardsLeft( ) < 20 )
        {
            shuffle( cards, *player );
        }
        auto wager = player->bet( bankroll, MinimumBet );
        cout << "Player bets " << wager << endl;
        Card first  = cards.deal( );
        Card second = cards.deal( );
        Card third  = cards.deal( );
        Card fourth = cards.deal( );
        first4Card( first, second, third, fourth, player, playerCard, dealerCard );
        if ( playerCheck( &player, second, playerCard, cards, bankroll, wager, fourth ) )
        {
            continue;
        }
        if ( dealerCheck( &player, cards, bankroll, wager, dealerCard ) )
        {
            continue;
        }
        compare( dealerCard, playerCard, bankroll, wager );
        if ( bankroll >= MinimumBet )
        {
            continue;
        }
        break;
    }
    cout << "Player has " << bankroll << " after " << thisHand << " hands\n";
    return 0;
}
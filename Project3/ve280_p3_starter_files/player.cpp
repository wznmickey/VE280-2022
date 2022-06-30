#include "player.h"

class SPlayer : public Player
{
private:
    static auto doHard( const Card &dealer, const Hand &player ) -> bool
    {
        if ( player.handValue( ).count <= 11 )
        {
            return true;
        }
        if ( player.handValue( ).count >= 17 )
        {
            return false;
        }
        if ( player.handValue( ).count == 12 )
        {
            return ! ( ( dealer.spot >= FOUR ) && ( dealer.spot <= SIX ) );
        }
        if ( ( dealer.spot >= TWO ) && ( dealer.spot <= SIX ) )
        {
            return false;
        }
        return true;
    }

    static auto doSoft( const Card &dealer, const Hand &player ) -> bool
    {
        if ( player.handValue( ).count <= 17 )
        {
            return true;
        }
        if ( player.handValue( ).count >= 19 )
        {
            return false;
        }
        if ( ( dealer.spot == TWO ) || ( dealer.spot == SEVEN ) || ( dealer.spot == EIGHT ) )
        {
            return false;
        }
        return true;
    }

public:
    auto bet( unsigned int /*bankroll*/, unsigned int minimum ) -> int override
    {
        return static_cast< int >( minimum );
    }
    void expose( Card /*c*/ ) override
    {
        return;
    }
    void shuffled( ) override
    {
        return;
    }
    auto draw( Card dealer, const Hand &player ) -> bool override
    {
        if ( player.handValue( ).soft )
        {
            return doSoft( dealer, player );
        }

        return doHard( dealer, player );
    }
};
class CPlayer : public SPlayer
{
private:
    int count { 0 };

public:
    auto bet( unsigned int bankroll, unsigned int minimum ) -> int override
    {
        if ( ( count >= 2 ) && ( bankroll >= 2 * minimum ) )
        {
            return 2 * static_cast< int >( minimum );
        }
        return static_cast< int >( minimum );
    }
    void expose( Card c ) override
    {
        if ( c.spot >= TEN )
        {
            count--;
        }
        if ( c.spot <= SIX )
        {
            count++;
        }
        return;
    }
    void shuffled( ) override
    {
        count = 0;
    }
};

static SPlayer sPlayer;
static CPlayer cPlayer;
extern auto    get_Simple( ) -> Player *
{
    return &sPlayer;
}
extern auto get_Counting( ) -> Player *
{
    return &cPlayer;
}

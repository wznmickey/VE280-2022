#include "deck.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    auto d = Deck();
    cout<<d.cardsLeft()<<endl;
    d.deal();
    d.deal();
    d.shuffle(1);
}
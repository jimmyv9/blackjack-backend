/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */

#include <iostream>
#include "vector"
#include "hand.h"
#include "player.h"
#include "card.h"

#ifndef BLACKJACK_DECK_H

using namespace std;

class Deck : public Hand {
    public:
        Deck();
        ~Deck();
        void build();
        void shuffle();
        void deals(Hand& hand, int &top);
        void cardsInDeck();
};


#endif //BLACKJACK_DECK_H

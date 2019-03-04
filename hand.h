/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */


#include <iostream>
#include <vector>
#include "card.h"

#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H

using namespace std;

class Hand {
    public:
        Hand();
        ~Hand();
        void clear(); //clears the hand
        void add(Card* card); //adds a card to the hand
        int getTotal() const; //adds the value of all cards in the hand
        vector<Card*> getCards() const;
    protected:
        vector<Card*> allCards;
};


#endif //BLACKJACK_HAND_H

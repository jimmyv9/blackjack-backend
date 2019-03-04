/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H
#include <iostream>
#include <vector>
#include "hand.h"

using namespace std;

class Player : public Hand {
    public:
        Player();
        ~Player();
        virtual void printHand() const;
        virtual bool hits();
        void reset();
        void setWinner(bool b);
        void setCash(int val);
        void setName(string n);
        int getCash() const;
        string getName() const;
        bool isBusted();
    protected:
        string name;
        int cash;
        bool winner;
        bool busted;
};
#endif //BLACKJACK_PLAYER_H


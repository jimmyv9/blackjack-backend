/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */


#ifndef BLACKJACK_HUMAN_H
#define BLACKJACK_HUMAN_H

#include "player.h"
#include "hand.h"

class Human : public Player {
    public:
        Human();
        ~Human();
        int getBet() const;
        int setBet(int b);
        bool busts();
        bool hits();
    private:
        int bet;
};


#endif //BLACKJACK_HUMAN_H

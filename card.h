/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */

#include <iostream>

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H
using namespace std;

enum Rank {Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
const Rank START_RANK = Ace;
const Rank END_RANK = King;
enum Suit{Spades=1, Hearts, Clubs, Diamonds};
const Suit START_SUIT = Spades;
const Suit END_SUIT = Diamonds;

class Card {
    public:
        Card(Rank r, Suit s);
        ~Card();
        friend ostream &operator <<(ostream& os, const Card* c);
        int getValue() const;
        Rank setRank(Rank r);
        Suit setSuit(Suit s);
        bool faceUp() const;
        void flip();
    private:
        Rank rank; //card has a value determined by enum Rank
        Suit suit; //card a suit determined by enum Suit
        bool up; //determines whether card is face up
};

#endif //BLACKJACK_CARD_H

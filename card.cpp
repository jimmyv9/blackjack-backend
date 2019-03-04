/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */


#include "card.h"
#include <iostream>

using namespace std;

Card::Card(Rank r, Suit s) {
    setRank(r);
    setSuit(s);
    up = false;
}


Card::~Card() {

}

ostream &operator <<(ostream& os, const Card* c) {
    if (c->rank == 1) {os << 'A';}
    else if (c->rank == 11) {os << 'J';}
    else if (c->rank == 12) {os << 'Q';}
    else if (c->rank == 13) {os << 'K';}
    else {os << c->rank;}

    if (c->suit == 1) {os << 'S';}
    else if (c->suit == 2) {os << 'H';}
    else if (c->suit == 3) {os << 'C';}
    else if (c->suit == 4) {os << 'D';}

    return os;
}

int Card::getValue() const {
    int value = 0;
    if (rank == 1) {value = 1;}
    if (rank >= 10) {value = 10;}
    if (rank < 10) {value = rank;}
    return value;
}

Rank Card::setRank(Rank r) {
    rank = r;
    return rank;
}

Suit Card::setSuit(Suit s) {
    suit = s;
    return suit;
}

//tests whether card is face up
bool Card::faceUp() const{
    if (up) {return true;}
    else {return false;}
}

void Card::flip() {
    if (!faceUp()) {up = true;}
    else {up = false;}
}





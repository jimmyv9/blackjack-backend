/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */


#include "hand.h"
#include "deck.h"
#include <iostream>

using namespace std;

Hand::Hand() {

}

Hand::~Hand() {

}

void Hand::clear() {
    allCards.clear();
}

void Hand::add(Card* card) {
    allCards.push_back(card);
}

int Hand::getTotal() const {
    int total = 0;
    int cardVal;
    for (int i = 0; i <= allCards.size() - 1; i++) {
        cardVal = allCards[i]->getValue();
        //dealing with Ace
        if (cardVal == 1) {
            if (total < 11) {
                 cardVal = 11;
            }
        }
        total += cardVal;
    }
    return total;
}

vector<Card*> Hand::getCards() const {
    return allCards;
}
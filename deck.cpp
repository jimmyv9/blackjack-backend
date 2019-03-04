/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */

#include <algorithm>
#include "deck.h"
#include "card.h"
#include "vector"
#include <random>

using namespace std;

Deck::Deck() {
    build();
}

//deletes the card pointers one by one that were created by the deck
Deck::~Deck() {
    for (int i = 0; i < allCards.size() - 1; i++) {
        delete allCards[i];
    }
}

void Deck::build() {
    for (int s = START_SUIT; s <= END_SUIT; s++) {
        for (int r = START_RANK; r <= END_RANK; r++) {
            Card* card;
            Rank rank = static_cast<Rank>(r); //converts value of r into a Rank-type and sets rank equal to it
            Suit suit = static_cast<Suit>(s); //converts value of s into a Suit-type and sets suit equal to it
            card = new Card(rank, suit);
            allCards.push_back(card);
        }
    }
}

void Deck::shuffle() {
    mt19937 r{random_device{}()};
    ::shuffle(&allCards[0], &allCards[52], r);
}

//deals card (which is at specific position in the deck) to a player
void Deck::deals(Hand &hand, int &top) {
    allCards[top]->flip();
    hand.add(allCards[top]);
    top++; //update top card after it is drawn
}

//which cards are still in the deck? (testing purposes only)
void Deck::cardsInDeck() {
    for (int i = 0; i < allCards.size(); i++) {
        cout << allCards[i] << endl;
    }
}
/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */


#include "player.h"

Player::Player() {
    setName("Dealer");
    setCash(0); //dealer has no money, by the end of the game, we take into consideration how much he has lost/won
    busted = false; //no player is initially busted
    winner = false;
}

Player::~Player() {

}

void Player::reset() {
    busted = false;
}

//printHand function that will print human and player's hands (not const because flips card)
void Player::printHand() const{
    cout << name << "'s current hand is: ";
    for(int i = 0; i <= allCards.size() - 1; i++) {
        if (allCards[i]->faceUp()) {
            cout << "[" << allCards[i] << "] ";
        }
        else {cout << "[??]";}
    }
    cout << "(" << getTotal() << " points)";
}

bool Player::hits() {
    if (!isBusted()) {
        if (getTotal() > 16) {
            cout << endl << name << " chooses to stay." << endl;
            return false;
        }
        else {
            cout << name << " chooses to draw." << endl;
            return true;
        }
    }
    else {
        cout << "Dealer busts!" << endl;
        return false;
    }
}

void Player::setWinner(bool b) {
    winner = b;
}

void Player::setCash(int val) {
    cash = val;
}

void Player::setName(string n) {
    name = n;
}

int Player::getCash() const {
    return cash;
}

string Player::getName() const{
    return name;
}

//used to bust player
bool Player::isBusted() {
    if(getTotal() > 21) { // busts user if above 21
        busted = true;
    }
    return busted; //returns whether user is busted or not
}
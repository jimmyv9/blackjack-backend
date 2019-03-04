/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 */


#include "human.h"

Human::Human(){
    string n;
    cout << "What is your preferred name?" << endl;
    cin >> n;
    setName(n); //sets name of human player

    //setting cash
    int c;
    cout << "How much money you have out of pocket?" << endl;
    cin >> c;
    while (cin.fail()) {
        cout << "Type in a whole number, please." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> c;
    }
    while (c < 25 || c > 1000) {
        cout << "In Jimmy's Blackjack, minimum buy-in is 25 dollars. Maximum buy-in is 1000 dollars." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> c;
    }
    setCash(c);
}
Human::~Human(){

}

//message when human busts
bool Human::busts() {
    if(getTotal() > 21) {
        busted = true;
        cout << endl << name << " is busted!" << endl;
    }
    return busted;
}

int Human::getBet() const {
    return bet;
}

int Human::setBet(int b) {
    bet = b;
}

//interface for user input, whether it wants to hit (draw) another card or not
bool Human::hits() {
    if (!busts()) {
        string wannaHit;
        cout << endl << "Would you like to draw another card? (Y/N) ";
        cin >> wannaHit;
        while (wannaHit != "Y" && wannaHit != "N") {
            cin >> wannaHit;
            cout << "Answer Y or N." << endl;
        }
        if (wannaHit == "Y") {
            cout << name << " chooses to draw." << endl;
            return true;
        }
        else if (wannaHit == "N") {
            cout << name << " chooses to stay." << endl;
            return false;
        }
    }
    else {return false;}

}
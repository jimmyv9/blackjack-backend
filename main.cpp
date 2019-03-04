/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 1
 *
 * EXTRA CREDIT: CARDS ARE POINTERS
 *             : MORE THAN 2 HUMAN PLAYERS
 *             : GAMES ONLY END WHEN ALL HUMANS HAVE LEFT THE TABLE
 */

#include <iostream>

#include <iostream>
#include <ctime>
#include "player.h"
#include "card.h"
#include "hand.h"
#include "deck.h"
#include "human.h"
using namespace std;

void mainMenu();
void wannaDraw(Player &p, Deck &d1, int &top);
int getWinnerPos(vector<Human> table, Player dealer);
vector<Human> gameSetup();
vector<int> recordPos(vector<Human> table);
void deletePlayers(vector<Human>&table, vector<int>&pos);

int main() {
    //srand(time(NULL)); //seeds time for random events (uncomment for precision)

    mainMenu();
    vector<Human> table = gameSetup();
    Player dealer;

    //loop for rounds of Blackjack based on if there are players left at the table
    while (table.size() != 0) {
        Deck deck;
        deck.shuffle();
        int top = 0; //indicates that the top card of the deck is at position 0

        //round of betting for everyone
        cout << "Time for everyone to place their bet!" << endl
             << "---------------------------------" << endl;
        int maxBet = 0; // recording max bet made by someone at the table, as people cannot bet below that
        for (int k = 0; k <= table.size() - 1; k++) {
            int bet = 0;
            cout << table[k].getName() << ", how much would you like to bet? ";
            cin >> bet;
            while (cin.fail()) {
                cout << "Type in a whole number, please." << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> bet;
            }
            //cannot bet less than 0 or more than cash available
            while (bet < maxBet || bet > table[k].getCash()) {
                //if player goes all-in
                if(bet == table[k].getCash()) {
                    cout << table[k].getName() << " just went all-in." << endl;
                    break;
                }
                cout << "You can't bet negative amounts or more than what you have." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> bet;
            }
            if (bet > maxBet) {maxBet = bet;} //redefine value of max bet
            table[k].setBet(bet); //define the bet variable within the Human class
        }
        cout << endl;

        for (int f = 0; f <= table.size() - 1; f++) {
            cout << table[f].getName() << " bets $" << table[f].getBet() << endl;
        }
        cout << endl;

        //deal initial card to everyone
        cout << "The initial starting cards are:" << endl
             << "---------------------------------" << endl;
        for(int i = 0; i <= table.size() - 1; i++) {
            deck.deals(table[i], top);
            table[i].printHand();
            cout << endl;
        }
        deck.deals(dealer, top);
        dealer.printHand();
        cout << endl << endl;

        //every human takes a turn
        for(int p = 0; p <= table.size() - 1; p++) {
            cout << table[p].getName() << "'s turn:" << endl
                 << "---------------------------------" << endl;
            deck.deals(table[p], top);
            table[p].printHand();
            wannaDraw(table[p], deck, top);
            cout << endl;
        }

        //dealer takes his/her turn
        cout << "Dealer's turn:" << endl
             << "---------------------------------" << endl;
        deck.deals(dealer, top);
        dealer.printHand();
        cout << endl;
        wannaDraw(dealer, deck, top);

        //setting a winner
        int winner = getWinnerPos(table, dealer);
        if (winner == -1) {dealer.setWinner(true);}
        else {table[winner].setWinner(true);}


        //consequences of turns
        cout << endl << "Let's see how it turned out:" << endl
             << "---------------------------------" << endl;
        for(int v = 0; v <= table.size() - 1; v++) {
            if (v == winner) {
                cout << table[v].getName() << " wins $" << table[v].getBet() << endl;
            }
            else {
                cout << table[v].getName() << " loses $" << table[v].getBet() << endl;
            }
        }

        //final count of cash
        cout << "The standings so far:" << endl
             << "---------------------------------" << endl;
        for (int w = 0; w <= table.size() - 1; w++) {
            if (w == winner) {table[w].setCash(table[w].getCash() + table[w].getBet());} //player gets money
            else if (winner == -1){dealer.setCash(dealer.getCash() + table[w].getBet());} //loops through getting all player's money
            else {table[w].setCash(table[w].getCash() - table[w].getBet());} //player loses money

            cout << table[w].getName() << " $" << table[w].getCash() << endl;
        }
        cout << endl; //A E S T H E T I C S

        //clearing hands for new round
        for (int t = 0; t <= table.size() - 1; t++) {
            table[t].clear();
            table[t].reset();
        }
        dealer.clear();
        dealer.reset();

        vector<int> pos = recordPos(table); //records the position of players to be deleted at the end of a round
        deletePlayers(table, pos); //asks if a human wants to leave the table. Once all humans leave, game ends.
    }

    //ending game message
    cout << "Thanks for playing :)" << endl;
    return 0;
}

//creates a main menu for the user to interact previous to the beginning of the game
void mainMenu() {
    cout << "Welcome to Jimmy's Blackjack Table!" << endl << endl;
    cout << "Enter 'p' whenever you are ready to play." << endl <<
            "Don't know how to play? Enter 'r' for rules." << endl;
    string a;
    cin >> a;

    //while loop to make sure var a is input properly
    while ((a != "r") && (a != "p")) {
        cout << "That is not a valid entry. Enter 'p' for playing."
                "Enter 'r' for rules." << endl << endl;
        cin >> a;
    }

    if (a == "r") {
        cout << "A card game where the objective is to score closest to 21 points." << endl <<
                "Sum your hand value. Where an Ace is worth 1 or 11, and a face card is 10." << endl <<
                "Make bets against other players to get rich!" << endl <<
                "Enter 'b' to go back to menu." << endl;
        string b;
        cin >> b;
        while (b != "b") {
            cout << "Not a valid entry. Enter 'b' to go back." << endl;
            cin >> b;
        }
        mainMenu();
    }
    else if (a == "p") {
        cout << endl << "Welcome to the table!" << endl;
    }
}

//decides whether a player wants to draw a card or not
void wannaDraw(Player &p, Deck &d1, int &top) {
    bool draw = true;
    while(draw) {
        draw = p.hits();
        if(draw) {d1.deals(p, top);}
        p.printHand();
    }
}

//sets up human players
vector<Human> gameSetup() {
    vector<Human> table; //initializes a list of human players
    int num;
    cout << "How many humans are joining this game?" << endl;
    cin >> num;

    //solution to how to fix wrongful non integer
    while (cin.fail()) {
        cout << "Type in a whole number, please." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> num;
    }
    while (num > 7 || num < 0) {
        cout << "The largest table available fits only 8 people (dealer included)." << endl;
        cin >> num;
    }

    //loop to create new players;
    for (int i = 1; i <= num; i++) {
        cout << "Player " << i << ":" << endl;
        Human h;
        table.push_back(h);
        cout << "----------------------------------------" << endl;
    }
    return table;
}

//records position of players who want to leave game
vector<int> recordPos(vector<Human> table) {
    vector<int> pos; //vector to be returned
    for(int j = 0; j <= table.size() - 1; j++) {
        string anotherRound;
        cout << table[j].getName() << " would you like to keep playing? (Y/N)" << endl;
        cin >> anotherRound;
        while (anotherRound != "Y" && anotherRound != "N") { //allow only for "Y" or "N" responses
            cout << "Please respond with a Y or N." << endl;
            cin >> anotherRound;
        }
        if (anotherRound == "N") {
            pos.push_back(j);
        }
    }
    return pos;
}

int getWinnerPos(vector<Human> table, Player dealer) {
    int maxPoints = 0;
    int winnerPos;
    for (int i = 0; i <= table.size() - 1; i++) {
        if (table[i].getTotal() > 21)
            continue;
        if (table[i].getTotal() > maxPoints) {
            maxPoints = table[i].getTotal();
            winnerPos = i;
        }
    }
    if (maxPoints > dealer.getTotal()) {return winnerPos;}
    else {return -1;}
}

//takes a vector<int> sorted by ascending numbers and another of Humans to be deleted
void deletePlayers(vector<Human>&table, vector<int>&pos) {
    //have to loop the vector of position in descending order in order not to change index of early items in table
    for(int i = pos.size() - 1; i >= 0; i--) {
        table.erase(table.begin() + pos[i]);
    }
}
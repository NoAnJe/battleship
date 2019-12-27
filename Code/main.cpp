#include "main.h"
#include "map.h"
#include "mapref.h"

using namespace std;

// Gamewide definitions
Map defense[2], offense[2];
int x, y, player;
bool noWinner;

// Pin Definitions
#define LAUNCH_BUTTON 0  // TODO : DEFINE BUTTON (BOTH PLAYERS RIGHT NEXT TO EACH OTHER)
#define PIN_X      0     // TODO : ORDER BUTTON ... XA, XB, YA, YB ... BUTTON
#define MIN_ANALOG   0  // TODO : MINIMUM SAFE ANALOG VOLTAGE


void getCoords() {
    // TODO
}

// TODO : CORRECT THE CONSTRUCTORS FOR MAP
void initialize() {

    // defense[0] = new Map::Map();
    // defense[1] = new Map::Map();
    // offense[0] = new Map::Map();
    // offense[1] = new Map::Map();
}

int readXY(int isY) {
    // TODO : Read the value of X
    while(analogRead(PIN_X + player + isY * 2) < MIN_ANALOG) {}

    int readVal = analogRead(PIN_X + player);

    // TODO : REPLACE 9 - 0 IN THE COMPARISONS WITH THE ACTUAL THRESHOLDS (E.G. 1008)
    //          HOWEVER, DON'T REPLACE THE RETURN VALUES
    if((readVal > 9)) {
        return 9;
    } else if ((readVal <= 9) && (readVal > 8)) {
        return 8;
    } else if ((readVal <= 8) && (readVal > 7)) {
        return 7;
    } else if ((readVal <= 7) && (readVal > 6)) {
        return 6;
    } else if ((readVal <= 6) && (readVal > 5)) {
        return 5;
    } else if ((readVal <= 5) && (readVal > 4)) {
        return 4;
    } else if ((readVal <= 4) && (readVal > 3)) {
        return 3;
    } else if ((readVal <= 3) && (readVal > 2)) {
        return 2;
    } else if ((readVal <= 2) && (readVal > 1)) {
        return 1;
    } else if ((readVal <= 1) && (readVal > 0)) {
        return 0;
    }
}

void getCoords() {

    x = readXY(0);
    y = readXY(1);
}

int getDir() {

    while(true) {

        int dir = readXY(0);
        if((dir >= 0) && (dir < 4)) {

            return dir;
        }
    }
}

void setShips() {

    int i;
    int start = 5;
    int end = 2;

    // Map 5, 4, 3, 3, 2
    while(end > 0) {
        for(i = start; i > end; i--) {

            // TODO :
            //      1) Select coordinate
            //      2) Flash coordinate
            //      3) Select direction (using buttons 1, 2, 3, 4)
            //      4) Flash location or RED if invalid

            bool shipPlaced = false;

            while(!shipPlaced) {
                getCoords();
                int dir = getDir();
                if(offense[player].checkShip(x, y, dir, i) == 0) {

                    shipPlaced = true;
                    while(!digitalRead(LAUNCH_BUTTON + player)) {
                        if() // TODO : Check for the coordinates being changed
                    } // TODO : While the button to finalize isn't pressed


                    if(shipPlaced) {
                        offense[player].mapShip(x, y, dir, i);
                        break;
                    }
                }
            }

        }
        start = 3;
        end--;
    }
}

void playRound() {
    // TODO : Play the round
    //      1) Set coordinates
    //      2) Flash on screen
    //      3) Confirm
    //      4) Fire missile
    //      5) Check whether or not it was a hit
    //      6) Update maps
}

void celebrate() {
    // TODO :
    //      1) Current player is the winner
}

int main() {

    while(true) {

        // Initialization Section
        initialize();

        player = 0;
        setShips(0);
        player = 1;
        setShips(1);

        noWinner = true;
        while(noWinner) {

            if(player) {
                player = 0;
            } else {
                player = 1;
            }

            playRound();
            if (!offense[player].shipsRemaining()) break;
        }

        celebrate();

        // Both players must press their launch button to restart the game
        while((!digitalRead(LAUNCH_BUTTON)) || (!digitalRead(LAUNCH_BUTTON + 1))) {} // TODO : READ FINALIZE BUTTON
    }

    return 0;
}
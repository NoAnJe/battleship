#include "mapref.h"
#include "map.h"

#define SIDE_LEN 10

using namespace std;

class Map {

    private:

    MapRef mapping [SIDE_LEN][SIDE_LEN];
    int numShipSpots;

    public:

    Map() {

        int i, j;
        for(i = 0; i < SIDE_LEN; i++) {
            for(j = 0; j < SIDE_LEN; j++) {

                mapping[i][j] = MapRef::SEA;
            }
        }

        numShipSpots = 0;

    }

    int checkShip(int x, int y, int dir, int len) {

        // Check that the coordinates are within the array and there is a valid length / direction
        if((x >= SIDE_LEN) || (x < 0) || (y >= SIDE_LEN) || (y < 0) ||
           (len < 1) || (len > 5) || (dir < 0) || dir > 3) {

            return 2;
        }

        // Check that the current box is open sea
        if(mapping[x][y] != MapRef::SEA) {
            return 1;
        }

        // (If another block exists) check the next box
        if(len > 1) {
            
            int res = 0;
            switch (dir) {
                case 0: // NORTH
                    res = checkShip(x-1, y, dir, len-1);
                    break;

                case 1: // EAST
                    res = checkShip(x, y+1, dir, len-1);
                    break;

                case 2: // SOUTH
                    res = checkShip(x+1, y, dir, len-1);
                    break;

                default: // WEST
                    res = checkShip(x, y-1, dir, len-1);
                    break;
            }

            if(res != 0) {
                return res;
            }
        }

        return 0;
    }

    void mapShip(int x, int y, int dir, int len) {
        
        mapping[x][y] = MapRef::SHIP;
        numShipSpots++;

        if(len > 1) {
            int res = 0;
            switch (dir) {
                case 0: // NORTH
                    mapShip(x-1, y, dir, len-1);
                    break;

                case 1: // EAST
                    mapShip(x, y+1, dir, len-1);
                    break;

                case 2: // SOUTH
                    mapShip(x+1, y, dir, len-1);
                    break;

                default: // WEST
                    mapShip(x, y-1, dir, len-1);
                    break;
            }
        }
        
    }

    MapRef checkHit(int x, int y) {

        if(mapping[x][y] == MapRef::SHIP) {

            mapping[x][y] = MapRef::HIT;
            return MapRef::HIT;
        }

        return MapRef::MISS;
    }

    bool shipsRemaining() {
        if(numShipSpots) return false;
        return true;
    }

};
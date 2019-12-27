#include "mapref.h"

using namespace std;

class Map {

    public:
    /**
     * Constructor that initializes the values to SEA
     */
    Map();

    private:
    ~Map();

    public:

    /**
     * Checks validity of a ship of length len
     * 
     * Starting at location (x,y), the program will check the validity
     * a ship of length len in the specified direction. The
     * directions are 0-3 (North through West), where North is row
     * 0 (x = 0) and West is column 0 (y = 0). A success code of 0,
     * 1, or 2 is returned - 0 if it was a success, 1 if it was too
     * short (ARRAY OUT OF BOUNDS), or 2 if there was another SHIP
     * in the way.
     * 
     * @param x x coordinate
     * @param y y coordinate
     * @param dir Direction (0-3) in which to expand the ship
     * @param len Length of the ship to build
     * 
     * @return Success or error code
     */
    int checkShip(int x, int y, int dir, int len);
    
    // TODO : MAP SHIP - NO ERROR CHECKING
    // UPDATE DESCRIPTION
    void mapShip(int x, int y, int dir, int len);

    /**
     * This is a function that checks for a hit.
     * 
     * Specifically, this function, using the selected coordinates,
     * will check whether or not this map contains a SHIP at the
     * location. If it does, then it will update to be a HIT, and
     * will return a HIT. Otherwise, it will return as a MISS.
     * 
     * @param x The x coordinate
     * @param y The y coordinate
     * 
     * @return MISS or HIT
     */
    MapRef checkHit(int x, int y);

    // TODO : UPDATE DESCRIPTION
    bool shipsRemaining();
};
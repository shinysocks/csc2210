/*
 * robot.h
 *      Author: Noah Dinan
 */

#ifndef ROBOT_H_
#define ROBOT_H_

class MapCell;
class Map;
#include <string>

// A robot which lives on a map at a particular x and y coordinate.
class Robot {
    public:
        Robot(Map *map, int startx, int starty);
        // display robot status in the form of "Robot at 6, 7 (1 gold)" to cout
        void displayStatus();
        // move robot in specified direction (e/w/s/n), returning true
        //   if was able to move in that direction
        // Warning: this method can get long - be sure to write private messages
        //   to break it up
        bool move(char direction);
        // move robot in a series of directions, returning true if was
        //   able to complete the list of directions
        bool move(std::string commands);
    private:
        int x;
        int y;
        int gold;
        Map *map;
        bool is_within_bounds(char);
        MapCell* cell_at(int, int);
        void process_token(char);
        bool has_pit(char);
};

#endif /* ROBOT_H_ */

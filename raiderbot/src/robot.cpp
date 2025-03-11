/*
 * robot.cpp
 *
 *      Author: [TODO]
 */

#include "robot.h"
#include <iostream>
using namespace std;

Robot::Robot(Map *map, int startx, int starty) {
    x = startx;
    y = starty;
    gold = 0;
}

void Robot::displayStatus() {
    cout << "Robot at " << x << ", " << y << " (" << gold << " gold)";
}

bool Robot::move(char direction) {
    return false;
}

bool Robot::move(string commands) {
    return false;
}



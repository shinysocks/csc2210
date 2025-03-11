/*
 * robot.cpp
 *
 *      Author: Noah Dinan
 */

#include "robot.h"
#include "cell.h"
#include "map.h"
#include <iostream>
using namespace std;

Robot::Robot(Map *map, int startx, int starty) {
    x = startx;
    y = starty;
    gold = 0;
    Robot::map = map;
    process_token(cell_at(x, y)->display());
    cell_at(x, y)->enter();
}

void Robot::displayStatus() {
    cout << "Robot at " << x << ", " << y << " (" << gold << " gold)";
}

bool Robot::move(char direction) {
    if (!is_within_bounds(direction)) return false;
    if (has_pit(direction)) return false;

    cell_at(x, y)->vacate();

    if (direction == 'n') y--;
    else if (direction == 's') y++;
    else if (direction == 'e') x++;
    else if (direction == 'w') x--;

    process_token(cell_at(x, y)->display());
    cell_at(x, y)->enter();
    return true;
}

bool Robot::move(string commands) {
    for (unsigned int i = 0; i < commands.length(); i++) {
        if (!move(tolower(commands[i]))) return false;
    }
    return true;
}

bool Robot::is_within_bounds(char direction) {
    switch (tolower(direction)) {
        case 'n':
            return (y - 1) >= 0;
        case 's':
            return (y + 1) < map->HEIGHT;
        case 'e':
            return (x + 1) < map->WIDTH;
        case 'w':
            return (x - 1) >= 0;
        default: // illegal move
            return false;
    }
}

MapCell* Robot::cell_at(int x, int y) {
    return map->cells[x][y];
}

void Robot::process_token(char token) {
    if (token == 'T') {
        gold--;
        if (gold < 0) {
            cout << "Robot now owes the bank " << abs(gold) << " pieces." << endl;
        }

    } else if (token == '*') gold++;
}

bool Robot::has_pit(char direction) {
    if (direction == 'n') return cell_at(x, y - 1)->hasPit();
    if (direction == 's') return cell_at(x, y + 1)->hasPit();
    if (direction == 'e') return cell_at(x + 1, y)->hasPit();
    if (direction == 'w') return cell_at(x - 1, y)->hasPit();
    return false;
}


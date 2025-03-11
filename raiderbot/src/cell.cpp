/*
 * cell.cpp
 * Author: Noah Dinan
 */

#include "cell.h"

MapCell::MapCell(int x, int y, char type) {
    xLocation = x;
    yLocation = y;
    token = type;
}

bool MapCell::hasPit() {
    return token == '#';
}

bool MapCell::hasThief() {
    return token == 'T';
}

bool MapCell::hasGold() {
    return token == '*';
}

void MapCell::removeGold() {
    token = ' ';
}

bool MapCell::occupied() {
    return token != ' ';
}

char MapCell::display() {
    return token;
}

void MapCell::enter() {
    token = 'R';
}

void MapCell::vacate() {
    token = ' ';
}




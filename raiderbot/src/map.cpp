/*
 * map.cpp
 *
 *      Author: Noah Dinan
 */

#include "map.h"
#include "cell.h"
#include <iostream>
using namespace std;

Map::Map() {}

void Map::load() {
    string line = "";
    getline(cin, line);

    for (int y = 0; y < HEIGHT; y++) {
        getline(cin, line);

        for (unsigned int x = 1; x < line.length() - 1; x++) {
            cells[x - 1][y] = new MapCell(x - 1, y, line.at(x));
        }
    }

    getline(cin, line);
}

void Map::write() {
    cout << "+--------------------+" << endl;
    for (int y = 0; y < HEIGHT; y++) {
        cout << "|";
        for (int x = 0; x < WIDTH; x++) {
            cout << cells[x][y]->display();
        }
        cout << "|";
        cout << endl;
    }
    cout << "+--------------------+" << endl;
}


#include "Board.h"
using namespace std;

const int BOARD_SIZE = 3;

Board::Board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cells[i][j] = ' ';
        }
    }
}

void Board::printBoard() {
    cout << "  1   2   3" << endl;

    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i + 1 << " "; 
        for (int j = 0; j < BOARD_SIZE - 1; j++) {
            cout << cells[i][j] << " | ";
        } cout << cells[i][BOARD_SIZE - 1] << endl;

        if (i < 2) cout << "  - + - + -" << endl;
    }
}

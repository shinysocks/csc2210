#include "iostream"

class Board {
    private:
        char cells[3][3];
        friend class TicTacToe;
    public:
        Board();
        void printBoard();
 };

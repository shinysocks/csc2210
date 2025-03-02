// TicTacToe.h
 #include "Game.h"
 #include "Board.h"

 class TicTacToe : public Game {
    private:
        Board board;
        char currentPlayer;
        bool checkVictory(char, char[3][3]);

    public:
        TicTacToe();
        void play() override;
 };

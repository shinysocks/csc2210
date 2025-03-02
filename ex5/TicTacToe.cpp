#include "TicTacToe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe() {
    board = Board();
    currentPlayer = 'O';
}

bool TicTacToe::checkVictory(char t, char b[3][3]) {
  for (int i = 0; i < 3; i++) {
    if ((b[i][0] == t && b[i][1] == t && b[i][2] == t)
      || (b[0][i] == t && b[1][i] == t && b[2][i] == t)) {
      return true;
    }
  }
  if ((b[0][0] == t && b[1][1] == t && b[2][2] == t)
    || (b[0][2] == t && b[1][1] == t && b[2][0] == t)) {
    return true;
  }
  return false;
}

void TicTacToe::play() {
  int rounds = 0;
  while (!checkVictory(currentPlayer, board.cells) && rounds < 9) {
    rounds++;
    currentPlayer = currentPlayer == 'O' ? 'X' : 'O';
    board.printBoard();
    cout << currentPlayer << "'s turn, enter coordinates (example: \"1 3\"): ";
    int x, y;
    cin >> x >> y;
    while (board.cells[y - 1][x - 1] != ' ') {
      cout << "Invalid input! Pick again: ";
      cin >> x >> y;
    }
    board.cells[y - 1][x - 1] = currentPlayer;
  }
  if (checkVictory(currentPlayer, board.cells)) {
    cout << "Victory for " << currentPlayer << endl;
  } else {
    cout << "Tie" << endl;
  }
}

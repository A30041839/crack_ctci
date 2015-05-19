#include "../ctci.h"

using namespace std;

enum class Piece {
  Empty,
  White,
  Black
};

Piece checkWinner(vector<vector<Piece> >& board) {
  int n = board.size();
  int row, col;
  //check rows
  for (row = 0; row < n; ++row) {
    if (board[row][0] != Piece::Empty) {
      for (col = 1; col < n; ++col) {
        if (board[row][col] != board[row][col - 1]) {
          break;
        }
      }
      if (col == n) {
        return board[row][0];
      }
    }
  }
  //check colums
  for (col = 0; col < n; ++col) {
    if (board[0][col] != Piece::Empty) {
      for (row = 1; row < n; ++row) {
        if (board[row][col] != board[row - 1][col]) {
          break;
        }
      }
      if (row == n) {
        return board[0][col];
      }
    }
  }
  //check diagnal
  if (board[0][0] != Piece::Empty) {
    for (row = 1; row < n; ++row) {
      if (board[row][row] != board[row - 1][row - 1]) {
        break;
      }
    }
    if (row == n) {
      return board[0][0];
    }
  }
  //check counter diagnal
  if (board[0][n - 1] != Piece::Empty) {
    for (row = 1; row < n; ++row) {
      if (board[row][n - 1 - row] != board[row - 1][n - row]) {
        break;
      }
    }
    if (row == n) {
      return board[0][n - 1];
    }
  }
  return Piece::Empty;
}

int main(){
  return 0;
}

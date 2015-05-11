#include "../ctci.h"

using namespace std;

const int GRID_SIZE = 8;

bool checkValid(vector<int>& rows, int row, int col){
  for (int i = 0; i < row; ++i){
    if (abs(i - row) == abs(rows[i] - col) or rows[i] == col){
      return false;
    }
  }
  return true;
}

void _eightQueens(vector<vector<char> >& grid, int row, vector<int>& rows, int& cnt){
  if (row == GRID_SIZE){
    cout << "the " << ++cnt << " solution:" << endl;
    print_matrix(grid);
    return;
  }
  for (int col = 0; col < GRID_SIZE; ++col){
    if (checkValid(rows, row, col)){
      rows[row] = col;
      grid[row][col] = 'x';
      _eightQueens(grid, row + 1, rows, cnt);
      grid[row][col] = '.';
    }
  }
}

void eightQueens(vector<vector<char> >& grid) {
  int cnt = 0;
  vector<int> rows(GRID_SIZE, 0);
  _eightQueens(grid, 0, rows, cnt);
}

int main(){
  vector<vector<char> > grid(8, vector<char>(8, '.'));
  eightQueens(grid);
  return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_grid(vector<vector<char> >& s){
  for (int i = 0; i < s.size(); ++i){
    for (int j = 0; j < s.size(); ++j){
      cout << s[i][j];
    }
    cout << endl;
  }
}

bool place(vector<int>& rows, int row, int col){
  for (int i = 0; i < row; ++i){
    if (abs(i - row) == abs(rows[i] - col)){
      return false;
    }
  }
  return true;
}

void eightQueens(vector<vector<char> >& grid, int row, vector<int>& rows, vector<int>& cols, int& cnt){
  if (row == 8){
    cout << "the " << cnt << " solution:" << endl;
    print_grid(grid);
    cnt++;
    return;
  }
  for (int col = 0; col < 8; ++col){
    if (cols[col] == 0){
      if (place(rows, row, col)){
        cols[col] = 1;
        rows[row] = col;
        grid[row][col] = 'x';
        eightQueens(grid, row + 1, rows, cols, cnt);
        cols[col] = 0;
        grid[row][col] = '.';
      }
    }
  }
}

int main(){
  vector<vector<char> > grid(8, vector<char>(8, '.'));
  vector<int> cols(8, 0);
  vector<int> rows(8, 0);
  int cnt = 1;
  eightQueens(grid, 0, rows, cols, cnt);
  return 0;
}

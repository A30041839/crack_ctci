#include <iostream>
#include <vector>

using namespace std;

char testWinner(vector<vector<char> >& grid){
  int i, j;
  for (i = 0; i < 3; ++i){
    bool f1, f2;
    f1 = f2 = true;
    for (j = 1; j < 3; ++j){
      if (grid[i][j] != grid[i][j - 1]){
        f1 = false;
      }
      if (grid[j][i] != grid[j - 1][i]){
        f2 = false;
      }
    }
    if (f1) return grid[i][0];
    if (f2) return grid[0][i];
  }
  if (grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2]) return grid[0][0];
  if (grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0]) return grid[0][2];
  return '#';
}

int main(){
  vector<vector<char> > grid(3, vector<char>(3, ' '));
  for(int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      grid[i][j] = (i == j ? 'x' : 'o');
    }
  }
  char res = testWinner(grid);
  if (res != '#'){
    cout << "winner is " << res << endl;
  }else{
    cout << "no one wins." << endl;
  }
}

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> point;

int numofpathRecursive(point& cur, point& end){
  if (cur.first == end.first || cur.second == end.second){
    return 1;
  }
  cur.first++;
  int c1 = numofpathRecursive(cur, end);
  cur.first--;
  cur.second++;
  int c2 = numofpathRecursive(cur, end);
  cur.second--;
  return c1 + c2;
}

int numofpathDP(int x){
  int len = x + 1;
  vector<vector<int> > dp(len, vector<int>(len, 1));
  for (int i = len - 2; i >= 0; --i){
    for (int j = len - 2; j >= 0; --j){
      dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    }
  }
  return dp[0][0];
  
}

bool findpath(vector<vector<char> >& grid, int curx, int cury){
  if (grid[curx][cury] == 'x'){
    return false;
  }
  grid[curx][cury] = '*'; 
  if (curx == grid.size() - 1 and cury == grid.size() - 1){
    return true;
  }
  if (cury < grid.size() - 1 and grid[curx][cury + 1] != 'x'){
    if (findpath(grid, curx, cury + 1)){
      return true;
    }
  }
  if (curx < grid.size() - 1 and grid[curx + 1][cury] != 'x'){
    if (findpath(grid, curx + 1, cury)){
      return true;
    }
  }
  //trace back
  grid[curx][cury] = '.';
  return false;

}


int main(){
  point start(0, 0);
  point finish(10, 10);
  //cout << numofpathRecursive(start, finish) << endl;
  //cout << numofpathDP(10) << endl;
  
  vector<vector<char> > grid(10, vector<char>(10, '.'));
  grid[3][4] = 'x';
  grid[2][7] = 'x';
  grid[8][6] = 'x';
  grid[4][5] = 'x';
  grid[7][9] = 'x';
  grid[7][8] = 'x';
  grid[6][6] = 'x';
  grid[8][9] = 'x';
  grid[5][4] = 'x';
  grid[8][8] = 'x';
  grid[0][2] = 'x';
  grid[1][4] = 'x';
  
  if (findpath(grid, 0, 0)){
    for (int i = 0; i < 10; ++i){
      for (int j = 0; j < 10; ++j){
        cout << grid[i][j] << " ";
      }
      cout << endl;
    }
  }else{
    cout << "no path available." << endl;
  }
  return 0;
}

#include "../ctci.h"

using namespace std;

void print_screen(vector<vector<char> >& s){
  for (int i = 0; i < s.size(); ++i){
    for (int j = 0; j < s.size(); ++j){
      cout << s[i][j] << " ";
    }
    cout << endl;
  }
}

bool isSquare(vector<vector<char> >& grid, int x1, int y1, int y2){
  int len = y2 - y1 + 1;
  for (int i = 0; i < len; ++i){
    if (grid[i + x1][y1] != '*'){
      return false;
    }
    if (grid[i + x1][y2] != '*'){
      return false;
    }
    if (grid[x1 + len - 1][y1 + i] != '*'){
      return false;
    }
  }
  return true;
}

void findMaxSubsquare(vector<vector<char> >& grid){
  int max_len = INT_MIN;
  int max_x, max_y;
  for (int i = 0; i < grid.size(); ++i){
    int s = -1;
    int e = -1;
    for (int j = 0; j < grid.size(); ++j){
      if (grid[i][j] == '*'){
        if (s == -1){
          s = e = j;
        }else{
          e++;
        }
      }else{
        if (s != -1){
          if (e - s + 1 > grid.size() - i){
            continue;
          }
          while (isSquare(grid, i, s , e) == false and s <= e){
            e--;
          }
          if (s <= e and (e - s + 1) > max_len){
            max_len = e - s + 1;
            max_x = i;
            max_y = s;
          }
          s = e = -1;
        }
      }
    }
  }
  if (max_len != INT_MIN){
    cout << "max sub squre length is " << max_len << endl;
    for (int i = 0; i < max_len; ++i){
      grid[max_x][i + max_y] = 'o';
      grid[max_x + max_len - 1][i + max_y] = 'o';
      grid[max_x + i][max_y] = 'o';
      grid[max_x + i][max_y + max_len - 1] = 'o';
    }
    print_screen(grid);
  }
}

int main(){
  vector<vector<char> > grid(10, vector<char>(10, '.'));
  for (int i = 2; i < 7; ++i){
    grid[i][2] = '*';
    grid[i][6] = '*';
    grid[2][i] = '*';
    grid[6][i] = '*';
  }
  for (int i = 3; i < 6; ++i){
    grid[i][3] = '*';
    grid[i][5] = '*';
    grid[3][i] = '*';
    grid[5][i] = '*';
  }

  print_screen(grid);
  cout << endl;
  findMaxSubsquare(grid);
  return 0;
}

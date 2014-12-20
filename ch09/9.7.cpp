#include <iostream>
#include <vector>

using namespace std;

void print_screen(vector<vector<char> >& s){
  for (int i = 0; i < s.size(); ++i){
    for (int j = 0; j < s.size(); ++j){
      cout << s[i][j];
    }
    cout << endl;
  }
}

void paint_fill(char color, int x, int y, vector<vector<char> >& screen){
  screen[x][y] = color;
  if (screen[x - 1][y] != color){
    paint_fill(color, x - 1, y, screen);
  }
  if (screen[x + 1][y] != color){
    paint_fill(color, x + 1, y, screen);
  }
  if (screen[x][y - 1] != color){
    paint_fill(color, x, y - 1, screen);
  }
  if (screen[x][y + 1] != color){
    paint_fill(color, x, y + 1, screen);
  }
}

int main(){
  vector<vector<char> > screen(10, vector<char>(10, '.'));
  for (int i = 2; i < 7; ++i){
    screen[2][i] = '*';
    screen[i][2] = '*';
    screen[6][i] = '*';
    screen[i][6] = '*';
  }
  print_screen(screen);
  paint_fill('*', 4, 4, screen);
  cout << endl;
  print_screen(screen);
  return 0;
}

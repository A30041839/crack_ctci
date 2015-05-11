#include "../ctci.h"

using namespace std;

void _paint_fill(char ncolor, char ocolor, int x, int y, vector<vector<char> >& screen){
  if (x < 0 or x >= screen[0].size() or y < 0 or y >= screen.size()) {
    return;
  }
  if (screen[y][x] == ocolor) {
    screen[y][x] = ncolor;
    _paint_fill(ncolor, ocolor, x + 1, y, screen);
    _paint_fill(ncolor, ocolor, x, y + 1, screen);
    _paint_fill(ncolor, ocolor, x - 1, y, screen);
    _paint_fill(ncolor, ocolor, x, y - 1, screen);
  }
}

void paint_fill(char ncolor, int x, int y, vector<vector<char> >& screen) {
  if (screen[y][x] == ncolor) {
    return;
  }
  _paint_fill(ncolor, screen[y][x], x, y, screen);
}

int main(){
  vector<vector<char> > screen(10, vector<char>(10, '.'));
  for (int i = 2; i < 7; ++i){
    screen[2][i] = '*';
    screen[i][2] = '*';
    screen[6][i] = '*';
    screen[i][6] = '*';
  }
  print_matrix(screen);
  paint_fill('x', 3, 3, screen);
  cout << endl;
  print_matrix(screen);
  return 0;
}

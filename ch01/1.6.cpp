#include "../ctci.h"

using namespace std;

void rotate_matrix(vector<vector<int> >& m){
  int len = m.size();
  for (int i = 0; i < len / 2; ++i) {
    int first = i, last = len - 1 - i;
    for (int j = first; j < last; ++j) {
      int offset = j - first;
      int tmp = m[i][j];
      m[i][j] = m[last - offset][i];
      m[last - offset][i] = m[last][last - offset];
      m[last][last-offset] = m[j][last];
      m[j][last] = tmp;
    }
  }
}

int main(){
  vector<vector<int> > matrix(5, vector<int>());
  int k = 1;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      matrix[i].push_back(k++);
    }
  }
  print_matrix(matrix);
  cout << "after rotation:" << endl;
  rotate_matrix(matrix);
  print_matrix(matrix);
  return 0;
}

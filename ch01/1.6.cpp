#include "../ctci.h"

using namespace std;

void rotate_matrix(vector<vector<int> >& m){
  size_t len = m.size();
  for (size_t i = 0; i <= (len - 1) >> 1; ++i){
      for (size_t j = i; j < len - i - 1; ++j){
				int tmp = m[i][j];
        m[i][j] = m[j][len - 1 - i];
        m[j][len - 1 - i] = m[len - 1 - i][len - 1 - j];
        m[len - 1 - i][len - 1 - j] = m[len - 1 - j][i];
        m[len - 1 - j][i] = tmp;
      }
  }
}

int main(){
  vector<vector<int> > matrix(9, vector<int>());
  int k = 1;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      matrix[i].push_back(k++);
    }
  }
  rotate_matrix(matrix);
  print_matrix(matrix);
  return 0;
}


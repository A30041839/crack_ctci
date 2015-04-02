#include "../ctci.h"

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int> > &matrix) {
    if (matrix.size() > 0){
      setZeroes1(matrix);
    }
  }

  void setZeroes1(vector<vector<int> > &matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; ++i) {
      if (matrix[0][i] == 0) {
        flag1 = true;
      }
    }
    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) {
        flag2 = true;
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[0][j] == 0 or matrix[i][0] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (flag1) {
      for (int i = 0; i < n; ++i) {
        matrix[0][i] = 0;
      }
    }
    if (flag2) {
      for (int i = 0; i < m; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};


int main(){
  Solution s;
  vector<vector<int> > m(10, vector<int>(20, 1));
  m[0][0]=0;
  m[5][0]=0;
  m[7][7]=0;
  m[9][4]=0;
  s.setZeroes(m);
  print_matrix(m);
  return 0;
}

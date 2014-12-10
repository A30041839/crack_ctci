#include <iostream>
#include <vector>

using namespace std;

void set_matrix(vector<vector<double> >& matrix){
  int m = matrix.size();
  int n = matrix[0].size();
  vector<int> flag_row(m, 0);
  vector<int> flag_col(n, 0);
  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      if (matrix[i][j] == 0){
        flag_row[i] = 1;
        flag_col[j] = 1;
      }
    }
  }
  for (int i = 0; i < m; ++i){
    if (flag_row[i] == 1){
      for (int k = 0; k < n; ++k)
        matrix[i][k]=0;
    }
  }

  for (int i = 0; i < n; ++i){
    if (flag_col[i] == 1){
      for (int k = 0; k < m; ++k)
        matrix[k][i]=0;
    }
  }
}

void print_matrix(vector<vector<double> >& matrix){
  int m = matrix.size();
  int n = matrix[0].size();
  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      if (j != n - 1)
        cout << matrix[i][j] << ",";
      else
        cout << matrix[i][j] << endl;
    }
  }
}

int main(){
  vector<vector<double> > m(10, vector<double>());
  for (int i = 0; i < 10; ++i)
    m[i].assign(20, 1);
  m[0][0]=0;
  m[5][0]=0;
  m[7][7]=0;
  m[9][4]=0;
  set_matrix(m);
  print_matrix(m);
  return 0;
}

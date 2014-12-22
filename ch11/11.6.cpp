#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print_matrix(vector<vector<int> >& matrix){
  for (int i = 0; i < matrix.size(); ++i){
    for (int j = 0; j < matrix[i].size(); ++j){
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

pair<int, int> find(vector<vector<int> >& matrix, int num, int rs, int re, int cs, int ce){
  if (matrix[rs][cs] == num){
    return pair<int, int>(rs, cs);
  }
  while(cs <= ce and matrix[re][cs] < num) cs++;
  while(cs <= ce and matrix[rs][ce] > num) ce--;
  while(rs <= re and matrix[rs][ce] < num) rs++;
  while(rs <= re and matrix[re][cs] > num) re--;
  if (cs > ce or rs > re){
    return pair<int, int>(-1, -1);
  }
  return find(matrix, num, rs, re, cs, ce);
}

int main(){
  vector<vector<int> > matrix(5, vector<int>(4, 0));
  int k = 1;
  for (int i = 0; i < 5; ++i){
    for (int j = 0; j < 4; ++j){
      matrix[i][j] = k++;
    }
  }
  print_matrix(matrix);
  pair<int, int> res = find(matrix, 15, 0, 4, 0, 3);
  cout << res.first << "," << res.second << endl;
  res = find(matrix, 1, 0, 4, 0, 3);
  cout << res.first << "," << res.second << endl;
  res = find(matrix, 20, 0, 4, 0, 3);
  cout << res.first << "," << res.second << endl;
  res = find(matrix, 100, 0, 4, 0, 3);
  cout << res.first << "," << res.second << endl;
  return 0;
}

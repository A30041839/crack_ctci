#include "../ctci.h"

using namespace std;

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

pair<int, int> _binary_find(vector<vector<int>>& matrix, int target, int tl_x,
                           int tl_y, int br_x, int br_y) {
  if ((br_x < tl_x or br_y < tl_y) or
    (tl_x == br_x and tl_y == br_y and matrix[tl_x][tl_y] != target)) {
    return {-1, -1};
  }
  int mid1_x = (tl_x + br_x) / 2;
  int mid1_y = (tl_y + br_y) / 2;
  int mid2_x = mid1_x < br_x ? mid1_x + 1 : mid1_x;
  int mid2_y = mid1_y < br_y ? mid1_y + 1 : mid1_y;
  if (matrix[mid1_x][mid1_y] == target) {
    return {mid1_x, mid1_y};
  }else if (matrix[mid2_x][mid2_y] == target) {
    return {mid2_x, mid2_y};
  }
  bool tl = true, br = true;
  if (matrix[mid1_x][mid1_y] < target) {
    tl = false;
  }
  if (matrix[mid2_x][mid2_y] > target) {
    br = false;
  }
  if (tl) {
    auto res = _binary_find(matrix, target, tl_x, tl_y, mid1_x, mid1_y);
    if (res.first != -1) {
      return res;
    }
  }
  if (br) {
    auto res = _binary_find(matrix, target, mid2_x, mid2_y, br_x, br_y);
    if (res.first != -1) {
      return res;
    }
  }
  auto res = _binary_find(matrix, target, mid1_x + 1, tl_y, br_x, mid2_y - 1);
  if (res.first != -1) {
    return res;
  }
  res = _binary_find(matrix, target, tl_x, mid1_y + 1, mid1_x, br_y);
  return res;
}

pair<int, int> binary_find(vector<vector<int>>& matrix, int target) {
  if (matrix.empty()) {
    return {-1, -1};
  }
  return _binary_find(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
}

int main(){
  vector<vector<int> > matrix(5, vector<int>(4, 0));
  int k = 1;
  for (int i = 0; i < 5; ++i){
    for (int j = 0; j < 4; ++j){
      matrix[i][j] = k++;
    }
  }
  //print_matrix(matrix);
  pair<int, int> res = find(matrix, 15, 0, 4, 0, 3);
  cout << res.first << "," << res.second << endl;
  res = find(matrix, 1, 0, 4, 0, 3);
  cout << res.first << "," << res.second << endl;
  res = find(matrix, 20, 0, 4, 0, 3);
  cout << res.first << "," << res.second << endl;
  res = find(matrix, 100, 0, 4, 0, 3);
  cout << res.first << "," << res.second << endl;

  res = binary_find(matrix, 15);
  cout << res.first << "," << res.second << endl;
  res = binary_find(matrix, 1);
  cout << res.first << "," << res.second << endl;
  res = binary_find(matrix, 20);
  cout << res.first << "," << res.second << endl;
  res = binary_find(matrix, 100);
  cout << res.first << "," << res.second << endl;

  return 0;
}

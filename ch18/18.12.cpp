#include "../ctci.h"

using namespace std;

int _maxSequenceSum(vector<int>& vec){
  int curSum = vec[0];
  int maxSum = curSum;
  for (int i = 1; i < vec.size(); ++i) {
    curSum = curSum > 0 ? curSum + vec[i] : vec[i];
    maxSum = max(maxSum, curSum);
  }
  return maxSum;
}

void _computeRowSum(vector<vector<int> >& matrix, vector<vector<int> >& helper,
  int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (i == 0) {
        helper[0][j] = matrix[0][j];
      }else {
        helper[i][j] = helper[i - 1][j] + matrix[i][j];
      }
    }
  }
}

void _computePartialSum(vector<vector<int> >& helper, vector<int>& partialSum,
  int rowStart, int rowEnd, int col) {
  for (int i = 0; i < col; ++i) {
    partialSum[i] = rowStart == 0 ? helper[rowEnd][i] : helper[rowEnd][i] - helper[rowStart - 1][i];
  }
}

int maxSubsum(vector<vector<int> >& matrix){
  int row = matrix.size();
  int col = matrix[0].size();
  int res = INT_MIN;
  vector<vector<int> > helper(row, vector<int>(col, 0));
  //init a helper matrix to store row sum
  _computeRowSum(matrix, helper, row, col);
  vector<int> partialSum(col, 0);
  for (int i = 0; i < row; ++i) {
    for (int j = i; j < row; ++j) {
      //compute partial sum
      _computePartialSum(helper, partialSum, i, j, col);
      res = max(res, _maxSequenceSum(partialSum));
    }
  }
  return res;
}

int main(){
  vector<vector<int> > matrix(3, vector<int>(3, 0));
  vector<int> a = {1, 2, -3};
  matrix[0].assign(a.begin(), a.end());
  vector<int> b = {2, 5, -1};
  matrix[1].assign(b.begin(), b.end());
  vector<int> c = {2, 0, 2};
  matrix[2].assign(c.begin(), c.end());
  cout << maxSubsum(matrix) << endl;
  return 0;
}

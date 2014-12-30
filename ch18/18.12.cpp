#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int _maxSequenceSum(vector<int>& vec){
  int prevSum = vec[0];
  int maxSum = prevSum;
  for (int i =  1; i < vec.size(); ++i){
    prevSum = prevSum > 0 ? prevSum + vec[i] : vec[i];
    maxSum = max(prevSum, maxSum);
  }
  return maxSum;
}

int maxSubsum(vector<vector<int> >& matrix, int m, int n){
  vector<vector<int> > helper(m, vector<int>(n, 0));
  //init a helper matrix to store row sum
  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      if (i == 0){
       helper[i][j] = matrix[i][j];
      }else{
       helper[i][j] = helper[i - 1][j] + matrix[i][j];
      }
    }
  }
  int maxSum = INT_MIN;
  for (int i = 0; i < m; ++i){
    for (int j = i; j < m; ++j){
      vector<int> vec(n, 0);
      for (int k = 0; k < n; ++k){
        if (i == 0){
          vec[k] = helper[j][k];
        }else{
          vec[k] = helper[j][k] - helper[i - 1][k];
        }
      }
      int curSum = _maxSequenceSum(vec);
      maxSum = max(maxSum, curSum);
    }
  }
  return maxSum;
}

int main(){
  vector<vector<int> > matrix(3, vector<int>(3, 0));
  vector<int> a = {1, 2, -3};
  matrix[0].assign(a.begin(), a.end());
  vector<int> b = {2, 5, -1};
  matrix[1].assign(b.begin(), b.end());
  vector<int> c = {2, 0, 2};
  matrix[2].assign(c.begin(), c.end());
  cout << maxSubsum(matrix, 3, 3) << endl;
  return 0;
}

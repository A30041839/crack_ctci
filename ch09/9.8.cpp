#include "../ctci.h"

using namespace std;

int _numofways_recurse(vector<int>& cents, int ttl, int dep){
  if (ttl == 0) {
    return 1;
  }
  if (dep == cents.size()) {
    return 0;
  }
  int res = 0;
  for (int k = 0; k <= ttl / cents[dep]; ++k) {
    res += _numofways_recurse(cents, ttl - k * cents[dep], dep + 1);
  }
  return res;
}

int numofways_recurse(vector<int>& cents, int ttl) {
  return _numofways_recurse(cents, ttl, 0);
}

//Ref: http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
int numofways_dp1(vector<int>& cents, int ttl) {
  int m = cents.size();
  vector<vector<int> > dp (ttl + 1, vector<int>(m, 0));
  for (int i = 0; i < m; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 1; i < ttl + 1; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = i - cents[j] >= 0 ? dp[i - cents[j]][j] : 0;
      int y = j >= 1 ? dp[i][j - 1] : 0;
      dp[i][j] = x + y;
    }
  }
  return dp[ttl][m - 1];
}

int numofways_dp2(vector<int>& cents, int ttl) {
  vector<int> dp(ttl + 1, 0);
  dp[0] = 1;
  int m = cents.size();
  for (int i = 0; i < m; ++i) {
    for (int j = cents[i]; j <= ttl; ++j) {
      dp[j] += dp[j - cents[i]];
    }
  }
  return dp[ttl];
}

int main(){
  int ttl = 100;
  vector<int> cents = {25, 10, 5 , 1};
  cout << numofways_recurse(cents, ttl) << endl;
  cout << numofways_dp1(cents, ttl) << endl;
  cout << numofways_dp2(cents, ttl) << endl;
  return 0;
}

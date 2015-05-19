#include "../ctci.h"

using namespace std;

int maxSubsum(vector<int>& vec){
  vector<int> dp(vec.size(), 0);
  dp[0] = vec[0];
  int res = dp[0];
  for (int i = 1; i < vec.size(); ++i){
    dp[i] = dp[i - 1] > 0 ? (dp[i - 1] + vec[i]) : vec[i];
    res = max(dp[i], res);
  }
  return res;
}

int main(){
  vector<int> vec = {2, -8, 3, -2, 4, -10};
  cout << maxSubsum(vec) << endl;
  return 0;
}

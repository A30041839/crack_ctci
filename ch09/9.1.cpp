#include "../ctci.h"

using namespace std;

int countPossiblewayDP(int n){
  if (n < 0){
    return 0;
  }
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int k = 3; k <= n; ++k){
   dp[k] = dp[k - 1] + dp[k - 2] + dp[k - 3];
  }
  return dp[n];
}

int main(){
  int n = 10;
  cout << countPossiblewayDP(n) << endl;
  return 0;
}

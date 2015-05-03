#include "../ctci.h"

using namespace std;

int numofways1(int n){
  int ways = 0;
  for (int i = 0; i <= n / 25; ++i){
    for (int j = 0; j <= (n - i * 25) / 10; ++j){
      for (int k = 0; k <= (n - i * 25 - j * 10) / 5; ++k){
        if (i * 25 + j * 10 + k * 5 <= n){
          ways++;
        }
      }
    }
  }
  return ways;
}

int numofways2(vector<int>& cents, int n){
  vector<int> dp(cents.size(), 1);
 }

int main(){
  int n = 100;
  vector<int> cents = {25, 10, 5 , 1};
  cout << numofways1(n) << endl;
  cout << numofways2(cents, n) << endl;
  return 0;
}

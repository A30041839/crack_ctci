#include "../ctci.h"

using namespace std;

int findKth(int k){
  if (k < 0) {
    return 0;
  }
  queue<int> q3, q5, q7;
  q3.push(3);
  q5.push(5);
  q7.push(7);
  int res = 1;
  for (int i = 0; i < k; ++i) {
    int v1 = q3.empty() ? INT_MAX : q3.front();
    int v5 = q5.empty() ? INT_MAX : q5.front();
    int v7 = q7.empty() ? INT_MAX : q7.front();
    res = min(v1, min(v5, v7));
    if (res == v1) {
      q3.push(3 * res);
      q5.push(5 * res);
      q3.pop();
    }else if (res == v5) {
      q5.push(5 * res);
      q5.pop();
    }else {
      q7.pop();
    }
    q7.push(7 * res);
  }
  return res;
}

int main(){
  int k = 1;
  cout << findKth(k) << endl;
  k = 3;
  cout << findKth(k) << endl;
  k = 6;
  cout << findKth(k) << endl;
  return 0;
}

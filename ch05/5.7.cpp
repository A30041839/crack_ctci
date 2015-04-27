#include "../ctci.h"

using namespace std;

int _findMissingNumber(vector<int>& vec, int p) {
  if (vec.empty()) {
    return 0;
  }
  vector<int> ones, zeros;
  for (int n : vec) {
    if ((n & (1 << p)) != 0) {
      ones.push_back(n);
    }else {
      zeros.push_back(n);
    }
  }
  if (zeros.size() <= ones.size()) {
    int res = _findMissingNumber(zeros, p + 1);
    return (res << 1);
  }else {
    int res = _findMissingNumber(ones, p + 1);
    return (res << 1) | 1;
  }
}

int findMissingNumber(vector<int>& vec) {
  return _findMissingNumber(vec, 0);
}

int main(){
  int n = 9, miss = 6;
  vector<int> vec;
  for (int i = 0; i <= n; ++i) {
    if (i != miss) {
      vec.push_back(i);
    }
  }
  cout << "The missing number is :" << findMissingNumber(vec) << endl;
  return 0;
}

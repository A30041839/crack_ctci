#include "../ctci.h"

using namespace std;

vector<pair<int, int>> findNumPair(vector<int>& v, int target) {
  if (v.size() < 2) {
    return {};
  }
  sort(v.begin(), v.end());
  int first = 0, last = v.size() - 1;
  vector<pair<int, int>> res;
  while (first < last) {
    int sum = v[first] + v[last];
    if (sum == target) {
      res.push_back({v[first], v[last]});
      first++;
      last--;
    }else if (sum < target) {
      first++;
    }else {
      last--;
    }
  }
  return res;
}

int main(){
  vector<int> vec = {-1, 0, 2, 3, -4, 6, -2, 4};
  vector<pair<int, int> > res;
  res = findNumPair(vec, 2);
  for (auto p : res){
    printf("%d, %d\n", p.first, p.second);
  }
  return 0;
}

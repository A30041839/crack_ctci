#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool _find(vector<int>& vec, int n){
  int low = 0;
  int high = vec.size() - 1;
  while (low <= high){
    int mid = (low + high) / 2;
    if (vec[mid] == n){
      return true;
    }
    if (vec[mid] < n){
      low = mid + 1;
    }else{
      high = mid - 1;
    }
  }
  return false;
}

void findNumPair(vector<int>& vec, vector<pair<int, int> >& res, int n){
  sort(vec.begin(), vec.end());
  int k = vec.size();
  k = k % 2 == 0 ? (k / 2) : (k / 2 - 1);
  for (int i = 0; i <= k; ++i){
    if (_find(vec, n - vec[i]) and (vec[i] <= n - vec[i])){
      res.push_back(pair<int, int>(vec[i], n - vec[i]));
    }
  }
}

int main(){
  vector<int> vec = {-1, 0, 2, 3, -4, 6, -2, 4};
  vector<pair<int, int> > res;
  findNumPair(vec, res, 2);
  for (auto p : res){
    printf("%d, %d\n", p.first, p.second);
  }
  return 0;
}

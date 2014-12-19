#include <iostream>
#include <vector>

using namespace std;

int findKth(int k, vector<int>& vec){
  if (k <= vec.size()){
    return vec[k - 1];
  }
  int cnt = k - vec.size();
  while (cnt--){
    int min = INT_MAX;
    for (int i = 0; i < vec.size(); ++i){
      if (vec[i] * 7 > vec.back()){
        if (vec[i] * 3 > vec.back() && vec[i] * 3 < min){
          min = vec[i] * 3;
          break;
        }else if (vec[i] * 5 > vec.back() && vec[i] * 5 < min){
          min = vec[i] * 5;
        }else if (vec[i] * 7 < min){
          min = vec[i] * 7;
        }
        if (vec[i] * 3 > min){
          break;
        }
      }
    }
    vec.push_back(min);
  }
  return vec.back();
}

int main(){
  vector<int> vec = {3 * 5 * 7};
  cout << findKth(1, vec) << endl;;
  cout << findKth(5, vec) << endl;
  cout << findKth(10, vec) << endl;
  cout << findKth(20, vec) << endl;
  return 0;
}

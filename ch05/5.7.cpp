#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int fetchbit(vector<vector<int> >& vec, int i, int j){
  return vec[i][j];
}

int findMissingNumber(vector<vector<int> >& vec, int n){
  vector<int> tmpvec(n + 1, 0);
  int len = floor(log(n) / log(2) + 1);
  for (int i = 0; i < vec.size(); ++i){
    int tmp = 0;
    int c = 1;
    for (int k = 0; k < len; ++k){
      tmp += fetchbit(vec, i, k) * c;
      c *= 2;
    }
    tmpvec[tmp] = 1;
  }
  int res = 0;
  for (int i = 0; i < tmpvec.size(); ++i){
    if (tmpvec[i] == 0){
      res = i;
      break;
    }
  }
  return res;
}

int main(){
  vector<vector<int> > vec;
  vector<int> vec1 = {1, 0, 1};
  vector<int> vec2 = {1, 0, 0};
  vector<int> vec3 = {0, 1, 0};
  vector<int> vec4 = {0, 0, 0};
  vector<int> vec5 = {0, 1, 0};
  vec.push_back(vec1);
  vec.push_back(vec2);
  vec.push_back(vec3);
  vec.push_back(vec4);
  vec.push_back(vec5);
  cout << "The missing number is :" << findMissingNumber(vec, 5) << endl;
  return 0;
}

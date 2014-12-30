#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int rand1(int k){
  return rand() % k;
}

vector<int> sample(vector<int> vec, int m){
  vector<int> res;
  int n = vec.size();
  for (int i = 0; i < m; ++i){
    int p = rand1(n - i);
    res.push_back(vec[p]);
    vec.erase(vec.begin() + p);
  }
  return res;
}

int main(){
  srand((unsigned)time(NULL));
  vector<int> vec;
  for (int i = 1; i <= 20; ++i){
    vec.push_back(i);
  }
  vector<int> vecSample = sample(vec, 6);
  for (int i = 0; i < 6; ++i){
    cout << vecSample[i] << ",";
  }
  cout << endl;
  return 0;
}

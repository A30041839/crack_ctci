#include "../ctci.h"

using namespace std;

vector<int> chooseMfromN(vector<int>& v, int m) {
  if (v.size() < m) {
    return {};
  }
  vector<int> res;
  for (int i = 0; i < m; ++i) {
    res.push_back(v[i]);
  }
  for (int i = m; i < v.size(); ++i) {
    int j = rand() % (i + 1);
    if (j < m) {
      res[j] = v[i];
    }
  }
  return res;
}

int main(){
  srand((unsigned)time(NULL));
  vector<int> vec;
  for (int i = 1; i <= 20; ++i){
    vec.push_back(i);
  }
  vector<int> res = chooseMfromN(vec, 6);
  print_array(res);
  return 0;
}

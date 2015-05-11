#include "../ctci.h"

using namespace std;

//time: O(n!)
void permutation1(vector<char>& vec, int start, vector<vector<char> >& res){
  if (start == vec.size()){
    res.push_back(vec);
    return;
  }
  for (int i = start; i < vec.size(); ++i){
    swap(vec[start], vec[i]);
    permutation1(vec, start + 1, res);
    swap(vec[start], vec[i]);
  }
}

vector<vector<char> > permutation2(vector<char>& vec, int start) {
  if (start == vec.size()) {
    return {{}};
  }
  vector<vector<char> > res1 = permutation2(vec, start + 1);
  vector<vector<char> > res2;
  for (int i = 0; i < res1.size(); ++i) {
    for (int j = 0; j <= res1[i].size(); ++j) {
      vector<char> tmp = res1[i];
      tmp.insert(tmp.begin() + j, vec[start]);
      res2.push_back(tmp);
    }
  }
  return res2;
}

int main(){
  vector<char> vec = {'a', 'b', 'c'};
  vector<vector<char> > res;
  res = permutation2(vec, 0);
  for (auto& v : res) {
    for (auto& c : v) {
      cout << c;
    }
    cout << endl;
  }
  return 0;
}

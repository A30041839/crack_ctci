#include "../ctci.h"

using namespace std;

void getAllSubsets1(vector<int>& vec, vector<vector<int> >& subsets, vector<int>& tmp, int i){
  if (i == vec.size()){
    subsets.push_back(tmp);
    return;
  }
  tmp.push_back(vec[i]);
  getAllSubsets1(vec, subsets, tmp, i + 1);
  tmp.pop_back();
  getAllSubsets1(vec, subsets, tmp, i + 1);
}

vector<int> _getSubset(int k, vector<int>& vec) {
  vector<int> res;
  int index = 0;
  for (; k > 0; k >>= 1) {
    if (k & 1) {
      res.push_back(vec[index]);
    }
    index++;
  }
  return res;
}

vector<vector<int> > getAllSubsets2(vector<int>& vec) {
  int l = vec.size();
  int n = 1 << l;
  vector<vector<int> > res;
  for (int k = 0; k < n; ++k) {
    res.push_back(_getSubset(k, vec));
  }
  return res;
}

vector<vector<int> > getAllSubsets3(vector<int>& vec, int dep) {
  if (dep == vec.size()) {
    return {{}};
  }
  vector<vector<int> > res = getAllSubsets3(vec, dep + 1);
  int n = res.size();
  for (int i = 0; i < n; ++i) {
    auto v = res[i];
    v.push_back(vec[dep]);
    res.push_back(v);
  }
  return res;
}

int main(){
  vector<int> vec = {1, 2, 3};
  vector<vector<int> > subsets;
  vector<int> tmp;
  //getAllSubsets1(vec, subsets, tmp, 0);
  subsets = getAllSubsets3(vec, 0);
  for (int i = 0; i < subsets.size(); ++i){
    if (subsets[i].size() == 0){
      cout << "Empty set." << endl;
      continue;
    }
    for (int j = 0; j < subsets[i].size(); ++j){
      cout << subsets[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}

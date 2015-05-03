#include "../ctci.h"

using namespace std;

void getAllSubsets(vector<int>& vec, vector<vector<int> >& subsets, vector<int>& tmp, int i){
  if (i == vec.size()){
    subsets.push_back(tmp);
    return;
  }
  tmp.push_back(vec[i]);
  getAllSubsets(vec, subsets, tmp, i + 1);
  tmp.pop_back();
  getAllSubsets(vec, subsets, tmp, i + 1);
}

int main(){
  vector<int> vec = {1, 2, 3};
  vector<vector<int> > subsets;
  vector<int> tmp;
  getAllSubsets(vec, subsets, tmp, 0);
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

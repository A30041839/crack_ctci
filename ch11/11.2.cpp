#include "../ctci.h"

using namespace std;

vector<string> sort_by_anagram1(vector<string>& arr){
  unordered_map<string, vector<string> > mp;
  for (int i = 0; i < arr.size(); ++i){
    string key = arr[i];
    sort(key.begin(), key.end());
    mp[key].push_back(arr[i]);
  }
  vector<string> res;
  for (auto pair : mp){
    for (auto str : pair.second){
      res.push_back(str);
    }
  }
  return res;
}

bool cmp(const string& s1, const string& s2) {
  string _s1 = s1, _s2 = s2;
  sort(_s1.begin(), _s1.end());
  sort(_s2.begin(), _s2.end());
  return _s1 < _s2; //return _s1 == _s2 wrong!
}

vector<string> sort_by_anagram2(vector<string>& arr) {
  sort(arr.begin(), arr.end(), cmp);
  return arr;
}

int main(){
  vector<string> arr = {"china", "usa", "beijing", "inahc", "asu", "google", "oolegg"};
  auto res = sort_by_anagram2(arr);
  print_array(res);
  return 0;
}

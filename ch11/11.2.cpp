#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string normalize(string str){
  string res = str;
  sort(res.begin(), res.end());
  return res;
}

void sort(vector<string>& arr){
  unordered_map<string, vector<string> > map;
  for (int i = 0; i < arr.size(); ++i){
    map[normalize(arr[i])].push_back(arr[i]);
  }
  arr.clear();
  for (auto pair : map){
    for (auto s : pair.second){
      arr.push_back(s);
    }
  }
}

int main(){
  vector<string> arr = {"china", "usa", "beijing", "inahc", "asu", "google", "oolegg"};
  sort(arr);
  for (int i = 0; i < arr.size(); ++i){
    cout << arr[i] << ",";
  }
  cout << endl;
  return 0;
}

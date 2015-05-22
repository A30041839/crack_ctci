#include "../ctci.h"

using namespace std;

bool canCompose1(string str, unordered_map<string, bool>& map, bool isOriginWord) {
  if (map.count(str) > 0 and !isOriginWord) {
    return map[str];
  }
  for (int i = 0; i < str.size() - 1; ++i) {
    string left = str.substr(0, i + 1);
    string right = str.substr(i + 1);
    if (map.count(left) > 0 and map[left] == true and canCompose1(right, map, false)) {
      return true;
    }
  }
  map[str] = false;
  return false;
}

bool canCompose2(string str, unordered_map<string, bool>& map) {
  vector<bool> dp(str.size(), false);
  for (int i = 0; i < str.size(); ++i) {
    string left = str.substr(0, i + 1);
    if (map.count(left) and i < str.size() - 1) {
      dp[i] = true;
    }else {
      for (int j = 0; j < i; ++j) {
        if (dp[j] == true and map.count(left.substr(j + 1))) {
          dp[i] = true;
          break;
        }
      }
    }
  }
  return dp.back();
}

string findLongestComposingWord(vector<string>& vec) {
  if (vec.size() < 2) {
    return "";
  }
  unordered_map<string, bool> map;
  for (string& s : vec) {
    map[s] = true;
  }
  sort(vec.begin(), vec.end(), [](const string& s1, const string& s2) {
    return s1.size() > s2.size();});
  for (string& s : vec) {
    if (canCompose2(s, map)) {
      return s;
    }
  }
  return "";
}

int main() {
  vector<string> vec = {"hello", "xyz", "helloxyz", "me", "foo", "fooxyzhellomefoo"};
  cout << findLongestComposingWord(vec) << endl;
  return 0;
}

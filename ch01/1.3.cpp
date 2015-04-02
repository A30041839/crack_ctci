#include "../ctci.h"

using namespace std;

//sort the two strings, if the sorted strings are equal, then s1 is permutation of s2
//time complexity: O(nlogn)
//space complexity: O(1)
bool is_permutation1(string s1, string s2){
  if (s1.empty() or s2.empty()) {
    return false;
  }
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  return s1 == s2;
}

//hash table, count frequency of each char
//time complexity: O(n)
//space complexity: O(n)
bool is_permutation2(string s1, string s2){
  vector<int> hash(256, 0);
  for (auto& c : s1) {
    hash[c]++;
  }
  for (auto& c : s2) {
    hash[c]--;
  }
  for (auto& i : hash) {
    if (i != 0) {
      return false;
    }
  }
  return true;
}

int main(){
  string s1 = "abcde";
  string s2 = "abcd";
  if (is_permutation2(s1, s2))
    cout << s1 << " is permutation of " << s2 << endl;
  else
    cout << s1 << " is not permutation of " << s2 << endl;
  return 0;
}

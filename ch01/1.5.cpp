#include "../ctci.h"

using namespace std;

string compress_string(const string& s) {
  string res;
  int len = (int)s.size();
  int cnt = 0;
  char buffer[10];
  for (int i = 0; i < len; ++i) {
    if (i == 0) {
      res.push_back(s[0]);
      cnt = 1;
    }else {
      if (s[i] == s[i - 1]) {
        cnt++;
      }else {
        sprintf(buffer, "%d", cnt);
        res.append(string(buffer));
        res.push_back(s[i]);
        cnt = 1;
      }
    }
  }
  if (cnt > 0) {
    sprintf(buffer, "%d", cnt);
    res.append(string(buffer));
  }
  return (int)res.size() < len ? res : s;
}

int main(){
  string s = "aabcccccaaa";
  cout << compress_string(s) << endl;
  s = "";
  cout << compress_string(s) << endl;
  return 0;
}


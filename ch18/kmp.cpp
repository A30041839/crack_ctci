#include "../ctci.h"

using namespace std;

void init(string str, vector<int>& p){
  int j = -1;
  p[0] = -1;
  for (int i = 1; i < str.length(); ++i){
    while (j >= 0 and str[j + 1] != str[i]){
      j = p[j];
    }
    if (str[j + 1] == str[i]){
      j++;
    }
    p[i] = j;
  }
}

void find(string s, string str){
  int m = str.length();
  int n = s.length();
  vector<int> helper(m, 0);
  init(str, helper);
  int j = -1;
  for (int i = 0; i < n; ++i){
    while (j >=0 and str[j + 1] != s[i]){
      j = helper[j];
    }
    if (str[j + 1] == s[i]){
      j++;
    }
    if (j == m - 1){
      printf("Found %s in %s at %d\n", str.c_str(), s.c_str(), i - m + 1);
      j = helper[j];
    }
  }
}

int main(){
  return 0;
}

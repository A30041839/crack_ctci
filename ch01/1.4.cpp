#include "../ctci.h"

using namespace std;

void replace(string& str, int len) {
  int cnt = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == ' ') {
      cnt++;
    }
  }
  for (int i = len -1, j = len + cnt * 2 - 1; i >= 0; --i) {
    if (str[i] == ' ') {
      str[j] = '0';
      str[j - 1] = '2';
      str[j - 2] = '%';
      j -= 3;
    }else {
      str[j--] = str[i];
    }
  }
}

int main(){
  string s = "Mr John Smith      ";
  replace(s, 13);
  cout << s << endl;
  return 0;
}

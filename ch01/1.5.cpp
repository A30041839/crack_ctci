#include <iostream>
#include <cstring>
using namespace std;

const char* compress(const char* str){
  if (str == NULL || str[0] == '\0') return "";
  size_t len = strlen(str);
  char* str_compressed = new char[len * 2 + 1];
  for (size_t i = 0, j = 0, k = 0; i <= len; ++i){
    if (str[i] != str[j]){
      str_compressed[k] = str[j];
      str_compressed[k + 1] = i - j + '0';
      k += 2;
      j = i;
    }
  }
  return strlen(str_compressed) < strlen(str) ? str_compressed : str;
}

int main(){
  const char* s = "aabcccccaaa";
  cout << compress(s) << endl;
  s = "abcdd";
  cout << compress(s) << endl;
  return 0;
}


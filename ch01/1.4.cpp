#include <iostream>
#include <cstring>
using namespace std;

void replace(char* str){
  if (str == NULL || str[0] == '\0') return;
  size_t len = strlen(str);
  for (int i = len - 1, j = i; i >= 0; --i){
    if (str[i] == ' '){
      if (j != len - 1){
        str[j] = '0';
        str[j - 1] = '2';
        str[j - 2] = '%';
        j -= 3;
      }
    }else{
      str[j] = str[i];
      --j;
    }
  }
}
int main(){
  const char* s = "Mr John Smith    ";
  char* s1 = new char[strlen(s) + 1];
  strcpy(s1, s);
  replace(s1);
  cout << s1 << endl;
  delete[] s1;
  return 0;
}

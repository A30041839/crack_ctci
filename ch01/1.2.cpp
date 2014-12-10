#include <iostream>
#include <cstring>

using namespace std;

void reverse(char* str){
  if (str == NULL || strlen(str) == 0) return;
  size_t len = strlen(str);
  for (size_t i = 0; i < len / 2; ++i){
    char tmp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = tmp;
  }
}

int main(){
  char str1[] = {'h','e', 'l', 'l', 'o'};
  char str2[] = {'a', 'b', 'c', 'd'};
  char* str3 = NULL;
  char str4[] = {'\0'};
  reverse(str1);
  reverse(str2);
  reverse(str3);
  reverse(str4);
  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;
  cout << str4 << endl;
  return 0;
}

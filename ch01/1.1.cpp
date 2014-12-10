#include <iostream>
#include <cstring>
using namespace std;

void unique_char(const char* str){
  int a[128] = {0};
  for (int i = 0; i < strlen(str); ++i){
    if (a[str[i] - 0] == 1){
      cout << str << " has duplicate chars." << endl;
      return;
    }else{
      a[str[i] - 0] = 1;
    }
  }
  cout << str << " doesn't have duplicate chars." << endl;
}

int main(){
  const char* str1 = "abcdefg!";
  const char* str2 = "hello-there!";
  unique_char(str1);
  unique_char(str2);
  return 0;
}



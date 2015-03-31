#include "../ctci.h" 

using namespace std;

//swap based method
//time complexity: O(n), space complexity:O(1)
void reverse(char* str){
  if (str == nullptr or strlen(str) == 0) {
    return;
  }
  int len = (int)strlen(str);
  for (int i = 0; i < len / 2; ++i) {
    swap(str[i], str[len - i - 1]);
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

/*Implement an algorithm to determine if a string has
 * all unique characters. What if you cannot use additional
 * data structures.
 */

#include "..\ctci.h"

using namespace std;

//time complexity: O(n), space complexity: O(1) 
bool unique_char(const char* str){
  vector<int> cnt(256, 0);
  for (int i = 0; i < strlen(str); ++i) {
    if (++cnt[str[i]] > 1) {
      return false;
    }
  }
  return true;
}

int main(){
  const char* str1 = "abcdefg!";
  const char* str2 = "hello-there!";
  if (unique_char(str2)) {
    cout << str2 << " doesn't have duplicate chars." << endl;
  }else {
    cout << str2 << " has duplicate chars." << endl;
  }
  return 0;
}



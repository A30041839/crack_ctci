#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool is_permutation1(const char* s1, const char* s2){
  //approach 1: sort the two strings, if the sorted strings are equal, then s1 is permutation of s2
  if (s1 == NULL || s2 == NULL) return false;
  if (strlen(s1) != strlen(s2)) return false;
  char* _s1 = new char[strlen(s1) + 1];
  char* _s2 = new char[strlen(s2) + 1];
  strcpy(_s1, s1);
  strcpy(_s2, s2);
  sort(_s1, _s1 + strlen(_s1));
  sort(_s2, _s2 + strlen(_s2));
  bool res = strcmp(_s1, _s2) == 0;
  delete[] _s1;
  delete[] _s2;
  return res;
}

bool is_permutation2(const char* s1, const char* s2){
  //approach 2: count frequency of each char
  if (s1 == NULL || s2 == NULL) return false;
  if (strlen(s1) != strlen(s2)) return false;
  int a[128] = {0};
  for (size_t i = 0; i < strlen(s1); ++i)
    a[s1[i] - 0]++;
  for (size_t i = 0; i < strlen(s2); ++i)
    a[s2[i] - 0]--;
  for (int i = 0; i < 128; ++i){
    if (a[i] != 0)
      return false;
  }
  return true;
}

int main(){
  const char* s1 = "abcde";
  const char* s2 = "bedca";
  const char* s3 = NULL;
  if (is_permutation2(s1, s2))
    cout << s1 << " is permutation of " << s2 << endl;
  else
    cout << s1 << " is not permutation of " << s2 << endl;
  return 0;
}

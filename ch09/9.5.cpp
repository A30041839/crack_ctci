#include "../ctci.h"

using namespace std;

void swap(char* a, char* b){
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void permutation(char* str, char* start){
  if (start[0] == 0){
    cout << str << endl;
    return;
  }
  for (char* j = start; *j != 0; ++j){
    swap(start, j);
    permutation(str, start + 1);
    swap(start, j);
  }
}

int main(){
  char s[3] = {'a', 'b', 'c'};
  permutation(s, s);
  return 0;
}

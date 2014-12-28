#include <iostream>

using namespace std;

int max(int a, int b){
  int t = (unsigned int)((a - b) & (1 << 31)) >> 31;
  int arr[2];
  arr[0] = a;
  arr[1] = b;
  return arr[t];
}

int main(){
  cout << max(4, 6) << endl;
  return 0;
}

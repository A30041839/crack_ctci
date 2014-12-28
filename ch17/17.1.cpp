#include <iostream>

using namespace std;

void swap(int& a, int& b){
  a ^= b;
  b ^= a;
  a ^= b;
}

int main(){
  int a = -14;
  int b = 122;
  swap(a, b);
  cout << a << "," << b << endl;
  return 0;
}

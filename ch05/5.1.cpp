#include <iostream>

using namespace std;

void printbits(int num){
  int i = 31;
  while (i >= 0){
    cout << ((num & (1 << i)) >> i); 
    i--;
  }
  cout << endl;
}

int insert(int m, int n, int i, int j){
  int mask = 0;
  for (int k = j; k >= i; k--){
    mask += 1 << k;
  }
  return (~mask & n) | (m << i);
}

int main(){
  int n = 1 << 10;
  int m = 19;
  printbits(insert(m, n, 2, 6));
  return 0;
}

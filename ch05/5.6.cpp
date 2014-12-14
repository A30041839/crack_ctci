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

void swapbits(int& num){
  for (int i = 0; i < 31; i += 2){
    int mask = 3 << i;
    int tmp = (mask & num) >> i;
    if (tmp == 1 or tmp == 2){
      num = ((tmp ^ 3) << i) | (num & ~mask) ;
    }
  }
}

int main(){
  int num = 279;
  printbits(num);
  swapbits(num);
  printbits(num);
  return 0;
}

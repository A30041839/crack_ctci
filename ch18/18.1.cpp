#include <iostream>

using namespace std;

int add(int a, int b){
  int sum = 0;
  int c = 0;
  for (int i = 0; i < 32; ++i){
    int mask = 1 << i;
    int d1 = mask & a;
    int d2 = mask & b;
    if (d1 ^ d2){
      if (c == 0){
        sum |= mask;
      }
    }else if (d1 == 0){
      if (c == 1){
        c = 0;
        sum |= mask;
      }
    }else{
      if (c == 0){
        c = 1;
      }else{
        sum |= mask;
      }
    }
  }

  return sum;
}

int main(){
  cout << add(-4, 5) << endl;
  cout << add(1, 8) << endl;
  cout << add(10, -100) << endl;
  cout << add(50, 45) << endl;
  cout << add(121, -120) << endl;
  return 0;
}

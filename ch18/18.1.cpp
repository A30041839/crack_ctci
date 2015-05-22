#include <iostream>

using namespace std;

int add(int a, int b){
  if (b == 0) {
    return a;
  }
  int sum = a ^ b;
  int carry = (a & b) << 1;
  return add(sum, carry);
}

int main(){
  cout << add(-4, 5) << endl;
  cout << add(1, 8) << endl;
  cout << add(10, -100) << endl;
  cout << add(50, 45) << endl;
  cout << add(121, -120) << endl;
  return 0;
}

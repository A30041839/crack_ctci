#include "../ctci.h"

using namespace std;

int _negate(int num){
  int sgn = num > 0 ? -1 : 1;
  int res = 0;
  while (num){
    num += sgn;
    res += sgn;
  }
  return res;
}

int multiply(int a, int b){
  int sum = 0;
  for (int k = 1; k <= abs(b); ++k){
    sum += a;
  }
  return b < 0 ? _negate(sum) : sum;
}

int subtract(int a, int b){
  return a + _negate(b);
}

int divide(int a, int b){
  int res = 1;
  while (1){
    if (multiply(res, abs(b)) > abs(a)){
      res--;
      break;
    }
    res++;
  }
  int sgn = multiply(a, b) > 0 ? 1 : -1;
  return sgn > 0 ? res : _negate(res);
}

int main(){
  int a = 10;
  int b = 3;
  cout << multiply(a, b) << endl;
  cout << subtract(a, b) << endl;
  cout << divide(a, b) << endl;
  return 0;
}

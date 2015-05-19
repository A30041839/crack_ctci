#include <iostream>

using namespace std;

int flip(int x) {
  return x ^ 1;
}

int sign(int x) {
  return flip((x >> 31) & 1);
}

int max(int a, int b){
  int c = a - b;
  int sa = sign(a);
  int sb = sign(b);
  int sc = sign(c);
  int use_sa = sa ^ sb;
  int use_sc = flip(use_sa);
  int k = use_sa * sa + use_sc * sc;
  int m = flip(k);
  return a *  k + b * m;
}

int main(){
  cout << max(4, 6) << endl;
  return 0;
}

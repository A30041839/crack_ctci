#include "../ctci.h"

using namespace std;

int count2freq(double n){
  if (n >= 2 and n < 10){
    return 1;
  }
  double k = (int)log10(n);
  int h = (int)(n / pow(10, k));
  int t =  (int)n % (int)pow(10, k);
  int s = count2freq(t);
  int m = h == 2 ? (s + t + 1) : s;
  return count2freq((int)pow(10, k) * h - 1) + m;
}

int main(){
  cout << count2freq(2) << endl;
  cout << count2freq(12) << endl;
  cout << count2freq(25) << endl;
  cout << count2freq(1024) << endl;
  return 0;
}

#include "../ctci.h"

using namespace std;

//iteratively count the # of multiples of 5, 25, 125...
int factorialZero(int n) {
  int res = 0;
  for (int i = 5; n / i > 0; i *= 5) {
    res += n / i;
  }
  return res;
}

int main(){
  int n = 30;
  cout << factorialZero(n) << endl;
  return 0;
}

#include <iostream>

using namespace std;

int trailzeroCount1(int n){
  long f = 1;
  int cnt = 0;
  for (int i = n; i >= 1; --i){
    f *= i;
    if (f % 10 == 0){
      cnt++;
      f /= 10;
    }
  }
  return cnt;
}

int trailzeroCount2(int n){
  int lastDigit = 1;
  int count = 0;
  for (int i = 1; i <= n; ++i){
    lastDigit *= i;
    if (lastDigit % 10 == 0){
      count++;
      lastDigit /= 10;
    }else{
      lastDigit %= 10;
    }
  }
  return count;
}

int main(){
  int n = 10;
  cout << trailzeroCount2(n) << endl;
  return 0;
}

#include <iostream>
#include <utility>

using namespace std;

void printbits(int num){
  int i = 31;
  while (i >= 0){
    cout << ((num & (1 << i)) >> i);
    i--;
  }
  cout << endl;
}

int numOf1(int num){
  int res = 0;
  while (num){
    if ((num & 1) == 1){
      res++;
    }
    num >>= 1;
  }
  return res;
}

pair<int, int> getNext(int num){
  pair<int, int> res;
  int cnt = numOf1(num);
  int c = 0;
  for (int k = num + 1; c != 2; k++){
    if (numOf1(k) == cnt){
      if (c == 0){
        res.first = k;
      }else{
        res.second = k;
      }
      c++;
    }
  }
  return res;
}

int main(){
  int a = 12;
  printbits(a);
  printbits(getNext(a).first);
  printbits(getNext(a).second);
  return 0;
}

#include <iostream>
#include <bitset>

using namespace std;

int insert(int m, int n, int i, int j){
  int mask = 0;
  for (int k = j; k >= i; k--){
    mask += 1 << k;
  }
  return (~mask & n) | (m << i);
}

int main(){
  bitset<11> N("10001000000");
  bitset<6> M("10011");
  int n = N.to_ulong();
  int m = M.to_ulong();
  int r = insert(m, n, 2, 6);
  bitset<11> res(r);
  cout << res.to_string() << endl;
  return 0;
}

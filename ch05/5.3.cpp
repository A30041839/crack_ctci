#include "../ctci.h"

using namespace std;

unsigned int getNext(unsigned int num) {
  int c1 = 0, c2 = 0;
  int tmp = num;
  while (tmp != 0 and (tmp & 1) == 0) {
    c1++;
    tmp >>= 1;
  }
  while ((tmp & 1) == 1) {
    c2++;
    tmp >>= 1;
  }
  if (c1 + c2 == 32 or c1 + c2 == 0) {
    return 0;
  }
  int p = c1 + c2;
  num |= (1 << p);
  int mask = ~0 << p;
  num &= mask;
  mask = (1 << (c2 - 1)) - 1;
  return num |= mask;
}

unsigned int getPrev(unsigned int num) {
  int c1 = 0, c2 = 0;
  int tmp = num;
  while ((tmp & 1) == 1) {
    c1++;
    tmp >>= 1;
  }
  if (tmp == 0) {
    return 0;
  }
  while ((tmp & 1) == 0) {
    c2++;
    tmp >>= 1;
  }
  int p = c1 + c2;
  int mask = ~0 << (p + 1);
  num &= mask;
  mask = ((1 << (c1 + 1)) - 1) << (c2 - 1);
  return num |= mask;
}

int main(){
  bitset<32> n("0");
  unsigned int num = n.to_ulong();
  unsigned int next = getNext(num);
  unsigned int prev = getPrev(num);
  n = next;
  cout << n.to_string() << endl;
  n = prev;
  cout << n.to_string() << endl;
  return 0;
}

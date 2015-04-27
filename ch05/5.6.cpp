#include "../ctci.h"

using namespace std;

void swapbits(int& num){
  num = ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1);
}

int main(){
  bitset<10> n("101100101");
  int num = n.to_ulong();
  swapbits(num);
  cout << bitset<10>(num).to_string() << endl;
  return 0;
}

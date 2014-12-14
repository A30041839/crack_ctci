#include <iostream>

using namespace std;

int num_of_changes(int a, int b){
  int c = a ^ b;
  int k = 0;
  while (c != 0){
    if (c % 2 == 1){
      k++;
    }
    c = c >> 1;
  }
  return k;
}

int main(){
  cout << num_of_changes(31, 14) << endl;
  return 0;
}

#include <iostream>

using namespace std;

int num_of_changes(int a, int b){
  int k = 0;
  for (int c = a ^ b; c; c = c & (c - 1)) {
    k++;
  }
  return k;
}

int main(){
  cout << num_of_changes(31, 14) << endl;
  return 0;
}

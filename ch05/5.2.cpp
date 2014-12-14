#include <iostream>
#include <vector>

using namespace std;

void print(double num){
  double tmp = num;
  int k = 2;
  vector<char> bits;
  bits.push_back('0');
  bits.push_back('.');
  while (tmp != 0 and k <= 32){
    k++;
    tmp *= 2;
    if (tmp >= 1){
      bits.push_back('1');
      tmp -= 1;
    }else{
      bits.push_back('0');
    }
  }
  if (tmp == 0){
    for (int i = 0; i < bits.size(); ++i){
      cout << bits[i];
    }
  }else{
    cout << "ERROR";
  }
  cout << endl;
}

int main(){
  print(0.5);
  print(0.72);
  return 0;
}

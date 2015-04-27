#include <iostream>
#include <string>

using namespace std;

string convert(double num){
  string bits("0.");
  int k = 0;
  while (num != 0 and k < 30){
    num *= 2;
    if (num >= 1){
      bits.push_back('1');
      num -= 1;
    }else{
      bits.push_back('0');
    }
    k++;
  }
  return num == 0 ? bits : "ERROR";
}

int main(){
  cout << convert(0.5) << endl;
  cout << convert(0.72) << endl;
  return 0;
}

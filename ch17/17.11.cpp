#include <iostream>

using namespace std;

int rand5(){
  return rand() % 5;
}

int rand7(){
  while (true){
    //generate 0-24 with equal prob.
    int num = 5 * rand5() + rand5();
    if (num < 21){
      return num % 7;
    }
  }
}

int main(){
  srand(0);
  for (int i = 0; i < 10; ++i){
    cout << rand7() << endl;
  }
  return 0;
}

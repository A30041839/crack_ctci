#include <iostream>
#include <string>

using namespace std;

struct cardgame{
  virtual void show() = 0;
};

struct blackjack:cardgame{
  void show(){
    cout << "i'm blackjack." << endl;
  }
};

struct redjack:cardgame{
  void show(){
    cout << "i'm redjack." << endl;
  }
};

struct cardfactory{
  static cardgame* getcardgame(string type){
    if (type == "blackjack"){
      return new blackjack();
    }
    if (type == "redjack"){
      return  new redjack();
    }
  }
};

int main(){
  string type1 = "blackjack";
  string type2 = "redjack";
  cardgame* cg1 = cardfactory::getcardgame(type1);
  cardgame* cg2 = cardfactory::getcardgame(type2);

  cg1->show();
  cg2->show();
  return 0;
}

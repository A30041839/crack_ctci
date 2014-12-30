#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int _rand(){
  return rand() % 52;
}

void shuffleDeckofCards(vector<int>& deck){
  vector<int> tmp(52, 0);
  for (int i = 0; i < 52; ++i){
    int pos = _rand();
    while (tmp[pos] != 0){
      pos = _rand();
    }
    tmp[pos] = deck[i];
  }
  deck = tmp;
}

int main(){
  vector<int> deck;
  for (int i = 1; i <= 52; ++i){
    deck.push_back(i);
  }
  srand((unsigned)time(NULL));
  shuffleDeckofCards(deck);
  for (int i = 0; i < 52; ++i){
    cout << deck[i] << ",";
  }
  cout << endl;
  return 0;
}

#include "../ctci.h"

using namespace std;

int _rand(){
  return rand() % 52;
}

void shuffleDeckofCards1(vector<int>& deck){
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

void shuffleDeckofCards2(vector<int>& deck) {
  for (int i = 0; i < deck.size(); ++i) {
    int pos = rand() % (i + 1);
    swap(deck[i], deck[pos]);
  }
}

int main(){
  vector<int> deck;
  for (int i = 1; i <= 52; ++i){
    deck.push_back(i);
  }
  srand((unsigned)time(NULL));
  shuffleDeckofCards2(deck);
  print_array(deck);
  return 0;
}

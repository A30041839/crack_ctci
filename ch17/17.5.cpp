#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void masterMind(vector<char>& solution, vector<char>& guess){
  unordered_set<char> hit;
  unordered_set<char> phit;
  for (int i = 0; i < 4; ++i){
    if (guess[i] != solution[i] and hit.count(guess[i]) == 0){
      phit.insert(guess[i]);
    }
    if (guess[i] == solution[i]){
      if (phit.count(guess[i]) != 0){
        phit.erase(guess[i]);
      }
      hit.insert(guess[i]);
    }
  }
  printf("There are %lu hit and %lu pseudo-hit.\n", phit.size(), hit.size());
}

int main(){
  vector<char> solution = {'R', 'G', 'B', 'Y'};
  vector<char> guess = {'G', 'G', 'R', 'R'};
  masterMind(solution, guess);
  return 0;
}

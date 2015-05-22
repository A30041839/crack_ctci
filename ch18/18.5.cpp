#include "../ctci.h"

using namespace std;

unordered_map<string, unordered_map<string, int> > indexer;

void buildIndex(string& file){
  string str;
  vector<string> v;
  istringstream iss(file);
  while (iss >> str){
    v.push_back(str);
  }
  for (int i = 0; i < v.size(); ++i){
    for (int j = i + 1; j < v.size(); ++j){
      string s1 = v[i] < v[j] ? v[i] : v[j];
      string s2 = v[i] < v[j] ? v[j] : v[i];
      if (indexer.count(s1) != 0){
        if (indexer[s1].count(s2) != 0){
          indexer[s1][s2] = min(indexer[s1][s2], j - i - 1);
        }else{
          indexer[s1][s2] = j - i - 1;
        }
      }else{
        indexer[s1][s2] = j - i - 1;
      }
    }
  }
}

int minDist(string s1, string s2){
  string a = s1 < s2 ? s1 : s2;
  string b = s1 < s2 ? s2 : s1;
  if (indexer.count(a) != 0 and indexer[a].count(b) != 0){
    return indexer[a][b];
  }
  return -1;
}

int main(){
  string file = "Since the beginning, we've focused on providing the best user experience possible.\
                 Whether we're designing a new Internet browser or a new tweak to the look of the homepage , \
                 we take great care to ensure that they will ultimately serve you, rather than our own internal goal or bottom line";
  buildIndex(file);
  string s1 = "Internet";
  string s2 = "homepage";
  cout << minDist(s1, s2) << endl;
  return 0;
}

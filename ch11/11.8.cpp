#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class numberTracker{
public:
  int getRankofNumber(int n){
    if (map.count(n) != 0){
      return map[n];
    }else{
      return -1;
    }
  }

  void track(int n){
    unordered_map<int, int>::iterator iter = map.begin();
    int tmp = 0;
    while (iter != map.end()){
      if (iter->first >= n){
        iter->second++;
      }else{
        tmp++;
      }
      iter++;
    }
    if (map.count(n) == 0){
      map[n] = tmp;
    }
  }

private:
  unordered_map<int, int> map;
};

int main(){
  numberTracker nt;
  vector<int> vec = {5, 1, 4, 4, 5, 9, 7, 13, 3};
  for (int a : vec){
    nt.track(a);
  }
  cout << nt.getRankofNumber(1) << endl;
  cout << nt.getRankofNumber(3) << endl;
  cout << nt.getRankofNumber(4) << endl;

  return 0;
}

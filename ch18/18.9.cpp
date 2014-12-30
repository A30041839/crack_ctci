#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <algorithm>

using namespace std;

class medianTracker{
private:
  priority_queue<int, vector<int> > smallHeap;
  priority_queue<int, vector<int>, greater<int> > largeHeap;

public:
  void add(int n){
    if (!smallHeap.empty()){
      int tmp = smallHeap.top();
      if (n < tmp){
        if (smallHeap.size() > largeHeap.size()){
          smallHeap.pop();
          smallHeap.push(n);
          largeHeap.push(tmp);
        }else{
          smallHeap.push(n);
        }
      }else{
        if (!largeHeap.empty()){
          largeHeap.push(n);
          if (largeHeap.size() > smallHeap.size()){
            tmp = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(tmp);
          }
        }else{
          largeHeap.push(n);
        }
      }
    }else{
      smallHeap.push(n);
    }
  }

  int getMedian(){
    if (!smallHeap.empty()){
      return smallHeap.top();
    }else{
      throw exception();
    }
  }
}; 

int main(){
  vector<int> vec = {2, 0, 3, -1, -2, -6, 8, 9, 4, 7, -8, 9};
  vector<int> tmp;
  medianTracker tracker;
  for (int i = 0; i < vec.size(); ++i){
    tracker.add(vec[i]);
    tmp.push_back(vec[i]);
    sort(tmp.begin(), tmp.end());
    int med = tmp[(tmp.size() - 1) / 2];
    cout << tracker.getMedian() << ":" << med << endl;
  }
  return 0;
}

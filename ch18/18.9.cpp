#include "../ctci.h"

using namespace std;

class medianTracker{
private:
  priority_queue<int, vector<int> > max_pq; //stores the less half
  priority_queue<int, vector<int>, greater<int> > min_pq; //stores the larger half

public:
  void add(int n){
    if (max_pq.size() == min_pq.size()) {
      if (!min_pq.empty() and n > min_pq.top()) {
        max_pq.push(min_pq.top());
        min_pq.pop();
        min_pq.push(n);
      }else {
        max_pq.push(n);
      }
    }else {
      if (max_pq.top() > n) {
        min_pq.push(max_pq.top());
        max_pq.pop();
        max_pq.push(n);
      }else {
        min_pq.push(n);
      }
    }
  }

  double getMedian(){
    if (max_pq.empty()) {
      return 0;
    }else if (max_pq.size() > min_pq.size()) {
      return max_pq.top();
    }else {
      return double(max_pq.top() + min_pq.top()) / 2;
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
    double med = (i + 1) & 1 ? tmp[i / 2] : double(tmp[i / 2] + tmp[i / 2 + 1]) / 2;
    cout << tracker.getMedian() << ":" << med << endl;
  }
  return 0;
}

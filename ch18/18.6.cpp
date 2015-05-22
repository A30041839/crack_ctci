#include "../ctci.h"

using namespace std;

vector<int> getMinNumbers1(vector<int>& vec, int k){
  vector<int> res;
  priority_queue<int, vector<int>, less<int> > max_pq;
  for (int i = 0; i < vec.size(); ++i) {
    if (i < k) {
      max_pq.push(vec[i]);
    }else if (max_pq.top() > vec[i]) {
      max_pq.pop();
      max_pq.push(vec[i]);
    }
  }
  while (!max_pq.empty()) {
    res.insert(res.begin(), max_pq.top());
    max_pq.pop();
  }
  return res;
}

int partition(vector<int>& vec, int start, int finish){
  int i = start - 1;
  int mid = (start + finish) / 2;
  swap(vec[mid], vec[finish]);
  for (int j = start; j < finish; ++j){
    if (vec[j] < vec[finish]){
      swap(vec[++i], vec[j]);
    }
  }
  swap(vec[i + 1], vec[finish]);
  return i + 1;
}

vector<int> getMinNumbers2(vector<int>& vec, int k){
  int start = 0;
  int finish = vec.size() - 1;
  while (start <= finish){
    int pos = partition(vec, start, finish);
    if (pos == start + k - 1) {
      break;
    }else if (pos < start + k - 1) {
      start = pos + 1;
      k -= (pos - start + 1);
    }else {
      finish = pos - 1;
    }
  }
  vector<int> res;
  for (int i = 0; i < k; ++i){
    res.push_back(vec[i]);
  }
  return res;
}

int main(){
  vector<int> vec;
  for (int i = 1; i < 10000; ++i){
    vec.push_back(i);
  }
  vector<int> res = getMinNumbers2(vec, 10);
  print_array(res);
  return 0;
}

#include "../ctci.h"

using namespace std;

int getMiddleStart(vector<int>& vec) {
  int i;
  for (i = 1; i < vec.size(); ++i) {
    if (vec[i - 1] > vec[i]) {
      break;
    }
  }
  return i;
}

int getMiddleEnd(vector<int>& vec) {
  int i;
  for (i = vec.size() - 2; i >= 0; --i) {
    if (vec[i] > vec[i + 1]) {
      break;
    }
  }
  return i;
}

int shrinkLeft(vector<int>& vec, int start, int val) {
  while (start >= 0 and vec[start] > val) {
    start--;
  }
  return start + 1;
}

int shrinkRight(vector<int>& vec, int end, int val) {
  while (end < vec.size() and vec[end] < val) {
    end++;
  }
  return end - 1;
}

pair<int, int> sortRange(vector<int>& vec){
  if (vec.empty()) {
    return {-1, -1};
  }
  int start = getMiddleStart(vec);
  if (start == vec.size()) {
    //no such range exist
    return {-1, -1};
  }
  int end = getMiddleEnd(vec);
  if (start > end) {
    swap(start, end);
  }
  auto minIter = min_element(vec.begin() + start, vec.begin() + end + 1);
  auto maxIter = max_element(vec.begin() + start, vec.begin() + end + 1);
  start = shrinkLeft(vec, start - 1, *minIter);
  end = shrinkRight(vec, end + 1, *maxIter);
  minIter = min_element(vec.begin() + start, vec.begin() + end + 1);
  start = shrinkLeft(vec, start - 1, *minIter);
  return {start, end};
}

int main(){
  vector<int> vec = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 };
  auto res = sortRange(vec);
  cout << res.first << "," << res.second << endl;
  return 0;
}

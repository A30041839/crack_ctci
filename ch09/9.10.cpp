#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct box{
  explicit box(int w, int h, int l, int id)
    : width(w), hight(h), length(l), index(id) {}
  int width;
  int hight;
  int length;
  int index;

  bool operator<(const box& o) const{
    return width < o.width and hight < o.hight and length < o.length;
  }
  void to_string(){
    printf("%d: %d, %d, %d\n", index, width, hight, length);
  }
};

int buildHighestprev(vector<box>& boxes, vector<box>& res){
  sort(boxes.begin(), boxes.end());
  //for (box b : boxes){
  //  b.to_string();
  //}
  vector<int> prev(boxes.size(), 0);
  vector<int> dp(boxes.size(), 0);
  int maxHeight = 0;
  int i;
  for (i = boxes.size() - 1; i >= 0; --i){
    int prevbox = i;
    for (int j = i + 1; j < boxes.size(); ++j){
      if (boxes[i] < boxes[j] and dp[i] < dp[j]){
        dp[i] = dp[j];
        prevbox = j;
      }
    }
    dp[i] += boxes[i].hight;
    prev[i] = prevbox;
    maxHeight = max(maxHeight, dp[i]);
  }
  for (i = 0; i < dp.size(); ++i){
    if (dp[i] == maxHeight){
      break;
    }
  }
  while(prev[i] != i){
    res.push_back(boxes[i]);
    i = prev[i];
  }
  res.push_back(boxes[i]);
  return maxHeight;
}

int main(){
  vector<box> boxes;
  boxes.push_back(box(2, 1, 1, 1));
  boxes.push_back(box(2, 2, 3, 2));
  boxes.push_back(box(3, 8, 2, 3));
  boxes.push_back(box(3, 6, 4, 4));
  boxes.push_back(box(4, 9, 10, 5));
  
  vector<box> res;
  cout << "max height is " << buildHighestprev(boxes, res) << endl;
  for (box b : res){
    b.to_string();
  }
  return 0;
}

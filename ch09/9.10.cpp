#include "../ctci.h"

using namespace std;

struct box{
  explicit box(int w, int h, int l, int id)
    : width(w), height(h), length(l), index(id) {}
  int width;
  int height;
  int length;
  int index;

  bool operator<(const box& o) const{
    return width < o.width and height < o.height and length < o.length;
  }
  void to_string(){
    printf("%d: %d, %d, %d\n", index, width, height, length);
  }
};

int build_highest_stack_dp(vector<box>& boxes) {
  sort(boxes.begin(), boxes.end());
  int n = boxes.size();
  vector<int> dp(n, 0);
  dp[0] = boxes[0].height;
  int res = dp[0];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (boxes[j] < boxes[i]) {
        dp[i] = max(dp[i], dp[j] + boxes[i].height);
      }
    }
    res = max(res, dp[i]);
  }
  return res;
}

int main(){
  vector<box> boxes;
  boxes.push_back(box(2, 1, 1, 1));
  boxes.push_back(box(2, 2, 3, 2));
  boxes.push_back(box(3, 8, 2, 3));
  boxes.push_back(box(3, 6, 4, 4));
  boxes.push_back(box(4, 9, 10, 5));
  cout << "max height is " << build_highest_stack_dp(boxes) << endl;
  return 0;
}

#include "../ctci.h"

using namespace std;

struct rankNode {
  int left_size;
  int val;
  rankNode* left;
  rankNode* right;
  explicit rankNode(int _val): left_size(0), val(_val), left(nullptr), right(nullptr) {}
};

class rankTree {
public:
  void insert(int val) {
    this->root = _insert(val, root);
  }

  int getRank(int val) {
    return _getRank(val, root);
  }

private:
  rankNode* _insert(int val, rankNode* node) {
    if (node == nullptr) {
      return new rankNode(val);
    }
    if (val <= node->val) {
      node->left_size++;
      node->left = _insert(val, node->left);
    }else {
      node->right = _insert(val, node->right);
    }
    return node;
  }

  int _getRank(int val, rankNode* node) {
    if (node == nullptr) {
      return -1;
    }
    if (val == node->val) {
      return node->left_size;
    }else if (val < node->val) {
      return _getRank(val, node->left);
    }else {
      int right_rank = _getRank(val, node->right);
      if (right_rank == -1) {
        return -1;
      }
      return node->left_size + 1 + right_rank;
    }
  }

  rankNode* root = nullptr;
};

class numberTracker{
public:
  explicit numberTracker() {
    tree = new rankTree();
  }

  void track(int val) {
    tree->insert(val);
  }

  int getRank(int val) {
    return tree->getRank(val);
  }

private:
  rankTree* tree = nullptr;
};

int main(){
  numberTracker nt;
  vector<int> vec = {5, 1, 4, 4, 5, 9, 7, 13, 3};
  for (int a : vec){
    nt.track(a);
  }
  sort(vec.begin(), vec.end());
  print_array(vec);
  cout << nt.getRank(1) << endl;
  cout << nt.getRank(7) << endl;
  cout << nt.getRank(13) << endl;
  cout << nt.getRank(4) << endl;

  return 0;
}

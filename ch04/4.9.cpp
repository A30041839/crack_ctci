#include "../header/BinaryTree.hpp"
#include "../ctci.h"

using namespace std;

void print(vector<int>& path, int beg, int end){
  for (int i = beg; i < end; ++i){
    cout << path[i] << "->";
  }
  cout << path[end] << endl;
}

void findPathSum(Tnode<int>* root, vector<int>& path, int target){
  if (root == nullptr) {
    return;
  }
  path.push_back(root->val);
  int sum = 0;
  for (int i = path.size() - 1; i >= 0; --i) {
    sum += path[i];
    if (sum == target) {
      print(path, i, path.size() - 1);
    }
  }
  findPathSum(root->lchild, path, target);
  findPathSum(root->rchild, path, target);
  path.pop_back();
}

int main(){
  BinaryTree<int> bt("1(2(1(1(,5),1(2,1)),2(2,0)),5(4,7))");
  vector<int> path;
  findPathSum(bt.getRoot(), path, 3);
  return 0;
}

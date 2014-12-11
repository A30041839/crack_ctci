#include "../stl/header/BinaryTree.hpp"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void print(vector<int>& path){
  for (int i = 0; i < path.size() - 1; ++i){
    cout << path[i] << "->";
  }
  cout << path.back() << endl;
}

//dfs search(preorder) of the subtree
void _findPathSum(Tnode<int>* root, vector<int>& path, int& cursum, int sum){
  if (root == NULL){
    return;
  }
  cursum += root->val;
  path.push_back(root->val);
  if (cursum == sum){
    print(path);
  }
  _findPathSum(root->lchild, path, cursum, sum);
  _findPathSum(root->rchild, path, cursum, sum);
  path.pop_back();
  cursum -= root->val;
}

//process each subtree in a preorder sequence
void findPathSum(Tnode<int>* root, vector<int>& path, int sum){
  int cursum = 0;
  if (root != NULL){
    _findPathSum(root, path, cursum, sum);
    if (root->lchild){
      cursum = 0;
      findPathSum(root->lchild, path, sum);
    }
    if (root->rchild){
      cursum = 0;
      findPathSum(root->rchild, path, sum);
    }
  }
}

int main(){
  BinaryTree<int> bt("1(2(1(1(,5),1(2,1)),2(2,0)),5(4,7))");
  vector<int> path;
  findPathSum(bt.getRoot(), path, 3);
  return 0;
}

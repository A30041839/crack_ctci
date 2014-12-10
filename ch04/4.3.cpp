#include "../stl/header/BinaryTree.hpp" 
#include <iostream>
#include <vector>

using namespace std;

Tnode<int>* _BuildMinHeightBST(vector<int>& vec, int low, int high){
  if (low > high){
    return NULL;
  }
  int mid = (high + low) / 2;
  Tnode<int>* root = new Tnode<int>(vec[mid]);
  root->lchild = _BuildMinHeightBST(vec, low, mid - 1);
  root->rchild = _BuildMinHeightBST(vec, mid + 1, high);
  return root;
}

Tnode<int>* BuildMinHeightBST(vector<int>& vec){
  if (vec.size() == 0){
    return NULL;
  }
  return _BuildMinHeightBST(vec, 0, vec.size() - 1);
}

void preOrder(Tnode<int>* root){
  if (root != NULL){
    cout << root->val << ",";
    preOrder(root->lchild);
    preOrder(root->rchild);
  }
}

int main(){
  vector<int> vec = {1,2,3,4,5,6,7,8,9};
  Tnode<int>* bst = BuildMinHeightBST(vec);
  if (bst != NULL){
    preOrder(bst);
  }
  return 0;
}

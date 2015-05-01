#include "../header/BinaryTree.hpp"
#include "../ctci.h"

using namespace std;

bool _checkBST1(Tnode<int>* root, int curmin, int curmax){
  if (root == nullptr) {
    return true;
  }
  if (root->val < curmin or root->val > curmax) {
    return false;
  }
  return _checkBST1(root->lchild, curmin, root->val - 1) and
    _checkBST1(root->rchild, root->val + 1, curmax);
}

bool checkBST1(Tnode<int>* root){
  return _checkBST1(root, INT_MIN, INT_MAX);
}

bool _checkBST2(Tnode<int>* root, int& prev){
  if (root == nullptr) {
    return true;
  }
  if (!_checkBST2(root->lchild, prev)) {
    return false;
  }
  if (prev >= root->val) {
    return false;
  }
  prev = root->val;
  if (!_checkBST2(root->rchild, prev)) {
    return false;
  }
  return true;
}

bool checkBST2(Tnode<int>* root){
  int prev = INT_MIN;
  return _checkBST2(root, prev);
}

int main(){
  const char* str1 = "1(2(4,5(7,)),3(,6))";
  BinaryTree<int> bt1(str1);
  const char* str2 = "5(3(1,4),8(6,9))";
  BinaryTree<int> bt2(str2);

  Tnode<int>* root = bt1.getRoot();
  if (checkBST1(root)){
    cout << "BinaryTree is a BST!" << endl;
  }else{
    cout << "BinaryTree is not a BST!" << endl;
  }

  return 0;
}

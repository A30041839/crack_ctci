#include "../stl/header/BinaryTree.hpp"
#include <iostream>

using namespace std;

template<class T>
bool checkBST(Tnode<T>* root){
  if (root == NULL){
    return true;
  }
  bool res1 = checkBST(root->lchild);
  bool res2 = checkBST(root->rchild);
  if (res1 and res2){
    if (root->lchild != NULL and root->lchild->val > root->val){
      return false;
    }
    if (root->rchild != NULL and root->rchild->val < root->val){
      return false;
    }
    return true;
  }else{
    return false;
  }
}

int main(){
  const char* str1 = "1(2(4,5(7,)),3(,6))";
  BinaryTree<int> bt1(str1);
  const char* str2 = "5(3(1,4),8(6,9))";
  BinaryTree<int> bt2(str2);

  Tnode<int>* root = bt2.getRoot();
  if (checkBST<int>(root)){
    cout << "BinaryTree is a BST!" << endl;
  }else{
    cout << "BinaryTree is not a BST!" << endl;
  }

  return 0;
}

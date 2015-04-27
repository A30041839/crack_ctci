#include "../header/BinaryTree.hpp"
#include "../ctci.h"

using namespace std;

template<class T>
bool checkBST(Tnode<T>* root){
  if (root == NULL){
    return true;
  }
  bool res1 = checkBST(root->lchild);
  bool res2 = checkBST(root->rchild);
  return res1 and res2
    and (!root->lchild or root->lchild->val < root->val)
    and (!root->rchild or root->rchild->val > root->val);
}

int main(){
  const char* str1 = "1(2(4,5(7,)),3(,6))";
  BinaryTree<int> bt1(str1);
  const char* str2 = "5(3(1,4),8(6,9))";
  BinaryTree<int> bt2(str2);

  Tnode<int>* root = bt1.getRoot();
  if (checkBST<int>(root)){
    cout << "BinaryTree is a BST!" << endl;
  }else{
    cout << "BinaryTree is not a BST!" << endl;
  }

  return 0;
}

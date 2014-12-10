#include "../stl/header/BinaryTree.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
bool isBalance(Tnode<T>* root, BinaryTree<T>& bt){
  if (root == NULL){
    return true;
  }
  bool lbalance = isBalance(root->lchild, bt);
  bool rbalance = isBalance(root->rchild, bt);
  if (lbalance == true and rbalance == true){
    if (abs(bt.getSubTreeHight(root->lchild) - bt.getSubTreeHight(root->rchild)) <= 1){
      return true;
    }
  }
  return false;
}

int main(){
  BinaryTree<char> bt1("a(b(d,e),c)");
  BinaryTree<char> bt2("a(b(d,e),)");
  if (isBalance(bt2.getRoot(), bt2)){
    cout << "Binary tree is balanced!" << endl;
  }else{
    cout << "Binary tree is not balanced!" << endl;
  }
  return 0;
}

#include "../header/BinaryTree.hpp"
#include "../ctci.h"

using namespace std;

//not a good solution, runs in O(n^2) time
template<class T>
bool isBalance1(Tnode<T>* root, BinaryTree<T>& bt){
  if (root == nullptr){
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

//O(n) time
template<class T>
int isBalance2(Tnode<T>* root) {
  if (root == nullptr) {
    return 0;
  }
  int left_height = isBalance2(root->lchild);
  if (left_height == -1) {
    return -1;
  }
  int right_height = isBalance2(root->rchild);
  if (right_height == -1) {
    return -1;
  }
  if (abs(left_height - right_height) <= 1) {
    return max(left_height, right_height) + 1;
  }else {
    return -1;
  }
}

int main(){
  BinaryTree<char> bt1("a(b(d,e),c)");
  BinaryTree<char> bt2("a(b(d,e),)");
  if (isBalance2(bt1.getRoot()) != -1){
    cout << "Binary tree is balanced!" << endl;
  }else{
    cout << "Binary tree is not balanced!" << endl;
  }
  return 0;
}

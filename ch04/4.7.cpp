#include "../header/BinaryTree.hpp"
#include "../ctci.h"

using namespace std;

template<class T>
bool containsNode(Tnode<T>* root, Tnode<T>* node){
  if (root == nullptr){
    return false;
  }
  if (root == node){
    return true;
  }
  return containsNode(root->lchild, node) || containsNode(root->rchild, node);
}

template<class T>
Tnode<T>* lca1(Tnode<T>* root, Tnode<T>* node1, Tnode<T>* node2){
  Tnode<T>* firstAncestor = root;
  while (true){
    if (containsNode(firstAncestor->lchild, node1) and containsNode(firstAncestor->lchild, node2)){
      firstAncestor = firstAncestor->lchild;
    }else if (containsNode(firstAncestor->rchild, node1) and containsNode(firstAncestor->rchild, node2)){
      firstAncestor = firstAncestor->rchild;
    }else{
      break;
    }
  }
  return firstAncestor; 
}

template<class T>
Tnode<T>* lca2(Tnode<T>* root, Tnode<T>* node1, Tnode<T>* node2){
  if (root == nullptr) {
    return nullptr;
  }
  if (root == node1 or root == node2) {
    return root;
  }
  auto left_lca = lca2(root->lchild, node1, node2);
  auto right_lca = lca2(root->rchild, node1, node2);
  if (left_lca and right_lca) {
    return root;
  }
  return left_lca != nullptr ? left_lca : right_lca;
}
 
int main(){
  const char* str = "A(B(D,E(G,)),C(,F))";
  BinaryTree<char> bt(str);
  Tnode<char>* root = bt.getRoot();
  Tnode<char>* node1 = root->lchild->lchild;//D
  Tnode<char>* node2 = root->lchild->rchild;//E
  cout << lca2(root, node1, node2)->val << endl; //B
  Tnode<char>* node3 = root->rchild->rchild;//F
  cout << lca2(root, node1, node3)->val << endl; //A
  Tnode<char>* node4 = root->lchild; //B
  cout << lca2(root, node4, node1)->val << endl; //B
  return 0;
}

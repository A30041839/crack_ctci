#include "../header/BinaryTree.hpp"
#include "../ctci.h"

using namespace std;

//the problem of lca1 and lca 2 is if the given node is not in the tree, the
//algorithm will return the wrong value(of course you can detect the exisitence
//of the two nodes in the first place. lca3 addresses this problem by returning
//a boolean flag indicating whether the returned node is the actual lca.
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

template<class T>
pair<Tnode<T>*, bool> _lca3(Tnode<T>* root, Tnode<T>* node1, Tnode<T>* node2) {
  if (root == nullptr) {
    return {nullptr, false};
  }
  if (root == node1 and root == node2) {
    return {root, true};
  }
  auto lres = _lca3(root->lchild, node1, node2);
  if (lres.second) {
    return lres;
  }
  auto rres = _lca3(root->rchild, node1, node2);
  if (rres.second) {
    return rres;
  }
  //left and right subtrees don't contain the lca
  if (lres.first and rres.first) {
    //current node must be the lca
    return {root, true};
  }else if (root == node1 or root == node2) {
    bool is_ancestor = (lres.first || rres.first) ? true : false;
    return {root, is_ancestor};
  }else {
    return lres.first ? lres : rres;
  }
}

template<class T>
Tnode<T>* lca3(Tnode<T>* root, Tnode<T>* node1, Tnode<T>* node2) {
  auto res = _lca3(root, node1, node2);
  if (res.second) {
    return res.first;
  }
  return nullptr;
}

int main(){
  const char* str = "A(B(D,E(G,)),C(,F))";
  BinaryTree<char> bt(str);
  Tnode<char>* root = bt.getRoot();
  Tnode<char>* node1 = root->lchild->lchild;//D
  Tnode<char>* node2 = root->lchild->rchild;//E
  cout << lca3(root, node1, node2)->val << endl; //B
  Tnode<char>* node3 = root->rchild->rchild;//F
  cout << lca3(root, node1, node3)->val << endl; //A
  Tnode<char>* node4 = root->lchild; //B
  cout << lca3(root, node4, node1)->val << endl; //B
  return 0;
}

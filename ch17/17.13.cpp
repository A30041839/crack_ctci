#include <iostream>

using namespace std;

template<class T>
struct Tnode{
  Tnode* lchild;
  Tnode* rchild;
  T val;
  explicit Tnode(T _val): lchild(0), rchild(0), val(_val) {}
};

typedef Tnode<int>* pointer;

pointer getPrevious(pointer node){
  node = node->lchild;
  while (node and node->rchild){
    node = node->rchild;
  }
  return node;
}

pointer getNext(pointer node){
  node = node->rchild;
  while(node and node->lchild){
    node = node->lchild;
  }
  return node;
}

pointer bst2dlist(pointer root){
  if (root->lchild){
    bst2dlist(root->lchild);
  }
  pointer p = getPrevious(root);
  root->lchild = p;
  if (p){
    p->rchild = root;
  }
  if (root->rchild){
    bst2dlist(root->rchild);
  }
  p = getNext(root);
  root->rchild = p;
  if (p){
    p->lchild = root;
  }

  while(root->lchild){
    root = root->lchild;
  }
  return root;
}

int main(){
  Tnode<int>* p1 = new Tnode<int>(1);
  Tnode<int>* p2 = new Tnode<int>(2);
  Tnode<int>* p3 = new Tnode<int>(3);
  Tnode<int>* p4 = new Tnode<int>(4);
  Tnode<int>* p5 = new Tnode<int>(5);
  Tnode<int>* p6 = new Tnode<int>(6);
  Tnode<int>* p7 = new Tnode<int>(7);
  p2->lchild = p1;
  p2->rchild = p3;
  p6->lchild = p5;
  p6->rchild = p7;
  p4->lchild = p2;
  p4->rchild = p6;

  Tnode<int>* head = bst2dlist(p4);
  while (head != NULL){
    cout << head->val << ",";
    head = head->rchild;
  }
  cout << endl;

  delete p1;
  delete p2;
  delete p3;
  delete p4;
  delete p5;
  delete p6;
  delete p7;
  return 0;
}


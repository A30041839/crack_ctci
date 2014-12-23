#include <iostream>
#include <stdexcept>

using namespace std;

struct Node{
  struct Node* lchild;
  struct Node* rchild;
  
  void to_string(){
    printf("%d,%d\n", lchild, rchild);
  }
};

void cloneNode(Node* ptr, Node*& clonePtr){
  if (ptr == NULL){
    throw exception();
  }
  if (clonePtr){
    delete clonePtr;
  }
  clonePtr = new Node();
  clonePtr->lchild = ptr->lchild;
  clonePtr->rchild = ptr->rchild;
}

int main(){
  Node* ptr = new Node();
  ptr->lchild = ptr;
  ptr->rchild = ptr;
  Node* clone = NULL;
  cloneNode(ptr, clone);
  ptr->to_string();
  clone->to_string();
  return 0;
}

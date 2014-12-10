#include <iostream>

Tnode* next(Tnode* node){
  if (node->rchild == NULL){
    return node->parent;
  }
  Tnode* ptr = node->rchild;
  while (ptr->lchild != NULL){
    ptr = ptr->lchild;
  }
  return ptr;
}


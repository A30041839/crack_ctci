//find the in-order successor node in a binary search tree.
Tnode* next(Tnode* node){
  if (!node) {
    return nullptr;
  }
  if (node->rchild != nullptr) {
    node = node->rchild;
    while (node->lchild) {
      node = node->lchild;
    }
    return node;
  }else {
    Tnode* parent_node = node->parent;
    while (parent_node and parent_node->lchild != node) {
      node = parent_node;
      parent_node = parent_node->parent;
    }
    return parent_node;
  }
}


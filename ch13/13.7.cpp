#include "../ctci.h"

using namespace std;

struct Node{
  struct Node* lchild;
  struct Node* rchild;
};

Node* clone(Node* cur, map<Node*, Node*>& mp){
  if (cur == nullptr) {
    return nullptr;
  }
  if (mp.count(cur) > 0) {
    return mp[cur];
  }
  Node* node_cpy = new Node();
  mp[cur] = node_cpy;
  node_cpy->lchild = clone(cur->lchild, mp);
  node_cpy->rchild = clone(cur->rchild, mp);
  return node_cpy;
}

int main(){
  Node* ptr = new Node();
  ptr->lchild = new Node();
  ptr->rchild = new Node();
  map<Node*, Node*> mp;
  Node* clone_node = clone(ptr, mp);
  return 0;
}

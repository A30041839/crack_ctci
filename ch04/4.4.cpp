#include "../header/BinaryTree.hpp"
#include "../header/LinkedList.hpp"
#include "../ctci.h"

using namespace std;

void buildLists(Tnode<char>* root, vector<LinkedList<char> >& res){
  if (root == nullptr){
    return;
  }
  queue<Tnode<char>* > q;
  q.push(root);
  while (!q.empty()) {
    res.push_back(LinkedList<char>());
    int len = q.size();
    for (int i = 0; i < len; ++i) {
      Tnode<char>* node = q.front();
      q.pop();
      res.back().insert_to_tail(node->val);
      if (node->lchild) {
        q.push(node->lchild);
      }
      if (node->rchild) {
        q.push(node->rchild);
      }
    }
  }
}

int main(){
  const char* str = "A(B(D,E(G,)),C(,F))";
  BinaryTree<char> bt(str);
  vector<LinkedList<char> > vec;
  buildLists(bt.getRoot(), vec);
  for (int i = 0; i < (int)vec.size(); ++i){
    vec[i].print_list();
  }
  return 0;
} 




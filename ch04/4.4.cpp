#include "../stl/header/BinaryTree.hpp"
#include "../stl/header/LinkedList.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void buildLists(Tnode<char>* root, vector<LinkedList<char> >& res){
  if (root == NULL){
    return;
  }
  queue<Tnode<char>* > q;
  q.push(NULL);
  q.push(root);
  bool flag = true;
  while (!q.empty()){
    Tnode<char>* tmp = q.front();
    q.pop();
    if (tmp == NULL){
      //create a new linked list
      res.push_back(LinkedList<char>());
      flag = false;
    }else{
      res[res.size() - 1].insert_to_tail(tmp->val);
      if (tmp->lchild != NULL){
        if (flag == false){
          q.push(NULL);
          flag = true;
        }
        q.push(tmp->lchild);
      }
      if (tmp->rchild != NULL){
        if (flag == false){
          q.push(NULL);
          flag = true;
        }
        q.push(tmp->rchild);
      }
    }
  }
}

int main(){
  const char* str = "A(B(D,E(G,)),C(,F))";
  BinaryTree<char> bt(str);
  vector<LinkedList<char> > vec;
  buildLists(bt.getRoot(), vec);
  for (int i = 0; i < vec.size(); ++i){
    vec[i].print_list();
  }
  return 0;
} 




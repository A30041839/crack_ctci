#include "../header/BinaryTree.hpp"
#include "../ctci.h"

using namespace std;

void preOrder(Tnode<char>* root, vector<Tnode<char>* >& vec){
  if (root != NULL){
    vec.push_back(root);
    preOrder(root->lchild, vec);
    preOrder(root->rchild, vec);
  }
}

void inOrder(Tnode<char>* root, vector<Tnode<char>* >& vec){
  if (root != NULL){
    preOrder(root->lchild, vec);
    vec.push_back(root);
    preOrder(root->rchild, vec);
  }
}

bool vectorEqual(vector<Tnode<char>* >& v1, vector<Tnode<char>* >& v2){
  if (v1.size() != v2.size()){
    return false;
  }
  for (int i = 0; i < v1.size(); ++i){
    if (v1[i]->val != v2[i]->val){
      return false;
    }
  }
  return true;
}

//cost too much memory given the large amounts of tree nodes, space complexity is
//O(n + m), but time comlexity is slightly better: O(n + m).
bool isSubtree1(vector<Tnode<char>* >&vec_pre1, Tnode<char>* smallTree){
  vector<Tnode<char>* > vec_pre2;
  preOrder(smallTree, vec_pre2);
  vector<Tnode<char>* > vec_in2;
  inOrder(smallTree, vec_in2);
  vector<Tnode<char>* > tmp;
  for (int i = 0; i < vec_pre1.size() - vec_pre2.size() + 1; ++i){
    int j = 0;
    for (; j < vec_pre2.size(); ++j){
      if (vec_pre1[i + j]->val != vec_pre2[j]->val){
        break;
      }
    }
    if (j == vec_pre2.size()){
      //smallTree's preOrder sequence detected
      tmp.push_back(vec_pre1[i]);
    }
  }
  for (int i = 0; i < tmp.size(); ++i){
    vector<Tnode<char>* > vec_in1;
    inOrder(tmp[i], vec_in1);
    if (vectorEqual(vec_in1, vec_in2)){
      return true;
    }
  }
  return false;
}

//time complexity: O(n + km)
//space complexity: O(log(n) + log(m))
bool _match_tree(Tnode<char>* t1, Tnode<char>* t2) {
  if (t1 == nullptr or t2 == nullptr) {
    return t1 == t2;
  }
  if (t1->val != t2->val) {
    return false;
  }
  return _match_tree(t1->lchild, t2->lchild) and _match_tree(t1->rchild, t2->rchild);
}

bool _isSubtree2(Tnode<char>* t1, Tnode<char>* t2) {
  if (t1 == nullptr) {
    return false;
  }
  if (t1->val == t2->val) {
    if (_match_tree(t1, t2)) {
      return true;
    }
  }
  return _isSubtree2(t1->lchild, t2) || _isSubtree2(t1->rchild, t2);
}

bool isSubtree2(Tnode<char>* t1, Tnode<char>* t2) {
  if (t2 == nullptr) {
    return true;
  }
  if (t1 == nullptr) {
    return false;
  }
  return _isSubtree2(t1, t2);
}


int main(){
  vector<Tnode<char>* > vec;
  const char* s1 = "5(3(1,4),8(6,9))";
  const char* s2 = "8(6,9)";
  BinaryTree<char> largeTree(s1);
  BinaryTree<char> smallTree(s2);
  preOrder(largeTree.getRoot(), vec);
  if (isSubtree2(largeTree.getRoot(), smallTree.getRoot())){
    cout << "the small tree is subtree of large tree!" << endl;
  }else{
    cout << "the small tree is not subtree of large tree!" << endl;
  }
  return 0;
}

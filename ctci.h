#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <list>
#include <bitset>
#include <mutex>
#include <time.h>

//data structures
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

//public functions
void inorder(TreeNode* root){
  if (root){
    inorder(root->left);
    std::cout << root->val << ",";
    inorder(root->right);
  }
}

void postorder(TreeNode* root){
  if (root){
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << ",";
  }
}

void preorder(TreeNode* root){
  if (root){
    std::cout << root->val << ",";
    preorder(root->left);
    preorder(root->right);
  }
}

void print_array(int nums[], int n){
  for (int i = 0; i < n; ++i){
    std::cout << nums[i] << ",";
  }
  std::cout << std::endl;
}

template<class T>
void print_array(std::vector<T> &v) {
  for (T& tmp : v) {
    std::cout << tmp << ",";
  }
  std::cout << std::endl;
}

template<class T>
void print_matrix(std::vector<std::vector<T> >& m){
  for (size_t i = 0; i < m.size(); ++i){
    for (size_t j = 0; j < m[0].size(); ++j){
      if (j != m[0].size() - 1) {
        std::cout << m[i][j] << " ";
      }
      else {
        std::cout << m[i][j] << std::endl;
      }
    }
  }
}

template<class T>
void print_stack(std::stack<T>& s){
  std::vector<T> v;
  while (!s.empty()){
    T tmp = s.top();
    v.push_back(tmp);
    s.pop();
    std::cout << tmp << ",";
  }
  std::cout << std::endl;
  for (int i = v.size() - 1; i >= 0; --i)
    s.push(v[i]);
}

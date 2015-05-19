#include "../ctci.h"

using namespace std;

TreeNode* convertBST2list(TreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  }
  TreeNode* left = nullptr;
  if (root->left) {
    left = convertBST2list(root->left);
    TreeNode* ptr = left;
    while (ptr->right) {
      ptr = ptr->right;
    }
    ptr->right = root;
    root->left = ptr;
  }
  if (root->right) {
    TreeNode* right = convertBST2list(root->right);
    root->right = right;
    right->left = root;
  }
  return left ? left : root;
}


int main(){
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p4 = new TreeNode(4);
  TreeNode* p5 = new TreeNode(5);
  TreeNode* p6 = new TreeNode(6);
  TreeNode* p7 = new TreeNode(7);
  p2->left = p1;
  p2->right = p3;
  p6->left = p5;
  p6->right = p7;
  p4->left = p2;
  p4->right = p6;

  TreeNode* head = convertBST2list(p4);

  while (head != nullptr){
    cout << head->val << ",";
    head = head->right;
  }
  cout << endl;
  return 0;
}


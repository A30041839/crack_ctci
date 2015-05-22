#include "../ctci.h"

using namespace std;

//use suffix tree to do substring matching

struct SuffixTreeNode {
  char val;
  map<char, SuffixTreeNode*> next;
  vector<int> indexes;
  SuffixTreeNode(char v): val(v) {}
};

class SuffixTree {
public:
  SuffixTree() {
    root = new SuffixTreeNode('#');
  }

  SuffixTree(string str) {
    root = new SuffixTreeNode('#');
    for (int i = 0; i < str.size(); ++i) {
      insert(str.substr(i), i);
    }
  }

  void insert(string str, int index) {
    if (str.empty()) {
      return;
    }
    SuffixTreeNode* ptr = root;
    int i;
    for (i = 0; i < str.size(); ++i) {
      if (ptr->next.count(str[i]) == 0) {
        break;
      }
      ptr = ptr->next[str[i]];
      ptr->indexes.push_back(index);
    }
    string str2insert = str.substr(i);
    for (i = 0; i < str2insert.size(); ++i) {
      SuffixTreeNode* node = new SuffixTreeNode(str2insert[i]);
      node->indexes.push_back(index);
      ptr->next.insert(make_pair(str2insert[i], node));
      ptr = node;
    }
  }

  vector<int> search(string str) {
    SuffixTreeNode* ptr = root;
    for (int i = 0; i < str.size() and ptr->next.count(str[i]); ++i) {
      ptr = ptr->next[str[i]];
      if (i == str.size() - 1) {
        return ptr->indexes;
      }
    }
    return {-1};
  }

private:
  SuffixTreeNode* root = nullptr;
};

int main() {
  vector<string> v = {"abc", "xyz", "nike", "x"};
  string str = "xyzxabcnickx";
  SuffixTree tree(str);
  for (auto s : v) {
    vector<int> res = tree.search(s);
    print_array(res);
  }
  return 0;
}

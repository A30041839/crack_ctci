#include "../ctci.h"

using namespace std;

void printParentheses(int npair, int k, int nleft, vector<char>& v){
  if (npair <= 0) return;
  if (v.size() == 2 * npair){
    for (int i = 0; i < v.size(); ++i){
      cout << v[i];
    }
    cout << endl;
    return;
  }
  if (k > 0){
    v.push_back(')');
    printParentheses(npair, k - 1, nleft, v);
    v.pop_back();
  }
  if (nleft < npair){
    v.push_back('(');
    printParentheses(npair, k + 1, nleft + 1, v);
    v.pop_back();
  }
}

int main(){
  vector<char> v;
  printParentheses(3, 0, 0, v);
  return 0;
}

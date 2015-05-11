#include "../ctci.h"

using namespace std;

void _printParentheses(int pair, int left, int left_unbalanced, string str,
  vector<string>& res){
  if (str.size() == pair * 2 and !str.empty()) {
    res.push_back(str);
    return;
  }
  if (left < pair) {
    str.push_back('(');
    _printParentheses(pair, left + 1, left_unbalanced + 1, str, res);
    str.pop_back();
  }
  if (left_unbalanced > 0) {
    str.push_back(')');
    _printParentheses(pair, left, left_unbalanced - 1, str, res);
    str.pop_back();
  }
}

vector<string> printParentheses(int n) {
  vector<string> res;
  _printParentheses(n, 0, 0, "", res);
  return res;
}

int main(){
  vector<string> res = printParentheses(3);
  print_array(res);
  return 0;
}

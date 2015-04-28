#include "../ctci.h"

using namespace std;

//each time, we keep the current maximum elements
//in the additional stack, finally move elements
//from additional stack to the original stack.
//time: O(n^2) space O(n)
template<class T>
void sort_stack1(stack<T>& s){
  stack<T> _s;
  while (!s.empty()){
    int k = s.size();
    T max = s.top();
    while (!s.empty()){
      T tmp = s.top();
      if (max < tmp) max = tmp;
      _s.push(tmp);
      s.pop();
    }
    int cnt = 0;
    while (k--){
      T tmp = _s.top();
      if (tmp == max){
       ++cnt;
      }else{
        s.push(tmp);
      }
      _s.pop();
    }
    while(cnt--) {
      _s.push(max);
    }
  }

  while(!_s.empty()){
    s.push(_s.top());
    _s.pop();
  }
}

//works like insertion sort, each time we insert the
//element from original stack to the additional stack's
//proper position.
//time: O(n^2) space: O(n)
template<class T>
void sort_stack2(stack<T>& s) {
  stack<T> _s;
  while (!s.empty()) {
    T tmp = s.top();
    s.pop();
    while (!_s.empty() and _s.top() < tmp) {
      s.push(_s.top());
      _s.pop();
    }
    _s.push(tmp);
  }
  while (!_s.empty()) {
    s.push(_s.top());
    _s.pop();
  }
}

int main(){
  stack<int> s;
  vector<int> v = { 1, -2, 2, 0, 9, 23, 21, 4, 5, 10, -8 };
  for (size_t i = 0; i < v.size(); ++i) {
    s.push(v[i]);
  }
  sort_stack2(s);
  print_stack(s);
  return 0;
}

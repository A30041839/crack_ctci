#include "../header/stack.hpp"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
void sort_stack(stack<T>& s){
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

template<class T>
void print_stack(stack<T>& s){
  vector<T> v;
  while (!s.empty()){
    T tmp = s.top();
    v.push_back(tmp);
    s.pop();
    cout << tmp << ",";
  }
  cout << endl;
  for (int i = v.size() - 1; i >= 0; --i)
    s.push(v[i]);
}


int main(){
  stack<int> s;
  vector<int> v = { 1, -2, 2, 0, 9, 23, 21, 4, 5, 10, -8 };
  for (size_t i = 0; i < v.size(); ++i)
    s.push(v[i]);
  sort_stack(s);
  print_stack(s);
  return 0;
}

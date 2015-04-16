#include "../header/stack.hpp"
#include <iostream>

using namespace std;

template<class T>
struct tower{
  int index;
  stack<T> s;

  void push(const T& x){
    s.push(x);
  }
  void pop(){
    s.pop();
  }
  T top() const{
    return s.top();
  }
  bool empty() const{
    return s.empty();
  }
};

template<class T>
void move(tower<T>& s1, tower<T>& s2){
  T tmp = s1.top();
  s1.pop();
  s2.push(tmp);
  cout << "Move one plate from " << s1.index << " to " << s2.index << endl;
}

template<class T>
void Hanoi(tower<T>& s1, tower<T>& s2, tower<T>& s3, size_t n){
  if (n > 0){
    Hanoi(s1, s3, s2, n - 1);
    move(s1, s3);
    Hanoi(s2, s1, s3, n - 1);
  }
}

int main(){
  tower<int> s1, s2, s3;
  s1.index = 1;
  s2.index = 2;
  s3.index = 3;
  s1.push(3);
  s1.push(2);
  s1.push(1);
  s1.push(0);
  Hanoi(s1, s2, s3, 4);
  cout << "plates in the third tower(from top to bottom)" << endl;
  while(!s3.empty()){
    cout << s3.top() << endl;
    s3.pop();
  }
  return 0;
}

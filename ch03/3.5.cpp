#include "../stl/header/stack.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class myqueue{
public:
  myqueue(){}
  void push(const T& x) {
    m_stack1.push(x);
    m_back = x;
  }
  void pop() {
    if (!m_stack2.empty()){
      m_stack2.pop();
      return;
    }
    if (!m_stack1.empty()){
      while (!m_stack1.empty()){
        m_stack2.push(m_stack1.top());
        m_stack1.pop();
      }
      m_stack2.pop();
      return;
    }
  }
  T front(){
    if (!m_stack2.empty()){
      return m_stack2.top();
    }
    if (!m_stack1.empty()){
      while (!m_stack1.empty()){
        m_stack2.push(m_stack1.top());
        m_stack1.pop();
      }
      return m_stack2.top();
    }
    throw exception();
  }
  T back() const { return m_back; }

private:
  stack<T> m_stack1;
  stack<T> m_stack2;
  T m_back;

};

int main(){
  myqueue<int> q;
  for (int i = 0; i < 10; ++i)
    q.push(i);
  cout << q.front() << endl;
  cout << q.back() << endl;
  q.pop();
  q.pop();
  q.push(11);
  cout << q.front() << endl;
  cout << q.back() << endl;
  return 0;
}

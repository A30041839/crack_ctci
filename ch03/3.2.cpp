#include "../stl/header/stack.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

/* use an additional stack to keep track of the history
 * of minimum elements. When pushing an element into the 
 * stack, compare it with the top of the additional stack,
 * if the top is greater or equal than the element or the 
 * additional stack is empty, push the element to the additional
 * stack. When popping an element, if the popped value is equal
 * to the top of additional stack, then pop the additional stack 
 * as well.
 * */

template<class T>
class MinStack{
public:
  MinStack() {}

  void push(const T& x){
    m_stk.push(x);
    if (m_minstk.empty() or m_minstk.top() >= x)
      m_minstk.push(x);
  }
  void pop(){
    if (!empty()){
      if (m_minstk.top() == m_stk.top())
        m_minstk.pop();
      m_stk.pop();
    }
  }
  bool empty() const{
    return m_stk.empty();
  }
  T top() const{
    if (empty())
      throw exception();
    return m_stk.top();
  }
  T min() const{
    if (empty())
      throw exception();
    return m_minstk.top();
  }

private:
  stack<T> m_stk;
  stack<T> m_minstk;
};

int main(){
  MinStack<int> ms;
  ms.push(1);
  ms.push(2);
  cout << ms.min() << endl;
  ms.push(-1);
  cout << ms.min() << endl;
  ms.push(20);
  ms.push(5);
  cout << ms.min() << endl;
  ms.pop();
  ms.pop();
  ms.pop();
  cout << ms.min() << endl;
  return 0;
}

#include "../stl/header/stack.hpp"
#include "../stl/header/vector.hpp"
#include <iostream>

using namespace std;

template<class T>
class SetofStacks{
public:
  explicit SetofStacks(size_t capacity = 20)
    : m_capacity(capacity), m_count(1){
      m_stacks.push_back(stack<T>());
    }
  
  void push(const T& x){
    if (m_stacks[m_count - 1].size() == m_capacity){
      m_stacks.push_back(stack<T>());
      ++m_count;
    }
    m_stacks[m_count - 1].push(x);
  }

  void pop(){
    m_stacks[m_count - 1].pop();
    if (m_stacks[m_count - 1].empty() and m_count > 1){
      --m_count;
      m_stacks.pop_back();
    }
  }
  
  void pop_at(size_t index){
    if (index <= m_count - 1){
      m_stacks[index].pop();
      if (index < m_count - 1){
        stack<T> _stack;
        while(m_count > index + 1){
          _stack.push(top());
          pop();
        }
        while(!_stack.empty()){
          push(_stack.top());
          _stack.pop();
        }
      }
    }
  }

  T top() const{
    return m_stacks[m_count - 1].top();
  } 
  
  bool empty() const{
    return m_stacks[0].empty();
  }

private:
  size_t m_capacity;
  size_t m_count;
  vector<stack<T> > m_stacks;

};

int main(){
  SetofStacks<int> ss;
  for (int i = 0; i < 60; ++i)
    ss.push(i);
  ss.pop_at(1);
  while (!ss.empty()){
    cout << ss.top() << ",";
    ss.pop();
  }
  cout << endl;
  return 0;
}

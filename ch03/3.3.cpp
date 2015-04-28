#include "../ctci.h"

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

  //the pop_at method operates in a roll-over basis
  void pop_at(size_t index){
    if (index <= m_count - 1){
      m_stacks[index].pop();
      for (size_t i = index + 1; i < m_count; ++i) {
        stack<T> tmp;
        while (!m_stacks[i].empty()) {
          T top = m_stacks[i].top();
          m_stacks[i].pop();
          tmp.push(top);
        }
        T top = tmp.top();
        tmp.pop();
        m_stacks[i - 1].push(top);
        while (!tmp.empty()) {
          T top = tmp.top();
          tmp.pop();
          m_stacks[i].push(top);
        }
      }
      if (m_stacks[m_count - 1].empty() and m_count > 1){
        --m_count;
        m_stacks.pop_back();
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
  SetofStacks<int> ss(5);
  for (int i = 0; i < 11; ++i) {
    ss.push(i);
  }
  ss.pop_at(0);
  while (!ss.empty()){
    cout << ss.top() << ",";
    ss.pop();
  }
  cout << endl;
  return 0;
}

#include "../ctci.h"

using namespace std;

class Hanoi {
private:
  void _move(int from, int to){
    int tmp = m_stk[from].top();
    m_stk[from].pop();
    m_stk[to].push(tmp);
    cout << "Move one plate from " << from << " to " << to << endl;
  }
  
  void _solve(int from, int to, int buffer, int n){
    if (n > 0){
      _solve(from, buffer, to, n - 1);
      _move(from, to);
      _solve(buffer, to, from, n - 1);
    }
  }

  vector<stack<int> > m_stk;
  int m_n;

public:
  explicit Hanoi(int n): m_n(n) {
    m_stk.resize(3);
    for (int i = n; i >= 1; --i) {
      m_stk[0].push(i);
    }
  }

  stack<int>& solve() {
    _solve(0, 2, 1, m_n);
    return m_stk[2];
  };
};

int main(){
  Hanoi hanoi(10);
  cout << "plates in the third tower(from top to bottom)" << endl;
  auto s = hanoi.solve();
  while(!s.empty()){
    cout << s.top() << endl;
    s.pop();
  }
  return 0;
}

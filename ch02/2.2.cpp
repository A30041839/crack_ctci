#include "LinkedList.hpp"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
void find_last_k(LinkedList<T>& ls, size_t k){
  LNode<T>* ptr_slow = ls.head;
  LNode<T>* ptr_fast = ls.head;
  size_t _k = k;
  while (ptr_fast != NULL && _k > 0){
    ptr_fast = ptr_fast->next;
    --_k;
  }
  if (_k > 0){
    cout << "the last " << k << " element doesn't exist!" << endl;
    return;
  }
  while(ptr_fast != NULL){
    ptr_fast = ptr_fast->next;
    ptr_slow = ptr_slow->next;
  }
  cout << "the last " << k << " element is :" << ptr_slow->val << endl;
}

int main(){
  vector<int> vec;
  for (int i = 1; i < 11; ++i)
    vec.push_back(i);
  LinkedList<int> ls(vec);
  ls.print_list();
  find_last_k(ls, 5);
  find_last_k(ls, 12);
  return 0;
}

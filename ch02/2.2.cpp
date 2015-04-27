#include "../header/LinkedList.hpp"
#include "../ctci.h"

using namespace std;

template<class T>
LNode<T>* find_last_k(LinkedList<T>& ls, int k){
  LNode<T>* ptr1 = ls.head;
  for (int i = 0; i < k && ptr1 != nullptr; ++i) {
    ptr1 = ptr1->next;
  }
  if (ptr1 == nullptr) {
    return nullptr;
  }
  LNode<T>* ptr2 = ls.head;
  while (ptr1 != nullptr) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return ptr2;
}

int main(){
  vector<int> vec;
  for (int i = 1; i < 11; ++i) {
    vec.push_back(i);
  }
  LinkedList<int> ls(vec);
  ls.print_list();
  LNode<int>* res = find_last_k(ls, 12);
  if (res != nullptr) {
    cout << res->val << endl;
  }else {
    cout << "no such element!" << endl;
  }
  res = find_last_k(ls, 5);
  if (res != nullptr) {
    cout << res->val << endl;
  }else {
    cout << "no such element!" << endl;
  }
  return 0;
}

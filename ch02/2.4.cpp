#include "LinkedList.hpp"
#include <iostream>
#include <vector>

template<class T>
void partition(LinkedList<T>& ls, T x){
  LNode<T>* ptr1 = ls.head->next;
  LNode<T>* ptr2 = ls.head;
  while (ptr1 != NULL){
    if (ptr1->val < x){
      ptr2 = ptr2->next;
      T tmp = ptr1->val;
      ptr1->val = ptr2->val;
      ptr2->val = tmp;
    }
    ptr1 = ptr1->next;
  }
}

using namespace std;

int main(){
  vector<int> vec = {5, 2, 9, 3, 3, -1, 4, 19, 23, 10, 7, 18};
  LinkedList<int> ls(vec);
  partition(ls, 10);
  ls.print_list();
  partition(ls, 6);
  ls.print_list();
  return 0;
}

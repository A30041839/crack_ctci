#include "../header/LinkedList.hpp"
#include "../ctci.h"

using namespace std;

template<class T>
void partition(LinkedList<T>& ls, T x){
  LNode<T> *l1 = ls.head, *l2 = ls.head->next;
  while (l2 != nullptr) {
    if (l2->val < x) {
      l1 = l1->next;
      swap(l1->val, l2->val);
    }
    l2 = l2->next;
  }
}


int main(){
  vector<int> vec = {5, 2, 9, 3, 3, -1, 4, 19, 23, 10, 7, 18};
  LinkedList<int> ls(vec);
  partition(ls, 10);
  ls.print_list();
  partition(ls, 6);
  ls.print_list();
  return 0;
}

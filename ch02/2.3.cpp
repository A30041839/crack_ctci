#include "../header/LinkedList.hpp"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
void remove_middle(LinkedList<T>& ls, LNode<T>* mid){
  if (mid == nullptr) {
    return;
  }else if (mid->next == nullptr) {
    delete mid;
    ls.head->next = nullptr;
  }else {
    mid->val = mid->next->val;
    LNode<T>* tmp = mid->next;
    mid->next = tmp->next;
    delete tmp;
  }
}

int main(){
  vector<char> vec1 = {'a', 'b', 'c', 'd', 'e'};
  LinkedList<char> ls1(vec1);
  LNode<char>* mid = ls1.head->next->next->next;
  remove_middle(ls1, mid);
  ls1.print_list();
  return 0;
}

#include "LinkedList.hpp"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
void remove_middle(LinkedList<T>& ls){
  LNode<T>* ptr_slow = ls.head;
  LNode<T>* ptr_fast = ls.head;
  LNode<T>* prev = NULL;
  while(ptr_fast->next != NULL and ptr_fast->next->next != NULL){
    ptr_fast = ptr_fast->next->next;
    ptr_slow = ptr_slow->next;
    if (prev == NULL)
      prev = ls.head;
    else
      prev = prev->next;
  }
  if (ptr_fast->next != NULL){
    LNode<T>* tmp = ptr_slow->next;
    ptr_slow->next = tmp->next;
    delete tmp;
  }else{
    prev->next = ptr_slow->next;
    delete ptr_slow;
  }
}

int main(){
  vector<char> vec1 = {'a', 'b', 'c', 'd'};
  LinkedList<char> ls1(vec1);
  vector<char> vec2 = {'a', 'b', 'c', 'd', 'e'};
  LinkedList<char> ls2(vec2);
  remove_middle(ls1);
  remove_middle(ls2);
  ls1.print_list();
  ls2.print_list();
  return 0;
}

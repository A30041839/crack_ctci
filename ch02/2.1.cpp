#include "../header/LinkedList.hpp"
#include "../ctci.h"

using namespace std;

void remove_duplicate1(LinkedList<int>& ls){
  LNode<int>* ptr = ls.head;
  unordered_set<int> s;
  while(ptr->next != NULL){
    if (s.count(ptr->next->val) > 0){
      LNode<int>* tmp = ptr->next;
      ptr->next = tmp->next;
      delete tmp;
    }else{
      s.insert(ptr->next->val);
      ptr = ptr->next;
    }
  }
}

void remove_duplicate2(LinkedList<int>& ls){
  LNode<int>* ptr1 = ls.head->next;
  LNode<int>* ptr2 = NULL;
  while (ptr1 != NULL){
    LNode<int>* prev = ptr1;
    ptr2 = ptr1->next;
    while (ptr2 != NULL){
      if (ptr2->val == ptr1->val){
        prev->next = ptr2->next;
        delete ptr2;
        ptr2 = prev->next;
      }else{
        prev = prev->next;
        ptr2 = ptr2->next;
      }
    }
    ptr1 = ptr1->next;
  }
}

int main(){
  vector<int> vec = { 1, 4, -4, 8, 1, 6, 5, 5, 7, -8, -8 };
  LinkedList<int> ls1(vec);
  ls1.print_list();
  remove_duplicate1(ls1);
  ls1.print_list();
  LinkedList<int> ls2(vec);
  ls2.print_list();
  remove_duplicate2(ls2);
  ls2.print_list();

  return 0;
}

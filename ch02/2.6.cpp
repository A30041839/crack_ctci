#include "LinkedList.hpp"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
void find_loop_entry(LinkedList<T>& ls){
  LNode<T>* ptr_slow = ls.head->next;
  LNode<T>* ptr_fast = ls.head->next;
  int flag = 0;
  while (ptr_fast->next != NULL and ptr_fast->next->next != NULL){
    if (ptr_fast == ptr_slow and ptr_fast != ls.head->next){
      if (flag == 0){
        flag = 1;
        ptr_slow = ls.head->next;
      }else{
        cout << "The loop entry point is : " << ptr_slow->val << endl;
        break;
      }
    }
    ptr_slow = ptr_slow->next;
    if (flag == 0)
      ptr_fast = ptr_fast->next->next;
    else
      ptr_fast = ptr_fast->next;
  }
  if (ptr_fast->next == NULL or ptr_fast->next->next == NULL)
    cout << "The linked list has no loop!" << endl;
}

int main(){
  vector<char> vec1 = {'A', 'B', 'C', 'D', 'E'};
  LinkedList<char> ls1(vec1);
  LNode<char> *p1, *p2, *p;
  p = ls1.head->next;
  for(int i = 0; i < 5; ++i){
    if (i == 2)
      p1 = p;
    if (i == 4)
      p2 = p;
    p = p->next;
  }
  p2->next = p1;
  find_loop_entry(ls1);
  vector<char> vec2 = {'A', 'B', 'C', 'D', 'E'};
  LinkedList<char> ls2(vec2);
  find_loop_entry(ls2);
  return 0;
}

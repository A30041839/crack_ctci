#include "LinkedList.hpp"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void sum1(LinkedList<int>& a, LinkedList<int>& b, LinkedList<int>& c){
  LNode<int>* pa = a.head->next;
  LNode<int>* pb = b.head->next;
  int carry = 0;
  while (pa != NULL and pb != NULL){
    int tmp = carry + pa->val + pb->val;
    if (tmp >= 10){
      carry = 1;
      tmp -= 10;
    }else{
      carry = 0;
    }
    c.insert_to_tail(tmp);
    pa = pa->next;
    pb = pb->next;
  }
  if (pa != NULL){
    while (pa != NULL){
      int tmp = carry + pa->val;
      if (tmp >= 10){
        carry = 1;
        tmp -= 10;
      }else{
        carry = 0;
      }
      c.insert_to_tail(tmp);
      pa = pa->next;
    }
  }
  if (pb != NULL){
    while (pb != NULL){
      int tmp = carry + pb->val;
      if (tmp >= 10){
        carry = 1;
        tmp -= 10;
      }else{
        carry = 0;
      }
      c.insert_to_tail(tmp);
      pb = pb->next;
    }
  }
}

void sum2(LinkedList<int>& a, LinkedList<int>& b, LinkedList<int>& c){
  stack<int> s1, s2;
  LNode<int>* p = a.head->next;
  while (p != NULL){
    s1.push(p->val);
    p = p->next;
  }
  p = b.head->next;
  while (p != NULL){
    s2.push(p->val);
    p = p->next;
  }
  int carry = 0;
  stack<int> s3;
  while (!s1.empty() and !s2.empty()){
    int tmp = carry + s1.top() + s2.top();
    if (tmp >= 10){
      carry = 1;
      tmp -= 10;
    }else{
      carry = 0;
    }
    s3.push(tmp);
    s1.pop();
    s2.pop();
  }
  if (!s1.empty()){
    while (!s1.empty()){
      int tmp = carry + s1.top();
      if (tmp >= 10){
        carry = 1;
        tmp -= 10;
      }else{
        carry = 0;
      }
      s3.push(tmp);
      s1.pop();
    }
  }
  if (!s2.empty()){
    while (!s2.empty()){
      int tmp = carry + s2.top();
      if (tmp >= 10){
        carry = 1;
        tmp -= 10;
      }else{
        carry = 0;
      }
      s3.push(tmp);
      s2.pop();
    }
  }
  while (!s3.empty()){
    c.insert_to_tail(s3.top());
    s3.pop();
  }

}

int main(){
  vector<int> a = {7, 1, 6};
  vector<int> b = {5, 9, 2};
  LinkedList<int> s11;
  LinkedList<int> la(a);
  LinkedList<int> lb(b);
  sum1(la, lb, s11);
  s11.print_list();
  vector<int> c = {1, 2, 6, 6, 9, 1};
  LinkedList<int> s12;
  LinkedList<int> lc(c);
  sum1(la, lc, s12);
  s12.print_list();

  vector<int> a1 = {6, 1, 7};
  vector<int> b1 = {2, 9, 5};
  LinkedList<int> s21;
  LinkedList<int> la1(a1);
  LinkedList<int> lb1(b1);
  sum2(la1, lb1, s21);
  s21.print_list();
  vector<int> c1 = {1, 9, 6, 6, 2, 1};
  LinkedList<int> s22;
  LinkedList<int> lc1(c1);
  sum2(la1, lc1, s22);
  s22.print_list();

  return 0;
}

#include "../header/LinkedList.hpp"
#include "../ctci.h"

using namespace std;

template<class T>
bool is_palindrome1(LinkedList<T>& ls){
  vector<T> vec;
  LNode<T>* ptr = ls.head->next;
  while(ptr != NULL){
    vec.push_back(ptr->val);
    ptr = ptr->next;
  }
  for (size_t i = 0, j = vec.size() - 1; i < j; ++i, --j){
    if (vec[i] != vec[j])
      return false;
  }
  return true;
}

//recursive solution
//time complexity: O(n)
//space complexity: O(n), the recursive call enters n/2 times
template<class T>
bool is_palindrome2(LinkedList<T>& ls) {
  int len = 0;
  LNode<T>* ptr = ls.head;
  while (ptr->next) {
    len++;
    ptr = ptr->next;
  }
  return _is_palindrome2(ls.head->next, len, ptr);
} 

template<class T>
bool _is_palindrome2(LNode<T>* head, int len, LNode<T>*& next) {
  if (len == 0) {
    next = head;
    return true;
  }
  if (len == 1) {
    next = head->next;
    return true;
  }
  if (_is_palindrome2(head->next, len - 2, next) and head->val == next->val) {
      next = next->next;
      return true;
    }
  return false;
}

int main(){
  vector<char> vec1 = { 'a', 'b', 'c', 'b', 'a' };
  vector<char> vec2 = { 'a', 'b', 'k', 'a'};
  LinkedList<char> ls1(vec1);
  LinkedList<char> ls2(vec2);
  if (is_palindrome2(ls1))
    cout << "The list is palindrome." << endl;
  else
    cout << "The list is not palindrome." << endl;
}



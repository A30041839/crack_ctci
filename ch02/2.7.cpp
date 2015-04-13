#include "../header/LinkedList.hpp"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
bool is_palindrome(LinkedList<T>& ls){
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

int main(){
  vector<char> vec1 = { 'a', 'b', 'c', 'b', 'a' };
  vector<char> vec2 = { 'a', 'b', 'f', 'a'};
  LinkedList<char> ls1(vec1);
  LinkedList<char> ls2(vec2);
  if (is_palindrome(ls1))
    cout << "The list is palindrome." << endl;
  else
    cout << "The list is not palindrome." << endl;
}



#include "../ctci.h"

using namespace std;

void merge(vector<int>& a, vector<int>& b, int na){
  int cur = na + b.size() - 1;
  int i = na - 1;
  int j = b.size() - 1;
  while (i >= 0 and j >= 0){
    if (a[i] <= b[j]){
      a[cur--] = b[j--];
    }else{
      a[cur--] = a[i--];
    }
  }
  while (j >= 0){
    a[cur--] = b[j--];
  }
}

int main(){
  vector<int> a = {1, 3, 7, 8, 10, 11, 15, 0, 0, 0, 0};
  vector<int> b = {-1, 2, 3, 9};
  merge(a, b, 7);
  print_array(a);
  return 0;
}

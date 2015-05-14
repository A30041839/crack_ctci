#include "../ctci.h"

using namespace std;

int find(vector<int>& vec, int n){
  int low = 0;
  int high = vec.size() - 1;
  while (low <= high){
    int mid = (low + high) / 2;
    if (vec[mid] == n){
      return mid;
    }
    if (vec[mid] < vec[low]){
      //the right half is ordered
      if (n > vec[high] or n < vec[mid]){
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }else{
      //the left half is ordered
      if (n < vec[low] or n > vec[mid]){
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
  }
  return -1;
}

int main(){
  vector<int> vec = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
  cout << find(vec, 5) << endl;
  cout << find(vec, 15) << endl;
  cout << find(vec, 25) << endl;
  cout << find(vec, 1) << endl;
  cout << find(vec, 14) << endl;
  cout << find(vec, 19) << endl;
  cout << find(vec, 100) << endl;
  return 0;
}

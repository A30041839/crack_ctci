#include "../ctci.h"

using namespace std;

int findMagicIndex1(vector<int>& array){
  int low = 0;
  int high = array.size() - 1;
  while (low <= high){
    int mid = (low + high) / 2;
    if (array[mid] == mid){
      return mid;
    }else if (array[mid] > mid){
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return -1;
}

int _findMagicIndex2(vector<int>& array, int low, int high){
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (array[mid] == mid) {
    return mid;
  }
  int l = _findMagicIndex2(array, low, min(mid - 1, array[mid]));
  if (l != -1) {
    return l;
  }
  return _findMagicIndex2(array, max(mid + 1, array[mid]), high);
}

int findMagicIndex2(vector<int>& array) {
  return _findMagicIndex2(array, 0, array.size() - 1);
}

int main(){
  vector<int> vec = {-1,0,1,2,3,4,7,8,9,9};
  //cout << findMagicIndex1(vec) << endl;
  cout << findMagicIndex2(vec) << endl;
  return 0;
}

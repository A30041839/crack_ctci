#include "../ctci.h"

using namespace std;

int findMagicIndex2(vector<int>& array, int low, int high){
  if (low > high){
    return -1;
  }
  int mid = (low + high) / 2;
  if (array[mid] == mid){
    return mid;
  }else if (array[mid] > high){
    return findMagicIndex2(array, low, mid - 1);
  }else if (array[mid] < low){
    return findMagicIndex2(array, mid + 1, high);
  }else{
    int a = findMagicIndex2(array, low, mid - 1);
    if (a != -1){
      return a;
    }
    a = findMagicIndex2(array, mid + 1, high);
    if (a != -1){
      return a;
    }
    return -1;
  }
}

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

int main(){
  vector<int> vec = {-1,0,1,2,3,4,7,8,9,9};
  //cout << findMagicIndex1(vec) << endl;
  cout << findMagicIndex2(vec, 0, 9) << endl;
  return 0;
}

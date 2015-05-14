#include "../ctci.h"

using namespace std;

int find(vector<string>& vec, string str){
  int low = 0;
  int high = vec.size() - 1;
  while (low <= high){
    int mid = (low + high) / 2;
    if (vec[mid].empty()) {
      int left = mid - 1, right = mid + 1;
      while (true) {
        if (left < low and right > high) {
          return -1;
        }
        if (left >= low and !vec[left].empty()) {
          mid = left;
          break;
        }
        if (right <= high and !vec[right].empty()) {
          mid = right;
          break;
        }
        left--;
        right++;
      }
    }
    if (vec[mid] == str) {
      return mid;
    }else if (vec[mid] < str) {
      low = mid + 1;
    }else {
      high = mid - 1;
    }
  }
  return -1;
}


int main(){
  vector<string> vec = {"at", "", "", "", "ball", "", "", "car", "" , "", "dad", "", ""};
  cout << find(vec, "dd") << endl;
  cout << find(vec, "at") << endl;
  cout << find(vec, "ball") << endl;
  cout << find(vec, "car") << endl;
  cout << find(vec, "dad") << endl;
  return 0;
}

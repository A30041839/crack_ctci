#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find(vector<string>& vec, string s){
  int low = 0;
  int high = vec.size() - 1;
  while (low <= high){
    int mid = (low + high) / 2;
    if (!vec[mid].empty()){
      if (vec[mid] == s){
        return mid;
      }
      if (vec[mid] < s){
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }else{
      int i = mid - 1;
      int j = mid + 1;
      bool flag = true;
      while (i >= low and j <= high){
        if (!vec[i].empty()){
          if (vec[i] == s){
            return i;
          }else if (vec[i] > s){
            high = i - 1;
            flag = false;
            break;
          }
        }
        if (!vec[j].empty()){
          if (vec[j] == s){
            return j;
          }else if (vec[j] < s){
            low = j + 1;
            flag = false;
            break;
          }
        }
        i--;
        j++;
      }
      if (flag){
        return -1;
      }
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

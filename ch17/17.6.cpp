#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortRange1(vector<int>& vec){
  vector<int> vec2 = vec;
  sort(vec2.begin(), vec2.end());
  int start = 0, end = vec2.size() - 1;
  while (vec2[start] == vec[start] and start <= end){
    start++;
  }
  while (vec2[end] == vec[end] and start <= end){
    end--;
  }
  if (start < end){
    printf("min sort range is (%d, %d)\n", start, end);
  }else{
    printf("The array is already sorted.\n");
  }
}

int main(){
  vector<int> vec = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 };
  sortRange1(vec);
  return 0;
}

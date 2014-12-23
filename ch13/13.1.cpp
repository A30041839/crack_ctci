#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printTail(const char* filepath, vector<string>& tail, int n){
  tail.resize(n);
  int index = 0;
  ifstream fin(filepath);
  if (!fin){
    cerr << "The input file cannot be opened!" << endl;
    return;
  }
  string str;
  while(getline(fin, str)){
    tail[index % n] = str;
    index++;
  }
  fin.close();
  index %= n;
  vector<string> tmp;
  int k = 0;
  while(index--){
    tmp.push_back(tail[k++]);
  }
  for (int i = 0; i < tail.size(); ++i){
    if (i < (tail.size() - k)){
      tail[i] = tail[i + k];
    }else{
      tail[i] = tmp[i + k - tail.size()];
    }
  } 
}

int main(){
  vector<string> tail;
  const char* fpath = "lanjie_1020_to_1203_v2.cut";
  printTail(fpath, tail, 10);
  for (int i = 0; i < tail.size(); ++i){
    cout << tail[i] << endl;
  }
  return 0;
}

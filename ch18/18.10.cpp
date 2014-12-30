#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool dist(string a, string b){
  int k = 0;
  if (a.length() != b.length()){
    return false;
  }
  for (int i = 0; i < a.length(); ++i){
    if (a[i] != b[i]){
      k++;
    }
  }
  return k == 1;
}

bool dfs(map<int, vector<int> >& map, int from, int to, vector<int>& path, vector<int>& visited){
  if (visited[from] == 0){
    path.push_back(from);
    visited[from] = 1;
    if (from == to){
      return true;
    }
    for (int k : map[from]){
      if (dfs(map, k, to, path, visited)){
        return true;
      }
    }
    visited[from] = 0;
    path.pop_back();
  }
  return false;
}

void transform(vector<string>& list, string from, string to){
  vector<string> vec;
  int id1, id2;
  for (int i = 0; i < list.size(); ++i){
    if (list[i].length() == from.length()){
      vec.push_back(list[i]);
    }
  }
  map<int, vector<int> > map;
  for (int i = 0; i < vec.size(); ++i){
    if (vec[i] == from){
      id1 = i;
    }
    if (vec[i] == to){
      id2 = i;
    }
    for (int j = i + 1; j < vec.size(); ++j){
      if (dist(vec[i], vec[j])){
        map[i].push_back(j);
        map[j].push_back(i);
      }
    }
  }
  vector<int> path;
  vector<int> visited(vec.size(), 0);
  if (dfs(map, id1, id2, path, visited)){
    for (int i = 0; i < path.size() - 1; ++i){
      cout << vec[path[i]] << "->";
    }
    cout << vec[path.back()] << endl;
  }else{
    printf("No transform could be found!\n");
  }
}

int main(){
  vector<string> dictionary = {"YOU", "COOL", "DAMP", "ABCD", "LAMP", "LIMP", "FUCK", "LIME", "LIKE", "HELLO", "FACEBOOK"};
  transform(dictionary, "DAMP", "LIKE");
  return 0;
}

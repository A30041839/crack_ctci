#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person{
  explicit person(int hight, int weight)
    : h(hight), w(weight) {}
  bool operator<(const person& p) const{
    return h < p.h and w < p.w;
  }
  void to_string() const{
    printf("(%d, %d)\n", h, w);
  }

  int h;
  int w;
};

int maxNumofPerson(vector<person>& persons, vector<person>& resvec){
  sort(persons.begin(), persons.end());
  vector<int> dp(persons.size(), 0);
  vector<int> prevs(persons.size(), 0);
  int res = -1;
  for(int i = persons.size() - 1; i >= 0; --i){
    int prev = i;
    for (int j = i + 1; j < persons.size(); ++j){
      if (persons[i] < persons[j]){
        if (dp[j] > dp[i]){
          dp[i] = dp[j];
          prev = j;
        }
      }
    }
    dp[i] += 1;
    prevs[i] = prev;
    res = max(dp[i], res);
  }
  int k = 0;
  while(dp[k] != res){
    k++;
  }
  while(prevs[k] != k){
    resvec.push_back(persons[k]);
    k = prevs[k];
  }
  resvec.push_back(persons[k]);
  return res;
}

int main(){
  vector<person> persons;
  vector<person> resvec;
  persons.push_back(person(65, 100));
  persons.push_back(person(70, 150));
  persons.push_back(person(56, 90));
  persons.push_back(person(75, 190));
  persons.push_back(person(60, 95));
  persons.push_back(person(68, 110));
  persons.push_back(person(60, 101));
  persons.push_back(person(50, 70));
  cout << "Max number of person:" << maxNumofPerson(persons, resvec) << endl;
  for (int i = 0; i < resvec.size(); ++i){
    resvec[i].to_string();
  }

  return 0;
}

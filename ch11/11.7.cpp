#include "../ctci.h"

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

int maxNumofPerson1(vector<person>& persons){
  if (persons.empty()) {
    return 0;
  }
  sort(persons.begin(), persons.end());
  vector<int> dp(persons.size(), 1);
  int res = 1;
  for (int i = 1; i < persons.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (persons[j] < persons[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  return res;
}

int main(){
  vector<person> persons;
  persons.push_back(person(65, 100));
  persons.push_back(person(70, 150));
  persons.push_back(person(56, 90));
  persons.push_back(person(75, 190));
  persons.push_back(person(60, 95));
  persons.push_back(person(68, 110));
  persons.push_back(person(60, 101));
  persons.push_back(person(50, 70));
  cout << "Max number of person:" << maxNumofPerson1(persons) << endl;

  return 0;
}

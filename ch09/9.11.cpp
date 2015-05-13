#include "../ctci.h"

using namespace std;

map<char, vector<pair<bool, bool>>> true_mp = {{'&', {{true, true}}}, {'|', {{true, true}, {true, false}, {false, true}}}, {'^', {{true, false}, {false, true}}}};
map<char, vector<pair<bool, bool>>> false_mp = {{'&', {{false, false}, {false, true}, {true, false}}}, {'|', {{false, false}}}, {'^', {{true, true}, {false, false}}}};

int num_of_ways_boolean_exp_recurse(string exp, bool eval) {
  if (exp == "1") {
    return eval ? 1 : 0;
  }else if (exp == "0") {
    return eval ? 0 : 1;
  }
  int res = 0;
  for (int i = 1; i < exp.size(); i += 2) {
    string exp1 = exp.substr(0, i);
    string exp2 = exp.substr(i + 1);
    auto& mp = eval ? true_mp : false_mp;
    for (auto it : mp[exp[i]]) {
      res += num_of_ways_boolean_exp_recurse(exp1, it.first) *
        num_of_ways_boolean_exp_recurse(exp2, it.second);
    }
  }
  return res;
}

int num_of_ways_boolean_exp_dp(string exp, bool eval, map<string, map<bool, int>>& dp) {
  if (dp.count(exp) and dp[exp].count(eval)) {
    return dp[exp][eval];
  }
  if (exp == "1") {
    return eval ? 1 : 0;
  }else if (exp == "0") {
    return eval ? 0 : 1;
  }
  int res = 0;
  for (int i = 1; i < exp.size(); i += 2) {
    string exp1 = exp.substr(0, i);
    string exp2 = exp.substr(i + 1);
    auto& mp = eval ? true_mp : false_mp;
    for (auto it : mp[exp[i]]) {
      res += num_of_ways_boolean_exp_dp(exp1, it.first, dp) *
        num_of_ways_boolean_exp_dp(exp2, it.second, dp);
    }
  }
  dp[exp][eval] = res;
  return res;
}

int main() {
  string exp("1^0|0|1");
  map<string, map<bool, int>> dp;
  cout << num_of_ways_boolean_exp_dp(exp, true, dp) << endl;
  return 0;
}

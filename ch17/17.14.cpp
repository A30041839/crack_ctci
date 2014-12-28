#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

string uppercase(string s){
  for (int i = 0; i < s.length(); ++i){
    s[i] = toupper(s[i]);
  }
  return s;
}

string parse(string input, unordered_set<string>& dic){
  input = uppercase(input);
  for (string term : dic){
    size_t pos = 0;
    string _term = uppercase(term);
    while (input.find(_term, pos) != string::npos){
      pos = input.find(_term);
      string s1 = input[pos - 1] == ' ' ? "" : " ";
      string s2 = input[pos + _term.length()] == ' ' ? "" : " ";
      input = input.replace(pos, _term.length(), s1 + term + s2);
      pos += _term.length() + s1.length() + s2.length();
    }
  }
  return input;
}

int main(){
  unordered_set<string> dic;
  dic.insert("looked");
  dic.insert("just");
  dic.insert("like");
  dic.insert("her");
  dic.insert("brother");
  dic.insert("you");

  string input = "jesslookedjustliketimherbrother";
  cout << parse(input, dic) << endl;
  return 0;
}

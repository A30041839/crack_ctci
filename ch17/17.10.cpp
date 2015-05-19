#include "../ctci.h"

using namespace std;

string compressXML(string input){
  unordered_map<string, string> map;
  map["family"] = "1 ";
  map["person"] = "2 ";
  map["firstName"] = "3 ";
  map["lastName"] = "4 ";
  map["state"] = "5 ";

  string res = "";
  string str = "";
  string tag = "";
  bool f = false;
  for (int i = 0; i < input.length(); ++i){
    char c = input[i];
    if (c != ' ' and c != '<' and c != '>' and c != '/' and c != '"' and  c != '='){
      if (tag != ""){
        if (tag == "</"){
          res += "0 ";
          f = true;
        }else{
          res += " ";
        }
        tag = "";
      }
      if (!f){
        str += c;
      }
    }else{
      if (str != ""){
        if (map.count(str) != 0){
          res += map[str];
        }else{
          res += str + " ";
        }
        str = "";
      }
      if (c == '>'){
        if (f == false){
          res += "0 ";
        }else{
          f = false;
          continue;
        }
      }
      tag += c;
    }
  }
  return res;
}

int main(){
  string input = "<family lastName=\"McDowell\" state=\"CA\"><person firstName=\"Gayle\">Some Message</person></family>";
  cout << compressXML(input) << endl;
  return 0;
}

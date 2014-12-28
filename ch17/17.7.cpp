#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

map<long, string> mp;

void init(){
  mp[10000000000] = "billion";
  mp[1000000] = "million";
  mp[1000] = "thousand";
  mp[100] = "hundred";
  mp[90] = "ninety";
  mp[80] = "eighty";
  mp[70] = "seventy";
  mp[60] = "sixty";
  mp[50] = "fifty";
  mp[40] = "forty";
  mp[30] = "thirty";
  mp[20] = "twenty";
  mp[19] = "nineteen";
  mp[18] = "eighteen";
  mp[17] = "seventeen";
  mp[16] = "sixteen";
  mp[15] = "fifteen";
  mp[14] = "fourteen";
  mp[13] = "thirteen";
  mp[12] = "twelve";
  mp[11] = "eleven";
  mp[10] = "ten";
  mp[9] = "nine";
  mp[8] = "eight";
  mp[7] = "seven";
  mp[6] = "six";
  mp[5] = "five";
  mp[4] = "four";
  mp[3] = "three";
  mp[2] = "two";
  mp[1] = "one";
  mp[0] = "zero"; 
}

void _engParaphrase(long n, bool &f, string& res){
  if (n / 10000000000 > 0){
    res += mp[n / 10000000000] + " " + mp[10000000000] + " ";
    if (f){
      res += ",";
      f = false;
    }
  }
  n %= 10000000000;
  if (n / 1000000 > 0){
    _engParaphrase(n / 1000000, f, res);
    res += " " + mp[1000000] + " ";
    if (f){
      res += ",";
      f = false;
    } 
  }
  n %= 1000000;
  if (n / 1000 > 0){
    _engParaphrase(n / 1000, f, res);
    res += " " + mp[1000] + " ";
    if (f){
      res += ",";
      f = false;
    }
  }
  n %= 1000;
  if (n / 100 > 0){
    res += mp[n / 100] + " " + mp[100] + " ";
  }
  n %= 100;
  if (n > 0 and n < 20){
    res += mp[n];
    return;
  }
  if (n / 10 > 0){
    res += mp[n - n % 10] + " ";
  }
  n %= 10;
  if (n > 0 or (n == 0 and res == "")){
    res += mp[n];
  }
}

string engParaphrase(long n){
  string res = "";
  bool f = true;
  _engParaphrase(n, f, res);
  return res;
} 

int main(){
 init();
 cout << engParaphrase(0) << endl;
 cout << engParaphrase(1) << endl;
 cout << engParaphrase(12) << endl;
 cout << engParaphrase(634) << endl;
 cout << engParaphrase(1239) << endl;
 cout << engParaphrase(62981) << endl;
 cout << engParaphrase(490091) << endl;
 cout << engParaphrase(23900123) << endl;
 cout << engParaphrase(42912300321) << endl;
 return 0;
}

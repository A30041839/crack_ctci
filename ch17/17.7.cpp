#include "../ctci.h"

using namespace std;

vector<string> ones = {"one", "two", "three", "four", "five", "six", "seven",
                       "eight", "nine"};
vector<string> teens = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                        "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                       "eighty", "ninty"};
vector<string> bigs = {"", "thousand", "million", "billion"};

string numtoString100(long num) {
  string res;
  if (num / 100 > 0) {
    res += ones[num / 100 - 1] + " hundred ";
    num %= 100;
  }
  if (num >= 11 and num <= 19) {
    res += teens[num - 11] + " ";
    num = 0;
  }else if (num == 10 or num >= 20) {
    res += tens[num / 10 - 1] + " ";
    num %= 10;
  }
  if (num > 0) {
    res += ones[num - 1] + " ";
  }
  return res;
}

string numtoString(long num) {
  if (num == 0) {
    return "zero";
  }else if (num < 0) {
    return "negative " + numtoString(-1 * num);
  }
  string res;
  int i = 0;
  while (num > 0) {
    if (num % 1000 > 0) {
      res = numtoString100(num % 1000) + bigs[i++] + " " + res;
    }
    num /= 1000;
  }
  return res;
}

int main(){
 cout << numtoString(0) << endl;
 cout << numtoString(1) << endl;
 cout << numtoString(12) << endl;
 cout << numtoString(110) << endl;
 cout << numtoString(634) << endl;
 cout << numtoString(1239) << endl;
 cout << numtoString(62981) << endl;
 cout << numtoString(490091) << endl;
 cout << numtoString(23900123) << endl;
 cout << numtoString(42912300321) << endl;
 return 0;
}

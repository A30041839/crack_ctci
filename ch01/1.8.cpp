#include "../ctci.h"

using namespace std;

bool is_rotation(string& s1, string& s2){
  if (s1.empty() or s2.empty()) {
    return false;
  }
  if (s1.size() != s2.size()) {
    return false;
  }
  string s = s1 + s1;
  return s.find(s2, 0) != string::npos;
}


int main(){
	string s1("waterbottle");
	string s2("erbottlewat");
	if (is_rotation(s1, s2))
		cout << s1 << " is rotation of " << s2 << endl;
	else
		cout << s1 << " is not rotation of " << s2 << endl;
	return 0;
}

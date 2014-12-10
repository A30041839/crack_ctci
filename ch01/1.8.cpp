#include<iostream>
#include<string>

using namespace std;

bool is_rotation(string& s1, string& s2){
	if (s1.length() == 0 || s2.length() == 0) return false;
	if (s1.length() != s2.length()) return false;
	int pos = -1;
	for (size_t i = 0, j = 0; i < s1.length(); ++i){
		if (s1[i] == s2[j]){
			++j;
			if (pos == -1) 
				pos = i;
		}else{
			if (pos != -1)
				return false;
		}
	}
	return s2.find(s1.substr(0, pos)) != string::npos;
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

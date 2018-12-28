#include<iostream>

using namespace std;

int main (){
	string s,ans="";
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'))
			ans += s[i];
	}
	cout << ans << endl;
	return 0;
}
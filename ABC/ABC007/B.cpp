#include <iostream>

using namespace std;

int main(){
	string s,ans;
	cin >> s;
	if(s.compare("a")==0){
		cout << -1 << endl;
		return 0;
	}
	else if(s.length() > 1)ans = string(s.length()-1, 'a');
	else ans = 'a';
	cout << ans << endl;
	return 0;
}
#include <vector>
#include<iostream>
#include<string>

using namespace std;

int main(void){
	string s;
	int ans = 0;
	cin >> s;
	for(int i=0; i< s.length(); i++){
		if(s[i] == 'o') ans++;
	}
	if(ans >= 8 - (15 - int(s.length())))cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

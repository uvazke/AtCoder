#include<iostream>

using namespace std;

int main(){
	string s[4][4];
	for(int i=0; i<4;i++){
		cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3];
	}
	for(int i=3; i>=0;i--){
		cout << s[i][3]<< " " << s[i][2] << " " << s[i][1] << " " << s[i][0] << endl;
	}

	return 0;
}
#include<iostream>

using namespace std;
int main(){
	string s1,s2;
	cin >> s1;
	cin >> s2;
	for(int i=0;i<s1.length();i++){
		if(s1[i] != '@'){
			if(s2[i] != '@' && s2[i] != s1[i]){
				cout << "You will lose" << endl;
				return 0;
			}else if(s2[i] == '@' && !(s1[i] == 'a'||s1[i] == 't'||s1[i] == 'c'||s1[i] == 'o'||s1[i] == 'd'||s1[i] == 'e'||s1[i] == 'r')){
				cout << "You will lose" << endl;
				return 0;
			}
		}else{
			if(s2[i] != '@' && !(s2[i] == 'a'||s2[i] == 't'||s2[i] == 'c'||s2[i] == 'o'||s2[i] == 'd'||s2[i] == 'e'||s2[i] == 'r')){
				cout << "You will lose" << endl;
				return 0;
			}
		}
	}
	cout << "You can win" << endl; 
	return 0;
}
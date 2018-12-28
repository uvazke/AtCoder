#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N,num[4]={};
	string s;
	cin >> N;
	cin >> s;
	for(int i=0;i<s.length();i++){
		num[int(s[i])-48-1]++;
	}
	cout << max(max(max(num[0],num[1]),num[2]),num[3]) << " " << min(min(min(num[0],num[1]),num[2]),num[3])  << endl;

	return 0;
}
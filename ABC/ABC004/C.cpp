#include<iostream>

using namespace std;

int main(){
	int N,k,l,m;
	cin >> N;
	k = N%30;
	l = k%5;
	m = k/5;
	string a = "123456";
	char tmp;
	for(int i=0;i<m;i++){
		for(int j=0;j<5;j++){
			tmp = a[j];
			a[j] = a[j+1];
			a[j+1] = tmp;
		}
	}
	for(int j=0;j<l;j++){
		tmp = a[j];
		a[j] = a[j+1];
		a[j+1] = tmp;
	}
	cout << a << endl;
	return 0;
}
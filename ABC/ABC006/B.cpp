#include<iostream>

using namespace std;
int a[1000001];

int tribonacciDevBy(int n, int num){
	for(int i=3;i<n;i++){
		a[i] = (a[i-1] + a[i-2] + a[i-3])%num;

	}
	return a[n-1];
}
int main(){
	int n,ans;
	cin >> n;
	a[0] = 0;
	a[1] = 0;
	a[2] = 1;
	ans = tribonacciDevBy(n,10007);
	cout << ans << endl;
	return 0;
}
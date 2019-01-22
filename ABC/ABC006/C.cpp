#include<iostream>

using namespace std;

int main(){
	int N,M,a,b,c;
	cin >> N >> M;
	if(M - 2*N > 2*N || M - 2*N < 0){
		cout << "-1 -1 -1" << endl;
		return 0;
	}
	a = N - (M-2*N)/2 - (M-2*N)%2;
	b = (M-2*N)%2;
	c = (M-2*N)/2;
	cout << a << " " << b << " " << c << endl;
	return 0;
}
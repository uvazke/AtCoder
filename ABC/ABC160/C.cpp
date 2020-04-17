#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include<string>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	int K,N,A[200000],i,ans,tmp,m=0;
	cin >> K >> N;
	myfor(i,N){
		cin >> A[i];
	}
	m = K - (A[N-1] - A[0]);
	myforFL(i,0,N-1){
		m = max(m, A[i+1]-A[i]);
	}

	ans = K - m;
	cout << ans << endl;
	return 0;
}
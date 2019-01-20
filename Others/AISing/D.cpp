#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>
#include <iterator>

using namespace std;
long A[100000];
long sumO[100000],sumE[100000],sum[100000];
//TODO two way search
int solve(long X, int N){
	int ub = N+1,lb = 1,t;
	t = (ub + lb)/2;
	while(ub - lb >1){
		if(abs(A[N-t]-X) > abs(A[N-(t+1)/2]-X)){
			ub = t;
		}else{
			lb = t;
		}
		t = (ub+lb)/2;
	}
	// for(int i=1;i<N+1;i++){
	// 	if(abs(A[N-i]-X) > abs(A[N-(i+1)/2]-X)) return i-1;
	// }
	return t;
}

void calcSum(int N){
	sumE[0] = A[0];
	sumO[0] = 0;
	sum[0] = A[0];
	for(int i=1;i<N;i++){
		sum[i] = sum[i-1]+A[i];
		sumE[i] = sumE[i-1] + (i%2 == 0 ? A[i] : 0);
		sumO[i] = sumO[i-1] + (i%2 == 1 ? A[i] : 0); 
	}
}

int main(void){
	int N,Q;
	long X[100000];
	cin >> N >> Q;
	for(int i=0;i < N;i++){
		cin >> A[i];
	}
	calcSum(N);

	for(int i=0;i < Q;i++){
		cin >> X[i];
	}
	for(int i=0;i < Q;i++){
		int a = solve(X[i],N);
		long sum1 = sum[N-1] - sum[N -(a+1)/2 -1];
		long sum2;
		if(N!=a){
			if(N%2 == 0)sum2 = sumO[N - a - 1];
			else sum2 = sumE[N - a - 1];
		}else{
			sum2 = 0;
		}
		// for(int j=N -((a+1)/2)*2 -1;j>=0;j-=2){
		// 	sum2 += A[j];
		// }
		cout << sum1 + sum2 << endl;
	}
	
	return 0;
}
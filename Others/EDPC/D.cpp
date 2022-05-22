#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define myforInv(i,N) for(i=N;i>=0;i--)
#define myforFLInv(i,f,l) for(i=f;i>l;i--)

using namespace std;
int main(){
	long N,W,i,j;
	long w[100],v[100],dp[100001]={};

	cin >> N >> W;
	myfor(i,N){
		cin >> w[i]>>v[i];
	}
	myfor(i,N)myforFLInv(j,W,w[i]-1){
		dp[j] = max(dp[j-w[i]] + v[i],dp[j]);
	}
	cout << dp[W] << endl;
	return 0;
}

int main2(){
	int N,W,i,j;
	long w[100],v[100],dp[101][100001]={};

	cin >> N >> W;
	myfor(i,N){
		cin >> w[i]>>v[i];
	}

	myfor(i,N+1)myfor(j,W+1){
		if(j-w[i]>=0)dp[i+1][j] = max(dp[i][j-w[i]] + v[i],dp[i][j]);
		else dp[i+1][j] = dp[i][j];
	}
	cout << dp[N][W] << endl;
	return 0;
}


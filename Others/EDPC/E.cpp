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
#define MAXVALUE 100*1000
#define INF pow(10,16)
using namespace std;

int main(){
	long N,W,i,j;
	long w[100],v[100],dp[MAXVALUE+1];

	cin >> N >> W;
	myfor(i,N){
		cin >> w[i]>>v[i];
	}
	myfor(j,MAXVALUE+1)dp[j] = INF;
	myfor(i,N)myforInv(j,MAXVALUE){
		if(j-v[i] == 0)dp[j] = min(dp[j],w[i]);
		else if (j-v[i] > 0)dp[j] = min(dp[j-v[i]] + w[i],dp[j]);
	}
	myforInv(i,MAXVALUE){
		if(dp[i] <= W){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
int main2(){
	long N,W,i,j;
	long w[100],v[100],dp[101][MAXVALUE+1];

	cin >> N >> W;
	myfor(i,N){
		cin >> w[i]>>v[i];
	}
	myfor(i,N)myfor(j,MAXVALUE+1)dp[i][j] = INF;
	myfor(i,N)myfor(j,MAXVALUE+1){
		if(j-v[i] == 0)dp[i+1][j] = w[i];
		else if (j-v[i] > 0 && dp[i][j-v[i]] != 0)dp[i+1][j] = min(dp[i][j-v[i]] + w[i],dp[i][j]);
		else dp[i+1][j] = dp[i][j];
	}
	myforInv(i,MAXVALUE+1){
		if(dp[N][i] <= W){
			cout << i << endl;
			break;
		}
	}
	return 0;
}


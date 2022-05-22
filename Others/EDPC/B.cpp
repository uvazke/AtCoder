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

using namespace std;

int main(){
	int N,K,i,j;
	long dp[100001]={},h[100001],minCost;

	cin >> N >> K;
	myforFL(i,1,N+1){
		cin >> h[i];
	}
	dp[2] = abs(h[2]-h[1])+dp[1];
	myforFL(i,3,N+1){
		minCost = abs(h[i]-h[i-1])+dp[i-1];
		myforFL(j,2,K+1){
			if(i - j < 1)break;
			minCost = min(abs(h[i]-h[i-j])+dp[i-j],minCost);
		}
		dp[i] = minCost;
	}
	cout << dp[N] << endl;
	return 0;
}
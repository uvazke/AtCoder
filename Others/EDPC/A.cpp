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
	int N,h[100001],i;
	long dp[100001]={};

	cin >> N;
	myforFL(i,1,N+1){
		cin >> h[i];
	}
	dp[2] = abs(h[2]-h[1])+dp[1];
	myforFL(i,3,N+1){
		dp[i] = min(abs(h[i]-h[i-1])+dp[i-1],abs(h[i]-h[i-2])+dp[i-2]);
	}
	cout << dp[N] << endl;
	return 0;
}
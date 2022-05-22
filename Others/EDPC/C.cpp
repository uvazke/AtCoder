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
	int N,i,j;
	long a[100000],b[100000],c[100000],dp[100000][3] = {};

	cin >> N ;
	myfor(i,N){
		cin >> a[i]>>b[i]>>c[i];
	}
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0]; 
	myforFL(i,1,N){
		dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][2] + a[i]);
		dp[i][1] = max(dp[i-1][0] + b[i], dp[i-1][2] + b[i]);
		dp[i][2] = max(dp[i-1][0] + c[i], dp[i-1][1] + c[i]);
	}
	cout << max(max(dp[N-1][0],dp[N-1][1]),dp[N-1][2]) << endl;

	return 0;
}
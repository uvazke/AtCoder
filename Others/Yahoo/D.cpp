#include <vector>
#include<iostream>
#include <cmath>
using namespace std;

int main(void){
	int n;
	long a[200000];
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	long **dp;
	dp = (long**)malloc(sizeof(long*)*(n+1));
	for(int i=0;i<=n;i++) {
		dp[i] = (long*)malloc(sizeof(long)*5);
		for(int j=0;j<5;j++)dp[i][j] = 1000000000;
	}
for(int i=0;i<=5;i++)dp[0][i] = 0;
	for(int i=1;i<=n;i++){
		dp[i][0] = dp[i-1][0] + a[i-1];
		for(int j=1;j<5;j++){
			for(int k=0;k<=j;k++){
				dp[i][j] = min(dp[i][j], dp[i-1][k]);
			}
		}
		dp[i][1] += (a[i-1] == 0 ? 2 : (a[i-1] & 1));
		dp[i][2] += (a[i-1] % 2 == 0);
		dp[i][3] += (a[i-1] == 0 ? 2 : (a[i-1] & 1));
		dp[i][4] += a[i-1];
	}
	long ans = 1000000000;
	for(int i=0;i<5;i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}
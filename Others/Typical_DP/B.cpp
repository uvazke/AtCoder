#include <iostream>
#include <vector>
using namespace std;

int main (void){
	int A,B;
	long dp[1001][1001] = {};
	cin >> A >> B;
	vector<long> a(A),b(B);
	for (int i=0;i<A;i++){
		cin >> a[i];
	}
	for (int i=0;i<B;i++){
		cin >> b[i];
	}
	for (int i=1;i<=A;i++){
		dp[i][0] = ((A+B-i)%2==0) ? dp[i-1][0] + a[A-i] : dp[i-1][0];
	}
	for (int j=1;j<=B;j++){
		dp[0][j] = ((A+B-j)%2==0) ? dp[0][j-1] + b[B-j] : dp[0][j-1];
	}
	for (int i=1;i<=A;i++){
		for (int j=1;j<=B;j++){
			dp[i][j] = (A+B- i-j)%2 == 0 ? max(dp[i-1][j]+a[A-i], dp[i][j-1]+ b[B-j]) : min(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	cout << dp[A][B] << endl;
	return 0;
}
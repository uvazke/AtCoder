#include <vector>
#include<iostream>

using namespace std;

int main(void){
	int N,psum=0;
	cin >> N;
	vector<int> p(N);

	for(int i=0;i<N;i++){
		cin >> p[i];
		psum += p[i];
	} 
	sort(p.begin(),p.end(),greater<int>());
	vector<vector<int> >dp(N+1, vector<int>(psum+1,0));
	for(int i=0;i<N+1;i++)dp[i][0] = 1;
	for(int i=0; i<N;i++){
		for(int j=0; j<psum+1;j++){
			dp[i+1][j] = dp[i][j];
			if(j >= p[i] && dp[i][j-p[i]] == 1) dp[i+1][j] = 1;
		}
	}

	int ans=0;
	for(int i=0;i<psum+1;i++){
		ans += dp[N][i];
	}
	
	cout << ans << endl;
	

}

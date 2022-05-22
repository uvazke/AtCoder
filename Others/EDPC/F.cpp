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

int dp[3001][3001]={};

int main(){
	string s,t,ans;
	cin >> s >> t;
	int i, j;
	myfor(i,s.size())myfor(j,t.size()){
		if(s[i] == t[j])dp[i+1][j+1] = dp[i][j] + 1;
		dp[i+1][j+1] = max(dp[i+1][j],dp[i+1][j+1]); 
		dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j+1]);
	}
	int ansSize = dp[s.size()][t.size()];
	ans.resize(ansSize,'0');
	i = s.size();
	j = t.size();
	while(i>0 && j>0){
		if(dp[i][j] == dp[i-1][j]){
			i--;
		}else if(dp[i][j] == dp[i][j-1]){
			j--;
		}else{
			ans[--ansSize] = s[i-1];
			i--,j--;
		}
	}
	
	cout << ans << endl;
	return 0;
}
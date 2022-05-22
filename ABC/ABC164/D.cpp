#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	string S;
	int i,j;
	long num=0,num2,ans;
	cin >> S;
	long dp2[2019]={};
	myfor(i,S.size()){	
		long dp[2019]= {};	
		myfor(j,2019){
			num2 = (j*10 + long(S[i] - '0'))%2019;
			dp[num2] += dp2[j];
		}	
		num = long(S[i] - '0')%2019;
		dp[num]++;
		ans+=dp[0];
		memcpy(dp2,dp,sizeof(dp));
	}
	cout << ans << endl;
	return 0;
}
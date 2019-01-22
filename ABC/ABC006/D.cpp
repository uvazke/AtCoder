#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1000000000
struct u
{
	int dp;
	int i;
};

bool dpDesc( const u& left, const u& right ) {
    return left.dp == right.dp  ? left.dp> right.dp : left.dp > right.dp;
}

// int algo1(){
//  u hoge = {0,0};
// 	uVec.push_back(hoge);
// 	for(i=1;i<=N;i++){
// 		j=0;
// 		sort(uVec.begin(), uVec.end(), dpDesc);
// 		while(c[uVec[j].i] >= c[i])j++;
// 		int cand = uVec[j].dp + 1;
// 		dp[i] = cand;
// 		u hoge2 = {dp[i],i};
// 		uVec.push_back(hoge2);
// 	}
	
// 	sort(uVec.begin(), uVec.end(), dpDesc);
// 	return N - uVec[0].dp;
// }
int main(){
	int N,c[30001],dp[30001];
	
	cin >> N;
	c[0] = 0;
	for(int i=1;i<=N;i++){
		cin >> c[i];
	}
	dp[0] = 0;
	for(int i=1;i<=N;i++){
		dp[i] = INF;//initialization
	}


	for(int i=1;i<=N;i++){
		int j=0;
		while(c[i] > dp[j]){
			j++;
		}
		dp[j] = c[i];
	}
	int k=0;
	while(k <= N && dp[k] != INF){
		k++;
	}
	k--;

	cout << N - k << endl;
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
int main(void){
	int N,H,W,ans;
	cin >> N >> H >> W;
	ans = (N-H+1)*(N-W+1);
	cout << ans << endl;
	return 0;
}
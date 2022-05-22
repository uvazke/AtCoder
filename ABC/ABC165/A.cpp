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

int main(){
	int K,A,B,i;
	long dp[100001]={};
	bool ans = false;

	cin >> K >> A >> B;
	myforFL(i,1,B/K+1){
		if(K*i >= A && K*i <=B){
			ans = true;
			break;
		}
	}
	if(ans)cout << "OK" <<endl;
	else cout << "NG" << endl;

	return 0;
}
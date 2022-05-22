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
typedef long long ll;
int main(){
	int i,N;
	ll A[100001];
	ll ans = 0,anstmp;
	cin >> N;
	myfor(i,N+1)cin >> A[i];	
	myfor(i,N){
		if(i<30){
			anstmp = min(A[N]-(A[i]), ll(pow(2,i))-(A[i])) + A[i];
			if(anstmp <= pow(2,i)){
				anstmp = min(A[N] + A[i],ll(pow(2,i)));
				ans += anstmp;
				cout << anstmp << endl;

			}else{
				cout << -1 << endl;
				return 0;
			}	
		}else{
			ans += A[N];
		}
	}
	ans += A[N];
	cout << ans << endl;
	return 0;
}

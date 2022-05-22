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
#define INF 100000000
using namespace std;
int countOneForBit(int bit){
	int ans=0;
	while(bit > 0){
		if(bit%2 == 1)ans++;
		bit >>= 1;
	}
	return ans;
}
int main(){
	int i,j,N,M,x[66],y[66],ans=0;
	cin >> N >>M;
	vector<int> v(N);
	myfor(i,M){
		cin >> x[i] >> y[i];
		v[x[i]-1] += (1<<(y[i]-1));
		v[y[i]-1] += (1<<(x[i]-1));
	}
	myfor(i,N){
		v[i] += (1<<i);
	}
	for(int bit=1; bit < (1<<N);++bit){
		int valid_group = bit;
		myfor(i,N){
			if(bit & (1<<i)){
				valid_group &= v[i];
			}
		}
		ans = max(ans,countOneForBit(valid_group));
	}
	cout << ans<< endl;
	
	return 0;
}
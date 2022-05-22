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
	long N,M,H[100000],A[100000],B[100000],i,j,ans=0;
	bool good[100000];
	cin >> N >> M;
	myfor(i,N){
		cin >> H[i];
		good[i]=true;
	}
	myfor(i,M){
		cin >> A[i] >> B[i];
		if(H[A[i]-1] >= H[B[i]-1])good[B[i]-1] = false;
		if(H[A[i]-1] <= H[B[i]-1])good[A[i]-1] = false;
	}
	myfor(i,N){
		if(good[i]){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
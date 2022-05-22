#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>

#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define myforInv(i,N) for(i=N;i>=0;i--)
#define myforFLInv(i,f,l) for(i=f;i>l;i--)
using namespace std;

int main(){
	long  N,i,j,A[200000],L[200000],R[200000],ans=0;
	map<long, long> mpL,mpR;
	cin >> N;
	myfor(i,N){
		cin >> A[i];
		L[i] = A[i] + i;
		R[i] = i - A[i];
		mpL[L[i]]++;
		mpR[R[i]]++;
	}
	for(auto itr = mpL.begin(); itr != mpL.end(); ++itr) {
     ans += mpR[itr->first] * itr->second;
  }
	cout << ans <<endl;

	return 0;
}



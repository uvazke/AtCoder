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
	long N,K,A[200000];

	int i;
	cin >> N >> K;
	myfor(i,N){
		cin >> A[i];
	}
	myfor(i,N-K){
		if(A[i] < A[i+K])cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0; 

}

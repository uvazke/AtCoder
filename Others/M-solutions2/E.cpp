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
#define myIfBetween(x,a,b) if(x >= a && x <= b)

using namespace std;

int main(){
	int N;
	long X[15],Y[15],P[15];

	cin >> N;
	int i;
	myfor(i,N){
		cin >> X[i] >> Y[i] >> P[i];
	}
	
	long maxDist=0,PSum=0;
	myfor(i,N){
		maxDist += min(abs(X[i]),abs(Y[i])) * P[i];
		PSum += P[i];
	}
	cout << maxDist << endl;
	long x0 = round((double)maxDist/(double)Psum);
	long y0 = 

	return 0;
}



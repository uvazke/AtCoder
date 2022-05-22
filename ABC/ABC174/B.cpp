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
	int N,D,X[200000],Y[200000],ans=0,i;
	cin >> N >>D;
	myfor(i,N) {
		cin >> X[i] >> Y[i];
		if(pow(X[i],2) + pow(Y[i],2) <= pow(D,2))ans++;
	}
	cout << pow(X[0],2);
	cout << ans << endl;
 	return 0;
}

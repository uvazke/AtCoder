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
	long A,B,C,K;
	cin >> A >> B >> C >> K;
	if(A>=K)cout << K << endl;
	else if(A+B >= K) cout << A << endl;
	else cout << A - (K -(A+B)) << endl;

	return 0;
}
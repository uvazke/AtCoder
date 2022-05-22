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


float distance(long x1,long y1,long x2,long y2){
	return pow((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1),1./2.);
}

int main(){
	long N,i,j;
	long x[100],y[100];
	float ans = 0.;
	cin >> N;
	myfor(i,N)cin >> x[i] >> y[i];
	myfor(i,N)myfor(j,N)ans = max(distance(x[i],y[i],x[j],y[j]),ans);

	cout << ans << endl;
	return 0;
}

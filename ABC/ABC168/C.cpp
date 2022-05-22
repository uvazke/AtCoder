#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <iomanip>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define myforInv(i,N) for(i=N;i>=0;i--)
#define myforFLInv(i,f,l) for(i=f;i>l;i--)

using namespace std;

int main(){
	int i,j;
	double A,B,H,M;
	double tx,ty,mx,my;
	double PI = 3.1415926535897932384626433832795028841971 ;
	cin >> A >> B >> H >> M;

	double trad = 2.*PI*(H/12.+ (M/60.)/12.);
	double mrad = 2.*PI*(M/60.);
	double ans;
	if(trad-mrad <= PI)ans = A*A + B*B - 2.*A*B*cos(trad-mrad);
	else ans = A*A + B*B - 2.*A*B*cos(2*PI - (trad-mrad));
	cout<< setprecision(10)<< pow(ans,0.5) << endl;
	return 0;
}

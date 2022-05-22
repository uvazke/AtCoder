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
#define ifMeetBoundaryCondition(x,xMax,xMin,y,yMax,yMin) if(x < xMax && x >= xMin &&y < yMax && y >= yMin)
#define INF pow(10,9)
using namespace std;

int dx[] = {1,-1,0,0},dy[]={0,0,1,-1};

int main(){
	long N,A,B,ans;
	cin >> N >> A >> B;
	ans = A * (N/(A+B));
	if(N%(A+B) >= A)ans += A;
	else ans += N%(A+B);
	cout << ans << endl;
	return 0;
}

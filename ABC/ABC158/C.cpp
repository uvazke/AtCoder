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
	int A,B,i,j;
	cin >> A >> B;
	int minX = ceil(12.5*A);
	int maxX = ceil(12.5*(A+1)-1);
	int minY = 10*B;
	int maxY = 10*(B+1)-1;

	myforFL(i,minX,maxX+1){
		myforFL(j,minY,maxY+1){
			if(i == j){
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}

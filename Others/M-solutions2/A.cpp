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
	int X;
	cin >> X;
	int i;
	myfor(i,8){
		myIfBetween(X,400+i*200,599+i*200)cout << 8-i << endl;
	}
	return 0;
}



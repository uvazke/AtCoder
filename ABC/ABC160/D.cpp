#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include<string>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	int N,X,Y,d[2001],i,j;
	cin >> N >> X >> Y;
	myforFL(i,1,N)d[i] = 0;
	myforFL(i,1,N)myforFL(j,i+1,N+1){
		d[min(j-i,abs(j-Y) +abs(X-i) + 1)]++;
	}
	myforFL(i,1,N)cout << d[i] << endl;
	return 0;
}
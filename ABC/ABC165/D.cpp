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

using namespace std;

int main(){
	unsigned long long A, B, N, x,maxNum=0;
	cin >> A >> B >> N;
	if(N>=B)x = B - 1; 
	else x = N;
	
	maxNum = (A*x)/B - A*(x/B);

	cout << maxNum << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	long N,A[200000],buka[200000],i,ans;
	cin >> N;
	myfor(i,N)buka[i] = 0;
	myfor(i,N-1){
		cin >> A[i];
		buka[A[i]-1]++;
	}
	myfor(i,N)cout << buka[i] << endl;
	return 0;
}

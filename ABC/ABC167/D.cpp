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
	long N,K,i,loopSize;
	long nextCity;
	
	cin >> N >> K;
	vector <long> A(N),loop;
	vector <bool> isUsed(N,false);
	myfor(i,N)cin >> A[i];
	
	loop.push_back(1);
	isUsed[0] = true;
	nextCity = A[0];
	if(nextCity != 1)loop.push_back(nextCity);
	else{
		cout << 1 << endl;
		return 0;
	}
	
	while(K >= loop.size()){
		isUsed[nextCity-1]=true;
		nextCity = A[nextCity-1];
		if(isUsed[nextCity-1])break;
		loop.push_back(nextCity);
	}
	if(K+1 == loop.size()){
		cout << loop[K] << endl;
		return 0;
	}
	myforInv(i,loop.size()-1){
		if(loop[i] == nextCity){
			loopSize = loop.size() - i;
			cout << loop[(K - (loop.size() - loopSize))%loopSize + loop.size() - loopSize] << endl;
			return 0;
		}
	}


	return 0;
}
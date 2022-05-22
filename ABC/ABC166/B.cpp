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
	int N,K,d,a,i,j,human[101]={},ans=0;
	cin >> N >> K;
	myfor(i,K){
		cin >> d;
		myfor(j,d){
			cin >> a;
			human[a] = 1;
		}
	}
	myforFL(i,1,N+1){
		if(human[i] == 0){
			ans++;
		}
	}
	cout << ans <<endl;
	return 0;
}
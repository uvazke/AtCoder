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
	int N,M,a,days=0,i,ans;
	cin >> N >> M;
	myfor(i,M){
		cin >> a;
		days += a;
	}
	if(days > N)ans=-1;
	else ans = N - days; 
	cout << ans << endl;
	return 0;
}
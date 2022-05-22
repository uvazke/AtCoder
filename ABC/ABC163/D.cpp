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
long solver(int N, int K){
	double ans = 0,tmp;
	int i,j;
	myforFL(i,K,N+1+1){
		j = N+1;
		tmp = 1;
		while(j > N+1-K){
			tmp *= double(j);
			j--;
		}
		j = double(K);
		while(j > 1){
			tmp /= double(j);
			j--;
		}
		ans += tmp;
	}
	return long(ans);
}



int main(void){
	long N,K,ans;
	cin >> N >> K;
	ans = solver(N,K);
	cout << ans << endl;
	return 0;
}
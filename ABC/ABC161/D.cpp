#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int main(void){
	int K;
	cin >> K;
	queue<long> Q;
	for(int i=0;i<9;i++)Q.push(i+1);
	long ans,x;
	for(int i=0;i<K;i++){
		x = Q.front();
		Q.pop();
		if(x%10!=0)Q.push(10*x + x%10 - 1);
		Q.push(10*x+x%10);
		if(x%10!=9)Q.push(10*x + x%10 + 1);
	}
	ans=x;
	cout << ans << endl;
	return 0;
}

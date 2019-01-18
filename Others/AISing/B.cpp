#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
int main(void){
	int N,A,B,P[100],a=0,b=0,c=0,ans;

	cin >> N >> A >> B;
	for(int i=0; i<N; i++){
		cin >> P[i];
		if(P[i]<= A)a++;
		else if(P[i] <= B)b++;
		else c++;
	}
	ans = min(min(a,b),c);
	cout << ans << endl;
	return 0;
}
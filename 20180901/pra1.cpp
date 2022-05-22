#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

const int INF = 100000000;
struct Vec{
	int ind;
	int val;
};

bool valDesc( const Vec& left, const Vec& right ) {
    return left.val == right.val  ? left.val> right.val: left.val > right.val;
}

bool valAsc( const Vec& left, const Vec& right ) {
    return left.val == right.val  ? left.val <  right.val: left.val < right.val;
}
int main(void){
	long N,K,x,ans=(long)0;

	cin >> N >> K;
	long s1,s2,s;
	if(K%2 == 0){
		s2 = floor(N/K);
		s1 = floor((long)2*N/K) -s2;
		ans = s1*(s1-(long)1)*(s1-(long)2)+(long)3*s1*(s1-(long)1) + s1;
		ans += s2*(s2-(long)1)*(s2-(long)2)+(long)3*s2*(s2-(long)1) + s2;
	}
	else{
		s = floor(N/K);
		ans = s*(s-(long)1)*(s-(long)2)+(long)3*s*(s-(long)1) + s;
	}

	printf("%ld\n",ans);
	fflush(stdout);

	return 0;
}
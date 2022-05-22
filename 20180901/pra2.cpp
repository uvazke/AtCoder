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
	long N,K,x,ans;
	vector<long> r = vector<long>(100000000, INF);
	vector<long> l = vector<long>(100000000, INF);

	cin >> N >> K;
	
	printf("%ld\n",ans);
	fflush(stdout);

	return 0;
}
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define ll long long
using namespace std;

ll combi3(ll  n) {
	return (n* (n - 1)* (n - 2)) / 6;
}

ll combi2(ll n) {
	return (n * (n - 1)) / 2;
}
ll calc(ll n, ll count) {
	return (n - count)*combi2(count) + combi3(count);
}
ll A[200001] = { 0 };

int main(void) {
	ll N;
	
	int i;
	cin >> N;
	myfor(i, N) {
		int a;
		cin >> a;
		A[a]++;
	}
	auto ans = combi3(N);
	for (auto cnt: A) {
		ans -= calc(N, cnt);
	}

	cout << ans << endl;
	return 0;
}

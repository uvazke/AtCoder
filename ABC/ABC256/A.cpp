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

int main(void) {
	ll ans;
	int N;
	cin >> N;
	ans = pow(2, N);
	cout << ans << endl;
	return 0;
}

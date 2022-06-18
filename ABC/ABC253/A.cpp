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
	int a,b,c;
	cin >> a >> b >> c;
	auto ans = (a >= b && b >= c) || (a <= b && b <= c);
	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}

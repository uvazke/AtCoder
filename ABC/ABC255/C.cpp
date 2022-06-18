#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define ll long long
using namespace std;

int main(void) {
	ll X, A, D, N;
	cin >> X >> A >> D >> N;
	if (D >= 0) {
		if (X >= A + D * N) {
			cout << (X - (A + N * D)) << endl;
			return 0;
		}
		if (X < A) {
			cout << A - X << endl;
			return 0;
		}
		auto l = (X - A) / D;	;
		cout << min(abs(A + l * D - X), abs(A + (l + 1) * D - X)) << endl;
		return 0;		
	}

	if (X < A + D * N) {
		cout << ((A + N * D) - X) << endl;
		return 0;
	}
	if (X >= A) {
		cout << X - A << endl;
		return 0;
	}
	auto l = (A - X) / D; ;
	cout << min(abs(A + l * D - X), abs(A + (l + 1) * D - X)) << endl;
	return 0;
}

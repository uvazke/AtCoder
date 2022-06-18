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
	int N, i, A[100];
	cin >> N;
	myfor(i, N) {
		cin >> A[i];
	};
	
	int lastFour[4] = {0};
	myfor(i, N) {
		for (int j = 0; j <=  2; j++) {
			lastFour[j] = lastFour[j+1] + A[i];
		}
		lastFour[3] = A[i];
	};
	int count = 0;
	myfor(i, 4) {
		if (lastFour[i] >= 4) {
			count++;
		}
	};
	int ans = N >= 4 ? (N - 4 + count) : count;
	cout << ans << endl;
	return 0;
}

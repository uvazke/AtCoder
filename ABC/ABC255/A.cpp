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
	int R, C, i;
	int A[2][2];
	cin >> R >> C;
	myfor(i, 2) {
		cin >> A[i][0] >> A[i][1];
	}
	cout << A[R - 1][C - 1] << endl;

	return 0;
}

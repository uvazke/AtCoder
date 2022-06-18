#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iomanip>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define ll long long
using namespace std;



int main(void) {
	int K, N;
	cin >> N >> K;
	int A[1000];
	double x[1000], y[1000];
	for (int i = 0; i< K; i++) {
		int a;
		cin >> a;
		A[i] = a - 1;
	}
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	double maxDistOfAllPeople = 0.0000;
	for (int i = 0; i < N; i++) {
		auto minimumDist = 10000000.0;
		for (int j = 0; j < K; j++) {
			auto tmp = sqrt(pow(x[i] - x[A[j]], 2) + pow(y[i] - y[A[j]], 2));
			minimumDist = min(tmp, minimumDist);
		}
		maxDistOfAllPeople = max(minimumDist, maxDistOfAllPeople);

	}
	cout << std::fixed << std::setprecision(15) << maxDistOfAllPeople << endl;

	return 0;
}

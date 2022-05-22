#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
using namespace std;
int main(void) {
	int N, K,i;
	int A[100], B[100];
	int maxValue = 0;
	cin >> N >> K;
	myfor(i, N) {
		cin >> A[i];
		if (A[i] >= maxValue) {
			maxValue = A[i];
		}
	}
	int j;
	myfor(j, K) {
		cin >> B[j];
	}

	myfor(i, N) {
		if (A[i] == maxValue) {	
			myfor(j, K) {
				if (B[j] == i+1) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;
	return 0;
}

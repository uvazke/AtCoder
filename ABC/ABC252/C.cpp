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
	int N, i;
	string s[100];
	cin >> N;
	myfor(i, N) {
		cin >> s[i];
	}

	int j = 0;
	int table[10][10] = {0};
	

	myfor(i, 10) {
		myfor(j, N) {
			auto index = s[j].find(char(i + '0'));
			table[i][index]++;
		}
	}
	int minTime = 100000000;
	myfor(i, 10) {
		int tmp = 0;
		myfor(j, 10) {
			auto time = table[i][j] != 0 ? (table[i][j] - 1) * 10 + j : 0;
			tmp = max(tmp, time);
		}
		minTime = min(minTime, tmp);
	}
	cout << minTime << endl;
	return 0;
}

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
	int H, W;
	cin >> H >> W;
	string s[100];
	int i;
	int i1, i2, j1, j2;
	bool isFirst = true;
	myfor(i, H) {
		cin >> s[i];
		int j;
		myfor(j, W) {
			if (s[i][j] == 'o') {
				if (isFirst) {
					i1 = i;
					j1 = j;
					isFirst = false;
					continue;
				}
				i2 = i;
				j2 = j;
			}
		}
	}

	auto ans = abs(i2 - i1) + abs(j2 - j1);

	cout << ans << endl;
	return 0;
}

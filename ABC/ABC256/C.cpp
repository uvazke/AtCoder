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
	int h1, h2, h3, w1, w2, w3;
	cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
	ll ans = 0, cnt = 0;
	auto iMax = min(h1-2, w1-2);
	for (int i = 1; i <= iMax; i++) {
		auto jMax = min(h1 -1- i, w2-2);
		for (int j = 1; j <= jMax; j++) {
			auto kMax = min(h1 - i - j, w3 -2);
			int k = h1 - i - j;
			if (k > w3 - 2) {
				continue;
			}
			auto lMax = min(h2- 2, w1 - 1 - i);
			for (int l = 1; l <= lMax; l++) {
				auto mMax = min(h2 - 1 - l, w2 - 1 - j);
				for (int m = 1; m <=  mMax; m++) {
					int n = h2 - l - m;
					if (n > w3 - 1 - k) {
						continue;
					}
					auto oMax = min(h3 - 2, w1 - i - l);
					for (int o = 1; o <= oMax; o++) {
						if ((i + l + o) != w1) {
							continue;
						}
						auto pMax = min(h3 - 1 - o, w2 - j - m);
						for (int p = 1; p <= pMax; p++) {
							if ((j + m + p) != w2) {
								continue;
							}
							int q = h3 - o - p;
							if ((k + n + q) == w3) {
								ans++;
							}
						}
					}
					
				}
			}
			
		}
	}

	cout << ans << endl;

	return 0;
}

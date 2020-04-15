#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
	long N,K;
	cin >> N >> K;
	long ans = min(N%K,abs(N%K-K));
	cout << ans << endl;
	return 0;
}

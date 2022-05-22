#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void) {
	string s;
	cin >> s;
	int a = s[0] - '0';
	int b = s[2] - '0';
	cout << a * b << endl;
	return 0;
}

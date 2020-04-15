#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
	int N;
	cin >> N;
	if(N/100 == 7 || (N%100)/10 == 7 || (N%10)==7)cout << "Yes" << endl;
	else cout << "No" <<endl;
	return 0;
}

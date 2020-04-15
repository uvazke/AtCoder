#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
	int N;
	cin >> N;
	long ans=0;
	for(int i=1;i<=N;i++){
		if(i%3 != 0 && i%5 != 0)ans += i; 
	}
	cout << ans << endl;
	return 0;
}

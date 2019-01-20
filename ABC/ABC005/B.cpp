#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N, T,ans=100;
	cin >> N;
	for (int i=0; i< N;i++){
		cin >> T;
		ans = min(ans, T);
	}
	cout << ans << endl;
	return 0;
}
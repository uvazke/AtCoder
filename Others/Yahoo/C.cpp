#include <vector>
#include<iostream>

using namespace std;

int main(void){
	int K, A, B;
	long ans;
	cin >> K >> A >> B;
	if(B<=A+1){
		ans = K+1;
	}else if(K - 1 >= A){
		ans = long(A) + long((((K + 1) - A))/2)*long((B-A));
		if(((K + 1) - A)%2 == 1) ans++;
	}else ans = K + 1;
	cout << ans << endl;
	return 0;
}

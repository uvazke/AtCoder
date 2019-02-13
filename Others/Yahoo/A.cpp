#include <vector>
#include<iostream>

using namespace std;

int main(void){
	int N,K;
	cin >> N >> K;
	if((N+1)/K >= 2)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int N;
	int A[100],B[100],aMax=1,bMin=1000;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		aMax = max(A[i],aMax);
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> B[i];
		bMin = min(B[i],bMin);
	}
	int ans = max(bMin - aMax + 1,0);
	cout << ans << endl;
	return 0;
}
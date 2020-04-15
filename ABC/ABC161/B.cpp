#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(void){
	int N,M,count=0,sum;
	vector<int> A;
	cin >> N >> M;
	int tmp;
	for (int i=0;i<N;i++){		
		cin >> tmp;
		A.push_back(tmp);
	}
	sum = accumulate(A.begin(),A.end(),0);
	for (int i=0;i<N;i++){
		if(A[i] >= float(sum)/(4*M)){
			count++;
		}
	}
	if(count >= M)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

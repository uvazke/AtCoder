#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
int main(){
	int N,a;
	vector<int> A;
	cin >> N;
	f(i,0,N){
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(),A.end(),greater<int>() );
	int max2 = A[0];
	f(i,1,N){
		if(max2 != A[i]){
			cout << A[i] << endl;		
			return 0;
		}	
	}
	return 0;
}
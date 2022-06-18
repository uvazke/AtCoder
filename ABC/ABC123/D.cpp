#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define f2(i,a,b) for(int i=a;i<b;i++)

int main(){
	int x,y,z,k;
	vector<long> A(1000),B(1000),C(1000);
	long sum;
	cin >> x >> y >> z >> k;
	f(i,x) cin >> A[i];
	f(i,y) cin >> B[i];
	f(i,z) cin >> C[i];
	sort(A.begin(),A.end(),greater<long>() );
	sort(B.begin(),B.end(),greater<long>() );
	sort(C.begin(),C.end(),greater<long>() );
	int i1=0,i2=0,i3=0,cand1,cand2,cand3,m;
	f(i,k){
		sum = A[i1] + B[i2] + C[i3];
		if(i1+1 < x)cand1 = A[a[0]+1]+B[i2]+C[i3];
		else cand1 = 0;
		if(i2+1 < y)cand2 = A[i1]+B[i2+1]+C[i3];
		else cand2 = 0;
		if(i3+1 < z)cand3 = A[i1]+B[i2]+C[i3+1];
		else cand3 = 0;
		cout << A[i1] << " "  << B[i2] << " "<< C [i3] << endl;
		m = max(cand1,max(cand2,cand3));
		if(m == cand1)i1++;
		else if(m == cand2)i2++232
		else if(m == cand3)i3++;
		cout << sum << endl;
	} 
	return 0;
}
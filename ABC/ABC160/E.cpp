#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>

#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

void mySortDesc(long a[],int n);
void appendArray(long a[],int n1, long b[], int n2, long ret[]);
void arraycpy(long a[],int f,int l, long ret[]);
long sumOfArray(long a[],int n);
void solver1(){
	int X,Y,A,B,C,i,j,k;
	long p[100000],q[100000],r[100000],p2[100000],q2[100000],umami[300000],ans;
	cin >> X >> Y >> A >> B >> C;
	myfor(i,A)cin >> p[i];
	myfor(i,B)cin >> q[i];
	myfor(i,C)cin >> r[i];
	mySortDesc(p,A);
	mySortDesc(q,B);
	mySortDesc(r,C);
	arraycpy(p,0,X,p2);
	arraycpy(q,0,Y,q2);

	appendArray(p2,X,q2,Y,umami);
	appendArray(umami,X+Y,r,C,umami);
	mySortDesc(umami,X+Y+C);

	ans = sumOfArray(umami,X+Y);

	cout << ans << endl;
}

int main(void){
	int X,Y,A,B,C,i,j,k;
	vector <long> p,q,r,umami;
	long ans,tmp;

	cin >> X >> Y >> A >> B >> C;
	myfor(i,A){
		cin >> tmp;
		p.push_back(tmp);
	}
	myfor(i,B){
		cin >> tmp;
		q.push_back(tmp);
	}
	myfor(i,C){
		cin >> tmp;
		r.push_back(tmp);
	}
	sort(p.begin(),p.end(),greater<long>());
	sort(q.begin(),q.end(),greater<long>());

	q.resize(X+Y);

	copy(p.begin(),p.begin() + X,q.begin() + Y);
	copy(q.begin(),q.end(),back_inserter(r));
	sort(r.begin(),r.end(),greater<long>());
	ans = accumulate(r.begin(),r.begin() + X+Y,0L);
	cout << ans << endl;


	return 0;
}

void mySortDesc(long a[],int n){
	int i,j;
	long tmp;
	myfor(i,n)myforFL(j,i,n){
		if(a[i] < a[j]){
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}

void appendArray(long a[],int n1, long b[], int n2, long ret[]){
	int i;
	myfor(i,n1)ret[i] = a[i];
	myfor(i,n2)ret[i+n1] = b[i];
}

void arraycpy(long a[],int f,int l, long ret[]){
	int i;
	myforFL(i,f,l)ret[i-f] = a[i];
}

long sumOfArray(long a[],int n){
	int i;
	long ans=0;
	myfor(i,n)ans += a[i];
	return ans;
}
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
using namespace std;

int main(){
	int N,M,count=0,member=1;
	int x[66],y[66];
	bitset<12> a[12],k,k_init;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		a[i].set(i);
		k.set(i);
		k_init.set(i);
	}
	for(int i=0;i<M;i++){
		cin >> x[i] >> y[i];
		a[x[i]-1].set(y[i]-1);
		a[y[i]-1].set(x[i]-1);
	}
	for(int j=1;j<=pow(2,N);j++){
		unsigned long num = j;
		bitset<12> itr(num);
		count = 0;
		for(int i=0;i<N;i++){
			if(itr[i]){
				k &= a[i];
				count++;
			}
		}
		member = max(member, min(int(k.count()), count));
		k = k_init; 
	}
	cout << member << endl;
	

	return 0;
}
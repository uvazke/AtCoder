#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;
int mygcd2(int a,int b);
int mygcd3(int a,int b,int c);
int main(void){
	int K;
	cin >> K;
	long ans=0;
	int anstmp = 0;
	for(int i=1;i<=K;i++){
		for(int j=i;j<=K;j++){
			for(int k=j;k<=K;k++){
				if(i != j && j != k)anstmp= 6*mygcd3(i,j,k);
				else if(i!= j || j!=k) anstmp =3*mygcd3(i,j,k);
				else anstmp=mygcd3(i,j,k);
				ans += anstmp;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

int mygcd2(int a,int b){
	if(b==0)return a;
	return mygcd2(b,a%b);
}

int mygcd3(int a,int b,int c){
	return mygcd2(mygcd2(a,b),c);
}


#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int factorial(int n){
	if(n>1){
		return n*factorial(n-1);
	}else{
		return 1;
	}
}
long factorialWithMod(long n,long k,long l, long mod){
	long a=1,b[900];
	long itr;
	int x[900],count=0;
	for(int i=0;i<900;i++)x[i] = 0;
	for(int i=k+1;i<=n;i++){
		b[i] = i;
	}
	for(int i=k+1;i<=n;i++){
		if(count == 0){
			for(itr=l;itr>=1;itr--){
				if(x[itr] == 0 && b[i]%itr == 0){
					b[i] /= itr;
					x[itr] = 1;
				}
			}
		}
	}
	for(int i=k+1;i<=n;i++){
		a = (a*b[i])%mod;
		cout << a << endl;
	}
	cout << a << endl;
	
	return a;
}
int main(){
	long R,C,X,Y,D,L;
	cin >> R >> C;
	cin >> X >> Y;
	cin >> D >> L;
	long a = min(D,L),b = max(D,L);	
	long ans = (((R-X+1)%long(pow(10,9)+7)) * ((C-Y+1)%long(pow(10,9)+7))*factorialWithMod(X*Y,b,a,long(pow(10,9)+7)));
	cout << ans << endl;
	ans %= long(pow(10,9)+7);

	cout << ans << endl;
	
	return 0;
	
}
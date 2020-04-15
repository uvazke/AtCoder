#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;
long mygcd2(int a,int b);
long mygcd3(int a,int b,int c);
long mygcdn(int a[],int n);
void primeNumbers(long N,long prime[],long *prime_num);
int main(void){
	long N,K,A[100000],prime_num;
	cin >> N >> K;
	long ans=0,prime[100000];
	long anstmp = 0;
	int i;
	primeNumbers(K, prime, &prime_num);
	ans = long(pow(K,N));
	myfor(i,prime_num){
		ans += long(pow(K/prime[i],N)*(prime[i]-1));//どうにかして，2Xとかの文を抽出せなあかん
		
	}
	ans %= long(pow(10,9)+7);
	cout << ans << endl;
	return 0;
}

long mygcd2(int a,int b){
	if(b==0)return a;
	return mygcd2(b,a%b);
}

long mygcd3(int a,int b,int c){
	return mygcd2(mygcd2(a,b),c);
}

long mygcdn(int a[],int n){
	long i,ans = mygcd2(a[0],a[1]);
	myforFL(i,1,n-1){
		ans = mygcd3(a[i],a[i+1],ans);
	}
	return ans;
}

void primeNumbers(long N,long prime[],long *prime_num){
	int i,j,k=0;
	bool flag;
	myforFL(i,2,N+1){
		flag = true;
		myforFL(j,2,i){
			if(i%j == 0)flag = false;
		}
		if(flag)prime[k++] = i;
	}
	*prime_num = k;
}

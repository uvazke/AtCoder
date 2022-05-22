#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define myforInv(i,N) for(i=N;i>=0;i--)
#define myforFLInv(i,f,l) for(i=f;i>l;i--)

using namespace std;

int main(){
	long N,A[80],money=1000,stock=0;
	long dif[79];
	cin >> N;
	int i;
	myfor(i,N){
		cin >> A[i];
		if(i>0)dif[i-1] = A[i] - A[i-1];
	}

	long buyPrice=300,cellPrice=0;
	myfor(i,N){
		if(dif[i] > 0 && buyPrice > A[i]){
			if(cellPrice != 0){
				money += stock *cellPrice;
				stock = 0;
				cellPrice = 0;
			}
			buyPrice = A[i];
		}
		if(dif[i] < 0 && cellPrice < A[i]){
			if(buyPrice !=300){
				stock = money/buyPrice;
				money%=buyPrice;
				buyPrice = 300;
			}
			cellPrice = A[i];
		}
	}
	if(buyPrice !=300){
		stock = money/buyPrice;
		money%=buyPrice;
		buyPrice = 300;
	}
	if(cellPrice != 0){
		money += stock *cellPrice;
		stock = 0;
		cellPrice = 0;
	}
	money += stock *A[N-1];

	cout << money << endl;

	return 0; 

}

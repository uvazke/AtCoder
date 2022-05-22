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
#define MAXDIF 126 //pow(pow(10.,9.),1./5.)*2
using namespace std;

int main(){
	long X,i,j;
	cin >> X;
	myforFL(i,-63,127){
		myforFL(j,i,127){
			if(pow(j,5) - pow(i,5) == X){
				cout << j << " " << i << endl;
				return 0;
			}
		}
	}
	return 0;
}

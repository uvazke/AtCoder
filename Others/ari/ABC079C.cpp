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

int add(int a, int b){
	return a+b;
}
int sub(int a, int b){
	return a-b;
}


int main(){
	string S;
	int i,j,k;
	string opr = "+-";
	

	cin >> S;
	int a,b,c,d,num;
	a = S[0] - '0';
	b = S[1] - '0';
	c = S[2] - '0';
	d = S[3] - '0';
	myfor(i,2){
		myfor(j,2){
			myfor(k,2){
				if(opr[i] == opr[0]) num = add(a,b);
				else num = sub(a,b);
				if(opr[j] == opr[0]) num = add(num,c);
				else num = sub(num,c);
				if(opr[k] == opr[0]) num = add(num,d);
				else num = sub(num,d);
				if(num == 7){
					string hoge = "hoge";
					string ans = hoge + S[0] + opr[i]+S[1]+opr[j]+S[2]+opr[k]+S[3]+"=7";
					
					cout << ans.substr(4) <<endl; 
					return 0;
				}
			}
		}
	}
	return 0;
}
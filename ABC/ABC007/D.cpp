#include <iostream>
#include <cmath>
using namespace std;

//it can solve the numbers of "numbers" which do not include 4 and 9.
long solve(long x){
	long xTmp = x,xHead=0,numOfDigit = 1,ans = 0;

	while(xTmp/10 > 0){
		xTmp /=10;
		numOfDigit++;
	}
	xHead = xTmp%10;

	if(numOfDigit > 1){
		ans = long(pow(8,numOfDigit-1));	
		if(xHead > 0){
			if(xHead <= 4)ans *= xHead;
			else if(xHead <= 9) ans *= (xHead - 1);
			if(xHead != 4 && xHead != 9){
				ans += solve(x - xHead * long(pow(10, numOfDigit-1)));
			}else{
				ans--;
			}
		}
	}else{
		if(x < 4)ans = xHead;
		else if(x < 9) ans = xHead - 1;
		else ans = xHead - 2; 
	}

	return ans;
}

long isProhibited(long x){
	long r;
	while(x > 0){
		r = x%10;
		if(r == 4 || r == 9){
			return 1;
		}
		x/=10;
	}
	return 0;
}

int main(){
	long A,B,Aans,Bans,ans;
	cin >> A >> B;
	Aans = (A - solve(A));
	Bans = (B - solve(B));
	ans = Bans - Aans + isProhibited(A);
	cout << ans << endl;
	return 0;
}
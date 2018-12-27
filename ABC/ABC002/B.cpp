#include<iostream>

using namespace std;
int main(){
	int x,y;
	cin >> x >> y;
	int a = abs(y-x)/10;
	int b;

	if((abs(y-x)%10)/5 >= 1){
		if(float((abs(y-x)%10)%5)/2.5 >= 1.0){
			b = 5 - (abs(y-x)%10)%5 + 1; //+ 10 degrees celsius change
		}else{
			b = (abs(y-x)%10)%5+1; //+ 5 degrees celsius change
		}
	}else{
		if(float((abs(y-x)%10)%5)/2.5 >= 1.0){
			b = 5 - (abs(y-x)%10)%5 + 1; //+ 5 degrees celsius change
		}else{
			b = (abs(y-x)%10)%5;
		}
	}

	
	cout << a+b<< endl;
	return 0;
} 
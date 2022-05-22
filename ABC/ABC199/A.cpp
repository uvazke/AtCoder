#include <iostream>

using namespace std;

int main (){
	int A,B,C,ans;
	cin >> A >> B >> C;
	cout << ((A*A + B*B < C*C) ? "Yes" : "No")<< endl;
}
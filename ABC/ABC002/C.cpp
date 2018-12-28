#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main (){
	int x[3],y[3];
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
	int a[2],b[2];
	a[0] = x[1] - x[0];
	a[1] = y[1] - y[0];
	b[0] = x[2] - x[0];
	b[1] = y[2] - y[0];
	double ans = double(abs(a[0]*b[1] - a[1]*b[0]))/2.0;
	cout <<fixed << setprecision(10)<< ans << endl;
	return 0;
}
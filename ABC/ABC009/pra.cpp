#include <iostream>
#include <ios>
#include <iomanip>
#include <regex>
#include<cstdlib>
using namespace std;

int nCr(int n, int r){
  long den=1,num=1;
  for(int i=n;i>n-r;i--){
    num *= long(i); 
  }
  cout << num << endl;

  for(int i=1;i<r+1;i++){
    den *= long(i); 
  }
  cout << den <<endl;
  return (num/den);
}
int main(){
	char *x[] = {"fdsa","fdsaっf"};
	cout << (sizeof(x) / sizeof(x[0])) << endl;
	cout << nCr(20,10) << endl;
	char a[] = "4392149328194382914832" ,b[] = "2";
	int n = atoi(a), m = atoi(b);
	cout << n << m << endl;
	if(!regex_match(a,regex("\\d+")) || !regex_match(b,regex("\\d+"))){
		cout << a << endl;
    return 1;
  }
  if(n <= 0 || n > 10 || m <= 0 || m > 10){
  	cout << "fdsafdsaf" << endl;
    return 1;
  }else if((n*m)%2 == 1){
    cout << setfill('0') << right << setw(9) << 0 << endl;
    return 0;
  }
  cout << setfill('0') << right << setw(9) << nCr(n*m,(n*m)/2) << endl;

	return 0;
}
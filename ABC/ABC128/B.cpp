#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,j,n) for(int i=j;i<n;i++)

using namespace std;
struct restaurant{
	string name;
	int value;
	int index;
};

bool restaurantSort(const restaurant& a, const restaurant& b){
	if(a.name == b.name) return a.value > b.value;
	else return a.name < b.name;
}


int main(){
	int N, P, tmp;
	string S,strTmp;
	vector<restaurant> r; 
	cin >> N;
	f(i,N){
		cin >> S >> P;
		restaurant rTmp = {S,P,i+1};
		r.push_back(rTmp);
	}
	sort(r.begin(), r.end(), restaurantSort);
	f(i,N) cout << r[i].index << endl;
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
int main(void){
	int Deg,Dis,W;
	string Dir,DirBase;
	cin >> Deg,Dis;
	Dir= "";
	if(Deg <= 562){
		Dir+="N";
		if(Deg > 338)Dir+="E";
		else if(Deg > 112)Dir+="NE";
	}else if(Deg > 3037){
		Dir+="N";
		if(Deg < 3263)Dir+="W";
		else if(Deg < 3488)Dir+="NW";
	}else if()
	
	
	cout << VV << endl;
	return 0;
}
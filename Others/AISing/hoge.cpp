#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string s[400];
int H,W;

int (*dfs(int list[][400]))[400]{
	list[0][0] = 3;
	return list;
}

int main(void){
	int list[400][400];
	list[0][0] = 0;
	int (*list2)[400] = dfs(list);
	cout << list[0][0] << endl;
	cout << list2[0][0] << endl;
	
	return 0;
}


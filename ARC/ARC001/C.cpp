#include<iostream>

using namespace std;

#define f(i, n) for(int i=0; i < n; i++)
#define INF 10000000

int solver(int *a,int depth){
	int tmp = INF;
	f(i,8)f(j,8){
		f(k,8){
			if(a[i]== INF){
				if(tmp != -1 && j != a[k] && (j != a[k] - abs(i - k)) && (j != a[k] + abs(i - k)))tmp = j;
				else tmp = -1;
			}
		}
		if(tmp == j){
			a[i] = j;
			if (solver(a,depth+1) == 0) a[i] = INF;
		}
		tmp = INF;
	}
	f(i,8)if(a[i] == INF){ 
		return 0;
	}
	return 1;
}



int main(){
	string c[8];
	int a[8]={INF,INF,INF,INF,INF,INF,INF,INF};
	f(i ,8){
		cin >> c[i];
	}

	f(i,8)f(j,8){
		if(c[i][j] == 'Q'){
			if(a[i] != INF){
				cout << "No Answer" << endl; 
				return 0;
			}
			a[i] = j;
			
		}
	}
	f(i,8)f(j,8)if(i != j && ((a[i] != INF && a[i] == a[j]) ||a[i] == a[j] - abs(i - j) || (a[i] == a[j] + abs(i - j)))){
		cout << "No Answer" << endl; 
		return 0;
	}
	if(solver(a,0) == 0){
		cout << "No Answer" << endl; 
		return 0;
	};

	f(i,8){
		string s = "........";
		s[a[i]] = 'Q';
		cout << s << endl;
	}
	return 0;
}


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
#define ifMeetBoundaryCondition(x,xMax,xMin,y,yMax,yMin) if(x < xMax && x >= xMin &&y < yMax && y >= yMin)
#define INF pow(10,9)
using namespace std;

int dx[] = {1,-1,0,0},dy[]={0,0,1,-1};
vector<deque<int> >a(3);
int find_num(int num){
	if(find(a.begin(),a.end(),num) != a.end()){
		return 0;
	}else if(find(b.begin(),b.end(),num) != b.end()) {
		return 1;
	}else{
		return 2;
	}
}
int main(){
	int n, m, i, j=0,move_num =0;
	
	string s;
	cin >> n >> m;
	myfor(i,3){
		cin >> s;
		s.erase(0,2);
		while(!s.empty()){
			if(i==0)a[0].push_front(s[0] - '0');
			if(i==1)a[1].push_front(s[0] - '0');
			if(i==2)a[2].push_front(s[0] - '0');
			s.erase(0,2);
		}
	}
	int objective_vec_num = find_num(1);
	myforFL(i,2,m+1){
		int next_num_place = find_num(i);
		if(next_num_place == objective_vec_num)continue;
		while(a[next_num_place].front() != i){
			if(next_num_place == 1){
				if(a[2 - objective_vec_num].front() < a[next_num_place].front()){	
					a[2 - objective_vec_num].push_front(a[next_num_place].front());
					a[next_num_place].pop_front();
					move_num++;
				}else{
					cout << -1 << endl;
					return 0;
				}
			}else{

			}
		
	}
	return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int N,max=0;
	string S[50],ans;
	unordered_map<string, int> map;
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> S[i];
		map[S[i]]++;
	}

	for(auto itr = map.begin(); itr != map.end(); itr++){
		if(max < itr->second){
			max = itr->second;
			ans = itr->first;
		}
	}
	
	cout << ans << endl; 
	return 0;
}
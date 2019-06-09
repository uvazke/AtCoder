#include<iostream>
#include<vector>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;i++)

string S;
vector<int> replacedInd;
bool isAlreadyReplaced(int i){
	f(j,0,replacedInd.size())if(replacedInd[j] == i)return true;
	return false;
}

int main(){
	int N,K;
	cin >> N >> K;
	cin >> S;
	if(K <= 1){
		cout << S << endl;
		return 0;
	}
	int count = 0;
	f(i,0,N){
		char min = S[i];
		int minind = i;
		bool siIsAlreadyReplaced = isAlreadyReplaced(i);
		f(j,i,N){
			if(replacedInd.size() <= K-2){
				if(S[j] <= min){
					 min = S[j];
					 minind= j;
				}
			}else if(replacedInd.size() == K-1){
				bool sjIsAlreadyReplaced = isAlreadyReplaced(j);
				if(S[j] <= min && !(!siIsAlreadyReplaced && !sjIsAlreadyReplaced)){
					 min = S[j];
					 minind= j;
				}
			}else if(replacedInd.size() == K){
				bool sjIsAlreadyReplaced = isAlreadyReplaced(j);
				if(S[j] <= min && siIsAlreadyReplaced && sjIsAlreadyReplaced){
					 min = S[j];
					 minind= j;
				}
			}
		}

		if(i != minind && S[i] != min){
			bool minIsAlreadyReplaced = isAlreadyReplaced(minind);

			if(!siIsAlreadyReplaced)replacedInd.push_back(i);
			if(!minIsAlreadyReplaced)replacedInd.push_back(minind);

			if(replacedInd.size() <= K){
				char tmp = S[i];
				S[i] = min;
				S[minind] = tmp;
			}else{
				if(!siIsAlreadyReplaced)replacedInd.pop_back();
				if(!minIsAlreadyReplaced)replacedInd.pop_back();
			}
		}
	}
	
	cout << S << endl;
	return 0;
}
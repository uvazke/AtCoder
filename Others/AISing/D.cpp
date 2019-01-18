#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>
#include <iterator>

using namespace std;
int main(void){
	long N,Q,A[100000],X[100000],sum=0,ans;
	vector<long> v;
	int k=0;
	int inik = k;
	cin >> N >> Q;
	for(int i=0; i<N; i++){
		cin >> A[i];
		v.push_back(A[i]);
		if(i >= N/2)sum += A[i];
	}

	for(int i=0; i<Q; i++){
		cin >> X[i];
	}

	
	for(int i=0; i<Q; i++){
		k = inik;
		while(A[k] < X[i]){
			k++;
			if(k>=N)break;
		}
		if(k>0)k--;
		inik = k;
		
		if(X[i] <= A[N/2]/2){
			ans = sum;
		}else{
			vector<long> v2;
			copy(v.begin(), v.end(), back_inserter(v2) );
			for(int j=0;j<(N+1)/2;j++){
				ans += v2.back();
				v2.pop_back();
				if(!v2.empty()){
					if(k < v2.size()-1){
						if(abs(v2[k] - X[i]) <= abs(v2[k+1] - X[i])){
							v2.erase(v2.begin() + k);
							if(k>0)k -= 1;
						}else{
							v2.erase(v2.begin() + k+1);
						}
					}else{
						v2.pop_back();
						if(k>0)k-=1;
					}
				}
			}
			
		}
		cout << ans << endl;
		ans = 0;
	}

	return 0;
}
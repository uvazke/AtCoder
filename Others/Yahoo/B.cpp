#include <vector>
#include<iostream>

using namespace std;

int main(void){
	int a[3],b[3],gone[4],used[3],now,ans=0;
	for(int i=0;i<3;i++)cin >> a[i] >> b[i];
	for(int k=0; k<6;k++){
		if(k%2==1)now = b[k/2];
		else now = a[k/2];
		for(int i=0;i<3;i++){
			gone[i] = 0;
			used[i] = 0;
		}
		gone[3] = 0;
		gone[now-1] = 1;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(used[j] == 0){
					if(b[j] == now && a[j] != now && gone[a[j]-1] == 0){
						gone[a[j]-1] = 1;
						used[j] = 1; 
						now = a[j];
					}else if(b[j] != now && a[j] == now && gone[b[j]-1] == 0){
						gone[b[j]-1] = 1; 
						used[j] = 1; 
						now = b[j];
					}else if(gone[a[j]-1] == 1 && gone[b[j]-1] == 1){
						i=100;
					}
				}
			}
		}
		for(int i=0;i<3;i++){
			ans+=used[i] + gone[i];
		}
		ans += gone[3];
		if(ans == 7){
			cout << "YES" << endl;
			return 0;
		}
		ans=0;
	}
	cout << "NO" << endl;
	return 0;
}

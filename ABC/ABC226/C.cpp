#include <algorithm>
#include <float.h>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <vector>
#define myfor(i, N) for (i = 0; i < N; i++)
#define myforFL(i, f, l) for (i = f; i < l; i++)
#define myforInv(i, N) for (i = N; i >= 0; i--)
#define myforFLInv(i, f, l) for (i = f; i > l; i--)
using namespace std;

int main() {
    int N, i, j;
    int T[200000];
    map<int, vector<int> > myMap;
    bool used[200000];

    cin >> N;
    myfor(i, N) {
        int K;
        cin >> T[i]>> K;
        myMap[i].clear();
        myfor(j, K) {
            int A;
            cin >> A;
            myMap[i].push_back(A - 1);
        }
        used[i] = false;
    }

    long ans = 0;
    used[N - 1] = true;
    myforInv(i, N - 1) {
        if(used[i]){
            ans += T[i]; 
            for(auto x : myMap[i]){
                used[x] = true;
            }
        }    
    }
    auto vec = myMap[N - 1];
    cout << ans<< endl;
    return 0;
}
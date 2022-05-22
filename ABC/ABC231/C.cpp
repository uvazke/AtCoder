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
    int N,Q,i;
    vector<int> A;
    cin >> N >> Q;
    myfor(i,N){
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    
    myfor(i,Q){
        int x;
        cin >> x;
        auto itr = lower_bound(A.begin(), A.end(), x);
        if(itr != A.end()){
            auto pos = distance(A.begin(), itr);
            cout << N - pos << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
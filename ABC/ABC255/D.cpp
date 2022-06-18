#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define ll long long
using namespace std;
ll sum[200000];

int main(void) {
    int N, Q, X[200000];
    vector<int> vec;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end());
    sum[0] = (ll)vec[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + (ll)vec[i];
    }


    for (int i = 0; i < Q; i++) {
        cin >> X[i];
    }

    for (int i = 0; i < Q; i++) {
        auto uB = upper_bound(vec.begin(), vec.end(), X[i]);
        ll index = distance(vec.begin(), uB);
        if (uB == vec.end()) {
            ll ans3 = (ll)X[i] * (ll)(N)-sum[N - 1];
            cout << ans3 << endl;
            continue;
        }
        if (index - 1 <= 0) {
            ll ans2 = sum[N - 1] - (ll)X[i] * ((ll)N);
            cout << ans2 << endl;
            continue;
        }
        ll ans = (ll)X[i] * (ll)(index) - sum[index-1] + sum[N - 1] - sum[index-1] - (ll)X[i] * ((ll)N - (ll)(index));
        cout << ans << endl;
    }
    
    
    return 0;
}

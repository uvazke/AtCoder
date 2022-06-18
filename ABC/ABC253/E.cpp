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
ll dp[5001] = { 0 };
ll dpTmp[5001] = { 0 };
ll sumBelow(int a) {
    int i;
    ll ans = 0;
    myfor(i, a+1) {
        ans += dpTmp[i] % 998244353;
    }
    return ans;
}
ll sumUpper(int a, int N) {
    ll ans = 0;
    for (int i = a; i < N; i++) {
        ans += dpTmp[i] % 998244353;
    }
    return ans;
}


int main(void) {
    ll N, M ,K;
    cin >> N >> M >> K;
    int i;
    myfor(i, M) {
        dp[i + 1] = 1;
        dpTmp[i + 1] = 1;
    }

    for (int j = 1; j < N; j++) {
        myfor(i, M) {
            if (i+1 >= K) {
                dp[i+1] = (sumBelow(i+1 - K) + sumUpper(i+1 + K, M+1)) % 998244353;
            }
            else{
                if (i + 1 + K < M + 1) {
                    dp[i + 1] = sumUpper(i + 1 + K, M + 1);
                }
                else {
                    dp[i + 1] = 0;
                }
            }
        }
        myfor(i, M) {
            dpTmp[i + 1] = dp[i + 1];
        }                
    }
    ll ans = 0;
    myfor(i, M) {
        ans += dp[i + 1] % 998244353;
    }
    cout << ans % 998244353 << endl;
    return 0;
}

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
ll sumTable[5001] = { 0 };

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;
    ll MOD = 998244353LL;
    for (auto j = 1; j < M + 1; j++) {
        sumTable[j] = (1 + sumTable[j - 1]) % MOD;
    }
    for (auto _ = 0; _ < N-1; _++) {
        
        for (auto j = 1; j < M + 1; j++) {
            if (K != 0) {
                auto L = max(j - K, 0);
                auto R = min(M, j + K - 1);
                //sumTable[M]‚Ì‚Ù‚¤‚ª¬‚³‚¢‰Â”\«‚ª‚ ‚é‚½‚ßMOD‚ð‘«‚µ‚Ä‚¨‚­B
                dp[j] = (sumTable[M] + MOD - sumTable[R]  + sumTable[L])% MOD;
            }
            else {
                dp[j] = sumTable[M] % MOD;
            }
           
        }
        for (auto j = 1; j < M + 1; j++) {
            sumTable[j] = ((dp[j] % MOD) + (sumTable[j - 1] % MOD)) % MOD;
        }

    }
    cout << sumTable[M] << endl;
    return 0;
}

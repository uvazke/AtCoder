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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    return a / d * b;
}

ll summation(ll a) {
    return (a * (a + 1)) / 2LL;
}

int main(void) {
    ll N, A, B;
    cin >> N >> A >> B;
    auto lcmOfAB = lcm(A, B);
    auto NS = summation(N);
    auto AS = A*summation(N/A);
    auto BS = B*summation(N/B);
    auto CS = lcmOfAB *summation(N/lcmOfAB);
    auto ans = NS - (AS + BS - CS);
    cout << ans << endl;
    return 0;
}

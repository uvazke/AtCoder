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


int A[200000], cnt[1000001], isNotDivisible[1000001];
int main(void) {
    int N, i;
    cin >> N;
    myfor(i, N) {
        cin >> A[i];       
    }
    myfor(i, N) {
        cnt[A[i]]++;
    }
    for (i = 1; i < 1000001; i++) {
        isNotDivisible[i] = true;
    }

    for (i = 1; i < 1000001; i++) {
        if (cnt[i] > 0) {
            if (cnt[i] > 1) {
                isNotDivisible[i] = false;
            }
            for (auto x = i * 2; x < 1000001; x = x + i) {
                isNotDivisible[x] = false;
            }
        }
    }
    auto ans = 0;
    myfor(i, N) {
        ans += isNotDivisible[A[i]] ? 1 : 0;
    }
    cout << ans << endl;
    return 0;
}

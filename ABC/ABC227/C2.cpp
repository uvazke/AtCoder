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
    long N;
    cin >> N;
    long i,j,k,ans=0;
    for(i = 1; i*i*i <= N; i++) {
        for(j = i; i*j*j <= N; j++) {
            ans += N / (i * j) - j + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
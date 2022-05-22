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
    int N, a[200000],b[200000],K;
    cin >> N >> K;
    int i;
    myfor(i, N) { cin >> a[i]; }
    myfor(i, N) { cin >> b[i]; }

    myfor(i, N - 1) { 
        auto d1 = abs(a[i] - a[i+1]);
        auto d2 = abs(a[i] - b[i+1]);
        auto d3 = abs(b[i] - a[i+1]);
        auto d4 = abs(b[i] - b[i + 1]);
        if(d1 > K && d2 > K && d3 > K && d4 > K){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
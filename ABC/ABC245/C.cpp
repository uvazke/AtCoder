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

    bool nextAIsUsable = true, nextBIsUsable = true;

    myfor(i, N - 1) {
        int d1 = K + 1, d2 = K + 1, d3 = K + 1, d4 = K + 1;
        if(nextAIsUsable) {
            d1 = abs(a[i] - a[i + 1]);
            d2 = abs(a[i] - b[i + 1]);
        }
        if(nextBIsUsable){
            d3 = abs(b[i] - a[i + 1]);
            d4 = abs(b[i] - b[i + 1]);
        }
        
        nextAIsUsable = d1 <= K || d3 <= K;
        nextBIsUsable = d2 <= K || d4 <= K;
        


        if(d1 > K && d2 > K && d3 > K && d4 > K) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
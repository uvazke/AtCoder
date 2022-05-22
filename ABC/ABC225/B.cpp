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
    int N, a, b, aPrev = -1, bPrev = -1, i;
    cin >> N;
    myfor(i, N-1) { 
        cin >> a >> b;
        if(aPrev == -1){
            aPrev = a;
            bPrev = b;
            continue;
        }
        if(a == aPrev || a == bPrev || b == aPrev || b == bPrev){
            aPrev = a;
            bPrev = b;
            continue;
        }
        cout << "No" << endl;
        return 0;
    }
    cout <<"Yes" << endl;
    return 0;
}
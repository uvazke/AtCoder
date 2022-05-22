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
    int a, b, c, d;
    cin >> a >> b >> c >>d;
    if(a < c){
        cout << "Takahashi" << endl;
        return 0;
    } else if(a == c) {
        if(b <= d){
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
    return 0;
}
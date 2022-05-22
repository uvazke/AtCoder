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
    int N, a[2001];
    cin >> N;
    int i;
    myfor(i, 2001){ a[i] = 0; }
    myfor(i,N){
        int b;
        cin >> b;
        a[b]++;
    }
    myfor(i,2001){
        if(a[i] == 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}